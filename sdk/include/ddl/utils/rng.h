#ifndef __DDL_UTILS_RNG_H__
#define __DDL_UTILS_RNG_H__
#include <cstdint>
class Rng{
    private:
        uint32_t x[5];
        uint32_t counter;
    public:
    Rng();
    Rng(uint32_t seed);
    uint32_t next();
};
#endif
