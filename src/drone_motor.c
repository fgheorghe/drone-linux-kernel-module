#include <stddef.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include "drone_motor.h"
#include "messages.h"
#include "constants.h"
#include "drone_util.h"

int get_motor_pin(int motor_id) {
	int motor_pin = -1;
	switch (motor_id) {
		case 1:
			motor_pin = MOTOR_PIN_1;
			break;
		case 2:
			motor_pin = MOTOR_PIN_2;
			break;
		case 3:
			motor_pin = MOTOR_PIN_3;
			break;
		case 4:
			motor_pin = MOTOR_PIN_4;
			break;
	}
	return motor_pin;
}

void set_motor_power(int motor_id, int power_percentage) {
	int motor_pin = get_motor_pin(motor_id);
	int power_value = MOTOR_POWER_MIN + (MOTOR_POWER_MAX - MOTOR_POWER_MIN) * power_percentage / 100;

	pin_write(motor_pin, power_value);

	printk(KERN_DEBUG DEBUG_MESSAGE_MOTOR_POWER_SET, motor_id, power_percentage, power_value);
}

void set_motor_power_off(int motor_id) {
	int motor_pin = get_motor_pin(motor_id);
	pin_write(motor_pin, 0);
	printk(KERN_DEBUG DEBUG_MESSAGE_MOTOR_POWER_OFF, motor_id);
}