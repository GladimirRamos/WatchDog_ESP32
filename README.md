Ativa o WatchDog RTC no ESP32

* quando digitar algo na serial não zera o timer do watchdog -> rtc_wdt_feed(); 

Watchdog vai atuar em... 3
Watchdog vai atuar em... 2
Watchdog vai atuar em... 1
ets Jun  8 2016 00:22:57

rst:0x10 (RTCWDT_RTC_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:1184
load:0x40078000,len:13232
load:0x40080400,len:3028
entry 0x400805e4

Rodando o setup...
Configuração do watchdog concluída!
0
1
2
3
