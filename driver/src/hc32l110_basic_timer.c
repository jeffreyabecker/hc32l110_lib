
#include "hc32l110_core.h"
#include "hc32l110_system.h"
#include "hc32l110_basic_timers.h"


__INLINE stc_basic_timer_cr_field_t* _basic_timer_get_cr(void* timer){
    return ((uint32_t)timer) == LPTIMER_ADDRESS? ((M0P_LPTIMER_TypeDef*)timer)->CR_f : ((M0P_BasicTimer_TypeDef *)timer)->CR_f;
}


    // __IO uint32_t ARR;
    // __IO uint32_t CNT;
    // __IO uint32_t CNT32;
    // union
    // {
    //   __IO uint32_t CR;
    //   stc_basic_timer_cr_field_t CR_f;
    // };
    // __IO uint32_t IFR;
    // __IO uint32_t ICLR;