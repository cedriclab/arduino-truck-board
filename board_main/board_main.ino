#include "buttons_gpio.h"

void setup(){
  Serial.begin(9600);
  //buttons_gpio_update_count(4);
  //buttons_gpio_set_first_pin(0);
  buttons_gpio_pins_setup();
}

void loop() {
  
}

