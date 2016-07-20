const int MAX_BUTTON_COUNT = 8; //Max number of buttons = 8, because button states are stored over one byte

unsigned char button_states = 0x00; //all-zeros byte
int button_count = 4; // Default value
int first_pin = 0; //Default value

void buttons_gpio_update_count(int new_count) {
	if (new_count > MAX_BUTTON_COUNT) {
		Serial.println("Maximum button count is 8");
		return;
	}
	button_count = new_count;
}

void buttons_gpio_set_first_pin(int pin_number) { //Assumes that contiguous pins will be used
	first_pin = pin_number;
}

void buttons_gpio_update_pin_states() {
	int i;
	for (i=0; i<button_count; i++) {
		digitalWrite(first_pin+i, ((button_states >> i) & 1) ? HIGH : LOW);
	}
}

void buttons_gpio_update_button_states(unsigned char new_button_states) {
	button_states = new_button_states;
	buttons_gpio_update_pin_states();
}

void buttons_gpio_pins_setup() {
	int i;
	for (i=0; i<button_count; i++) {
		pinMode(first_pin+i, OUTPUT);
		digitalWrite(first_pin+i, LOW);
	}
}