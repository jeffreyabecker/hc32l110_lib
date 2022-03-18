  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_direction_t P01 : 1;
    volatile gpio_direction_t P02 : 1;
    volatile gpio_direction_t P03 : 1;
  } stc_gpio_p0dir_field_t;

  typedef struct
  {
    volatile uint32_t P00 : 1;
    volatile uint32_t P01 : 1;
    volatile uint32_t P02 : 1;
    volatile uint32_t P03 : 1;
  } stc_gpio_p0in_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile uint32_t P01 : 1;
    volatile uint32_t P02 : 1;
    volatile uint32_t P03 : 1;
  } stc_gpio_p0out_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_analog_digital_t P01 : 1;
    volatile gpio_analog_digital_t P02 : 1;
    volatile gpio_analog_digital_t P03 : 1;
  } stc_gpio_p0ads_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_drive_capability_t P01 : 1;
    volatile gpio_drive_capability_t P02 : 1;
    volatile gpio_drive_capability_t P03 : 1;
  } stc_gpio_p0dr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_internal_pullup_t P01 : 1;
    volatile gpio_internal_pullup_t P02 : 1;
    volatile gpio_internal_pullup_t P03 : 1;
  } stc_gpio_p0pu_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_internal_pulldown_t P01 : 1;
    volatile gpio_internal_pulldown_t P02 : 1;
    volatile gpio_internal_pulldown_t P03 : 1;
  } stc_gpio_p0pd_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_mode_t P01 : 1;
    volatile gpio_mode_t P02 : 1;
    volatile gpio_mode_t P03 : 1;
  } stc_gpio_p0od_field_t;

  typedef struct
  {
    volatile gpio_interrupt_high_t P00 : 1;
    volatile gpio_interrupt_high_t P01 : 1;
    volatile gpio_interrupt_high_t P02 : 1;
    volatile gpio_interrupt_high_t P03 : 1;
  } stc_gpio_p0hie_field_t;

  typedef struct
  {
    volatile gpio_interrupt_low_t P00 : 1;
    volatile gpio_interrupt_low_t P01 : 1;
    volatile gpio_interrupt_low_t P02 : 1;
    volatile gpio_interrupt_low_t P03 : 1;
  } stc_gpio_p0lie_field_t;

  typedef struct
  {
    volatile gpio_interrupt_rising_t P00 : 1;
    volatile gpio_interrupt_rising_t P01 : 1;
    volatile gpio_interrupt_rising_t P02 : 1;
    volatile gpio_interrupt_rising_t P03 : 1;
  } stc_gpio_p0rie_field_t;

  typedef struct
  {
    volatile gpio_interrupt_falling_t P00 : 1;
    volatile gpio_interrupt_falling_t P01 : 1;
    volatile gpio_interrupt_falling_t P02 : 1;
    volatile gpio_interrupt_falling_t P03 : 1;
  } stc_gpio_p0fie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_direction_t P14 : 1;
    volatile gpio_direction_t P15 : 1;
  } stc_gpio_p1dir_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile uint32_t P14 : 1;
    volatile uint32_t P15 : 1;
  } stc_gpio_p1in_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile uint32_t P14 : 1;
    volatile uint32_t P15 : 1;
  } stc_gpio_p1out_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_analog_digital_t P14 : 1;
    volatile gpio_analog_digital_t P15 : 1;
  } stc_gpio_p1ads_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_drive_capability_t P14 : 1;
    volatile gpio_drive_capability_t P15 : 1;
  } stc_gpio_p1dr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_internal_pullup_t P14 : 1;
    volatile gpio_internal_pullup_t P15 : 1;
  } stc_gpio_p1pu_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_internal_pulldown_t P14 : 1;
    volatile gpio_internal_pulldown_t P15 : 1;
  } stc_gpio_p1pd_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_mode_t P14 : 1;
    volatile gpio_mode_t P15 : 1;
  } stc_gpio_p1od_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_interrupt_high_t P14 : 1;
    volatile gpio_interrupt_high_t P15 : 1;
  } stc_gpio_p1hie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_interrupt_low_t P14 : 1;
    volatile gpio_interrupt_low_t P15 : 1;
  } stc_gpio_p1lie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_interrupt_rising_t P14 : 1;
    volatile gpio_interrupt_rising_t P15 : 1;
  } stc_gpio_p1rie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile gpio_interrupt_falling_t P14 : 1;
    volatile gpio_interrupt_falling_t P15 : 1;
  } stc_gpio_p1fie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile uint32_t P23 : 1;
    volatile uint32_t P24 : 1;
    volatile uint32_t P25 : 1;
    volatile uint32_t P26 : 1;
    volatile uint32_t P27 : 1;
  } stc_gpio_p2dir_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile uint32_t P23 : 1;
    volatile uint32_t P24 : 1;
    volatile uint32_t P25 : 1;
    volatile uint32_t P26 : 1;
    volatile uint32_t P27 : 1;
  } stc_gpio_p2in_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile uint32_t P23 : 1;
    volatile uint32_t P24 : 1;
    volatile uint32_t P25 : 1;
    volatile uint32_t P26 : 1;
    volatile uint32_t P27 : 1;
  } stc_gpio_p2out_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile gpio_analog_digital_t P23 : 1;
    volatile gpio_analog_digital_t P24 : 1;
    volatile gpio_analog_digital_t P25 : 1;
    volatile gpio_analog_digital_t P26 : 1;
    volatile gpio_analog_digital_t P27 : 1;
  } stc_gpio_p2ads_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile gpio_drive_capability_t P23 : 1;
    volatile gpio_drive_capability_t P24 : 1;
    volatile gpio_drive_capability_t P25 : 1;
    volatile gpio_drive_capability_t P26 : 1;
    volatile gpio_drive_capability_t P27 : 1;
  } stc_gpio_p2dr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile gpio_internal_pullup_t P23 : 1;
    volatile gpio_internal_pullup_t P24 : 1;
    volatile gpio_internal_pullup_t P25 : 1;
    volatile gpio_internal_pullup_t P26 : 1;
    volatile gpio_internal_pullup_t P27 : 1;
  } stc_gpio_p2pu_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile gpio_internal_pulldown_t P23 : 1;
    volatile gpio_internal_pulldown_t P24 : 1;
    volatile gpio_internal_pulldown_t P25 : 1;
    volatile gpio_internal_pulldown_t P26 : 1;
    volatile gpio_internal_pulldown_t P27 : 1;
  } stc_gpio_p2pd_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile gpio_mode_t P23 : 1;
    volatile gpio_mode_t P24 : 1;
    volatile gpio_mode_t P25 : 1;
    volatile gpio_mode_t P26 : 1;
    volatile gpio_mode_t P27 : 1;
  } stc_gpio_p2od_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile gpio_interrupt_high_t P23 : 1;
    volatile gpio_interrupt_high_t P24 : 1;
    volatile gpio_interrupt_high_t P25 : 1;
    volatile gpio_interrupt_high_t P26 : 1;
    volatile gpio_interrupt_high_t P27 : 1;
  } stc_gpio_p2hie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile gpio_interrupt_low_t P23 : 1;
    volatile gpio_interrupt_low_t P24 : 1;
    volatile gpio_interrupt_low_t P25 : 1;
    volatile gpio_interrupt_low_t P26 : 1;
    volatile gpio_interrupt_low_t P27 : 1;
  } stc_gpio_p2lie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile gpio_interrupt_rising_t P23 : 1;
    volatile gpio_interrupt_rising_t P24 : 1;
    volatile gpio_interrupt_rising_t P25 : 1;
    volatile gpio_interrupt_rising_t P26 : 1;
    volatile gpio_interrupt_rising_t P27 : 1;
  } stc_gpio_p2rie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile gpio_interrupt_falling_t P23 : 1;
    volatile gpio_interrupt_falling_t P24 : 1;
    volatile gpio_interrupt_falling_t P25 : 1;
    volatile gpio_interrupt_falling_t P26 : 1;
    volatile gpio_interrupt_falling_t P27 : 1;
  } stc_gpio_p2fie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile uint32_t P31 : 1;
    volatile uint32_t P32 : 1;
    volatile uint32_t P33 : 1;
    volatile uint32_t P34 : 1;
    volatile uint32_t P35 : 1;
    volatile uint32_t P36 : 1;
  } stc_gpio_p3dir_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile uint32_t P31 : 1;
    volatile uint32_t P32 : 1;
    volatile uint32_t P33 : 1;
    volatile uint32_t P34 : 1;
    volatile uint32_t P35 : 1;
    volatile uint32_t P36 : 1;
  } stc_gpio_p3in_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile uint32_t P31 : 1;
    volatile uint32_t P32 : 1;
    volatile uint32_t P33 : 1;
    volatile uint32_t P34 : 1;
    volatile uint32_t P35 : 1;
    volatile uint32_t P36 : 1;
  } stc_gpio_p3out_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_analog_digital_t P31 : 1;
    volatile gpio_analog_digital_t P32 : 1;
    volatile gpio_analog_digital_t P33 : 1;
    volatile gpio_analog_digital_t P34 : 1;
    volatile gpio_analog_digital_t P35 : 1;
    volatile gpio_analog_digital_t P36 : 1;
  } stc_gpio_p3ads_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_drive_capability_t P31 : 1;
    volatile gpio_drive_capability_t P32 : 1;
    volatile gpio_drive_capability_t P33 : 1;
    volatile gpio_drive_capability_t P34 : 1;
    volatile gpio_drive_capability_t P35 : 1;
    volatile gpio_drive_capability_t P36 : 1;
  } stc_gpio_p3dr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_internal_pullup_t P31 : 1;
    volatile gpio_internal_pullup_t P32 : 1;
    volatile gpio_internal_pullup_t P33 : 1;
    volatile gpio_internal_pullup_t P34 : 1;
    volatile gpio_internal_pullup_t P35 : 1;
    volatile gpio_internal_pullup_t P36 : 1;
  } stc_gpio_p3pu_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_internal_pulldown_t P31 : 1;
    volatile gpio_internal_pulldown_t P32 : 1;
    volatile gpio_internal_pulldown_t P33 : 1;
    volatile gpio_internal_pulldown_t P34 : 1;
    volatile gpio_internal_pulldown_t P35 : 1;
    volatile gpio_internal_pulldown_t P36 : 1;
  } stc_gpio_p3pd_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_mode_t P31 : 1;
    volatile gpio_mode_t P32 : 1;
    volatile gpio_mode_t P33 : 1;
    volatile gpio_mode_t P34 : 1;
    volatile gpio_mode_t P35 : 1;
    volatile gpio_mode_t P36 : 1;
  } stc_gpio_p3od_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_interrupt_high_t P31 : 1;
    volatile gpio_interrupt_high_t P32 : 1;
    volatile gpio_interrupt_high_t P33 : 1;
    volatile gpio_interrupt_high_t P34 : 1;
    volatile gpio_interrupt_high_t P35 : 1;
    volatile gpio_interrupt_high_t P36 : 1;
  } stc_gpio_p3hie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_interrupt_low_t P31 : 1;
    volatile gpio_interrupt_low_t P32 : 1;
    volatile gpio_interrupt_low_t P33 : 1;
    volatile gpio_interrupt_low_t P34 : 1;
    volatile gpio_interrupt_low_t P35 : 1;
    volatile gpio_interrupt_low_t P36 : 1;
  } stc_gpio_p3lie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_interrupt_rising_t P31 : 1;
    volatile gpio_interrupt_rising_t P32 : 1;
    volatile gpio_interrupt_rising_t P33 : 1;
    volatile gpio_interrupt_rising_t P34 : 1;
    volatile gpio_interrupt_rising_t P35 : 1;
    volatile gpio_interrupt_rising_t P36 : 1;
  } stc_gpio_p3rie_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile gpio_interrupt_falling_t P31 : 1;
    volatile gpio_interrupt_falling_t P32 : 1;
    volatile gpio_interrupt_falling_t P33 : 1;
    volatile gpio_interrupt_falling_t P34 : 1;
    volatile gpio_interrupt_falling_t P35 : 1;
    volatile gpio_interrupt_falling_t P36 : 1;
  } stc_gpio_p3fie_field_t;

  typedef struct
  {
    volatile uint32_t P00 : 1;
    volatile uint32_t P01 : 1;
    volatile uint32_t P02 : 1;
    volatile uint32_t P03 : 1;
  } stc_gpio_p0stat_field_t;

  typedef struct
  {
    volatile uint32_t P00 : 1;
    volatile uint32_t P01 : 1;
    volatile uint32_t P02 : 1;
    volatile uint32_t P03 : 1;
  } stc_gpio_p0iclr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile uint32_t P14 : 1;
    volatile uint32_t P15 : 1;
  } stc_gpio_p1stat_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile uint32_t P14 : 1;
    volatile uint32_t P15 : 1;
  } stc_gpio_p1iclr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile uint32_t P23 : 1;
    volatile uint32_t P24 : 1;
    volatile uint32_t P25 : 1;
    volatile uint32_t P26 : 1;
    volatile uint32_t P27 : 1;
  } stc_gpio_p2stat_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 3;
    volatile uint32_t P23 : 1;
    volatile uint32_t P24 : 1;
    volatile uint32_t P25 : 1;
    volatile uint32_t P26 : 1;
    volatile uint32_t P27 : 1;
  } stc_gpio_p2iclr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile uint32_t P31 : 1;
    volatile uint32_t P32 : 1;
    volatile uint32_t P33 : 1;
    volatile uint32_t P34 : 1;
    volatile uint32_t P35 : 1;
    volatile uint32_t P36 : 1;
  } stc_gpio_p3stat_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile uint32_t P31 : 1;
    volatile uint32_t P32 : 1;
    volatile uint32_t P33 : 1;
    volatile uint32_t P34 : 1;
    volatile uint32_t P35 : 1;
    volatile uint32_t P36 : 1;
  } stc_gpio_p3iclr_field_t;