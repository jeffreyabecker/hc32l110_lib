#define DDL_USE_CORE 1
#define DDL_USE_GPIO 1
#include "hc32l110.h"


int main(){

    core_system_clock_config(default_system_config);
    while(1){
        __WFI();
    }
}