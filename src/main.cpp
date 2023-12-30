/* 
  Configuração do RTC Watchdog                                 28.12.2023
  por R&M Company

  Retorna => rst:0x10 (RTCWDT_RTC_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
             se digitar algo na serial trava, em 9 segundos reseta
*/

#include "Arduino.h"
#include "soc/rtc_wdt.h"

int i=0;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Rodando o setup...");
    // configuração do watchdog
    rtc_wdt_protect_off();                  //Disable RTC WDT write protection
    //Set stage 0 to trigger a system reset after 1000ms
    rtc_wdt_set_stage(RTC_WDT_STAGE0, RTC_WDT_STAGE_ACTION_RESET_RTC);
    rtc_wdt_set_time(RTC_WDT_STAGE0, 9000);
    rtc_wdt_enable();                       //Start the RTC WDT timer
    rtc_wdt_protect_on();                   //Enable RTC WDT write protection
    Serial.println("Configuração do watchdog concluída!");
}

void loop(){
  rtc_wdt_feed();                           // zera o timer do watchdog

   if (Serial.available()){
        i = 9;
        while(1){
         Serial.print("Watchdog vai atuar em... ");
         Serial.println (i);
         delay(1000);
         i = i - 1;
         }
      }
      
   Serial.println(i);
   delay(1000);
   i = i+1;
}