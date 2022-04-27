
#include "hc32l110_system.h"
#include "ddl/utils/rng.h"
Rng::Rng() : Rng(0){}
Rng::Rng(uint32_t seed){
    this->counter = 1;
    this->x[0] = seed == 0? HC32_DEVICE_ID->parts.components.wafer : seed;
    this->x[1] = (HC32_DEVICE_ID->parts.components.xcoord << 24) +
                 (HC32_DEVICE_ID->parts.components.revid << 16) +
                 (HC32_DEVICE_ID->parts.components.wafer << 8) +
                 HC32_DEVICE_ID->parts.components.ycoord;
    this->x[2] = (CLOCK_TRIM_HIGH_24_mhz << 16) + CLOCK_TRIM_HIGH_22_12_mhz;
    this->x[3] = (CLOCK_TRIM_HIGH_16_mhz << 16) + CLOCK_TRIM_HIGH_8_mhz;
    this->x[4] = (CLOCK_TRIM_HIGH_4_mhz << 16) + CLOCK_TRIM_LOW_38_4_khz;
}
uint32_t Rng::next(){
        /* Algorithm "xorwow" from p. 5 of Marsaglia, "Xorshift RNGs" */
    uint32_t t = this->x[4];

    uint32_t s = this->x[0]; /* Perform a contrived 32-bit shift. */
    this->x[4] = this->x[3];
    this->x[3] = this->x[2];
    this->x[2] = this->x[1];
    this->x[1] = s;

    t ^= t >> 2;
    t ^= t << 1;
    t ^= s ^ (s << 4);
    this->x[0] = t;
    this->counter += 362437;
    return t + this->counter;
}