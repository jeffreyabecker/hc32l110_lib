#include "hc32l110_ddl_util.h"
#include "hc32l110_registers.h"

typedef struct
{
    uint32_t x[5];
    uint32_t counter;
} xorwow_state_t;
static xorwow_state_t state;
void srand(uint32_t seed)
{
    state.counter = 1;
    state.x[0] = seed == 0? HC32_DEVICE_ID->parts.components.wafer : seed;
    state.x[1] = (HC32_DEVICE_ID->parts.components.xcoord << 24) +
                 (HC32_DEVICE_ID->parts.components.revid << 16) +
                 (HC32_DEVICE_ID->parts.components.wafer << 8) +
                 HC32_DEVICE_ID->parts.components.ycoord;
    state.x[2] = (CLOCK_TRIM_HIGH_24_mhz << 16) + CLOCK_TRIM_HIGH_22_12_mhz;
    state.x[3] = (CLOCK_TRIM_HIGH_16_mhz << 16) + CLOCK_TRIM_HIGH_8_mhz;
    state.x[4] = (CLOCK_TRIM_HIGH_4_mhz << 16) + CLOCK_TRIM_LOW_38_4_khz;
}

uint32_t rand()
{
    /* Algorithm "xorwow" from p. 5 of Marsaglia, "Xorshift RNGs" */
    uint32_t t = state.x[4];

    uint32_t s = state.x[0]; /* Perform a contrived 32-bit shift. */
    state.x[4] = state.x[3];
    state.x[3] = state.x[2];
    state.x[2] = state.x[1];
    state.x[1] = s;

    t ^= t >> 2;
    t ^= t << 1;
    t ^= s ^ (s << 4);
    state.x[0] = t;
    state.counter += 362437;
    return t + state.counter;
}
