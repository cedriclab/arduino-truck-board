const uint8_t MAX_BUTTON_COUNT = 8; //Max number of buttons = 8, because button states are stored over one byte

uint8_t button_states = 0x00; //all-zeros byte
uint8_t button_count = 4; // Default value
uint8_t first_pin = 0; //Default value

void buttons_gpio_update_count(uint8_t new_count) {
	if (new_count > MAX_BUTTON_COUNT) {
		Serial.println("Maximum button count is 8");
		return;
	}
	button_count = new_count;
}

void buttons_gpio_set_first_pin(uint8_t pin_number) { //Assumes that contiguous pins will be used
	first_pin = pin_number;
}

void buttons_gpio_update_pin_states() {
	uint8_t i;
	for (i=0; i<button_count; i++) {
		digitalWrite(first_pin+i, ((button_states >> i) & 1) ? HIGH : LOW);
	}
}

uint8_t buttons_gpio_get_button_states() {
	return button_states;
}

void buttons_gpio_update_button_states(uint8_t new_button_states) {
	button_states = new_button_states;
	buttons_gpio_update_pin_states();
}

void buttons_gpio_pins_setup() {
	uint8_t i;
	for (i=0; i<button_count; i++) {
		pinMode(first_pin+i, OUTPUT);
		digitalWrite(first_pin+i, LOW);
	}
}
