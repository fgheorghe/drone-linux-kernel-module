#include <stddef.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include "drone_commands.h"
#include "messages.h"
#include "drone_motor.h"

// Function prototypes.
int extract_device_id(const char *buff, size_t len);
int extract_command_id(const char *buff, size_t len);
int extract_command_parameter(const char *buff, size_t len);

// TODO: Implement.
// Format: id:command[:param]
// id: Drone component 'id' - 0 for drone, 1/2/3/4 - motor 1/2/3/4
// command: Device command - 0 - shutdown, 1 - power (requires param)
// param: Device command parameter - for power - 1 to 100, in %.
// TODO: Add more.
int handle_drone_command(const char *buff, size_t len) {
	int command_id = extract_command_id(buff, len);
	int device_id = extract_device_id(buff, len);
	int parameter;

	printk(KERN_DEBUG DEBUG_MESSAGE_DEVICE_ID, device_id);
	printk(KERN_DEBUG DEBUG_MESSAGE_COMMAND_ID, command_id);

	// Begin handling commands.
	switch (command_id) {
	    case 1:
	        parameter = extract_command_parameter(buff, len);
	        printk(KERN_DEBUG DEBUG_MESSAGE_COMMAND_PARAMETER, command_id);
	        if (device_id == 0) {
	            set_motor_power(1, parameter);
	            set_motor_power(2, parameter);
	            set_motor_power(3, parameter);
	            set_motor_power(4, parameter);
	        } else {
	            set_motor_power(device_id, parameter);
	        }
	        break;
	    case 0:
		    if (device_id == 0) {
			    set_motor_power_off(1);
			    set_motor_power_off(2);
			    set_motor_power_off(3);
			    set_motor_power_off(4);
		    } else {
			    set_motor_power_off(device_id);
		    }
		    break;
	}

	return 0;
}

int extract_device_id(const char *buff, size_t len) {
	int device_id = 0;
	int i = 0;
	int num;
        while (i < len && buff[i] != ':' && buff[i] != '\n' && buff[i] != '\0') {
		// TODO: Optimise.
		switch (buff[i]) {
			case '1':
				num = 1;
				break;
			case '2':
                                num = 2;
                                break;
			case '3':
                                num = 3;
                                break;
			case '4':
                                num = 4;
                                break;
			case '5':
                                num = 5;
                                break;
			case '6':
                                num = 6;
                                break;
			case '7':
                                num = 7;
                                break;
			case '8':
                                num = 8;
                                break;
			case '9':
				num = 9;
                                break;
			case '0':
                                num = 0;
				break;
			default:
				// Invalid device it.
				return -1;
				break;
		}
                device_id = device_id * 10 + num;
                i++;
        }
	return device_id;
}

int extract_command_parameter(const char *buff, size_t len) {
        int command_parameter = 0;
        int i = 0;
        int num;

	while (i < len && buff[i] != ':' && buff[i] != '\n' && buff[i] != '\0') {
		i++;
	}
	i++;
	while (i < len && buff[i] != ':' && buff[i] != '\n' && buff[i] != '\0') {
		i++;
	}
	i++;

        while (i < len && buff[i] != ':' && buff[i] != '\n' && buff[i] != '\0') {
                // TODO: Optimise.
                switch (buff[i]) {
                        case '1':
                                num = 1;
                                break;
                        case '2':
                                num = 2;
                                break;
                        case '3':
                                num = 3;
                                break;
                        case '4':
                                num = 4;
                                break;
                        case '5':
                                num = 5;
                                break;
                        case '6':
                                num = 6;
                                break;
                        case '7':
                                num = 7;
                                break;
                        case '8':
                                num = 8;
                                break;
                        case '9':
                                num = 9;
                                break;
                        case '0':
                                num = 0;
                                break;
                        default:
                                // Invalid command it.
                                return -1;
                                break;
                }
                command_parameter = command_parameter * 10 + num;
                i++;
        }
        return command_parameter;
}

int extract_command_id(const char *buff, size_t len) {
        int command_id = 0;
        int i = 0;
        int num;

	while (i < len && buff[i] != ':' && buff[i] != '\n' && buff[i] != '\0') {
		i++;
	}
	i++;

        while (i < len && buff[i] != ':' && buff[i] != '\n' && buff[i] != '\0') {
                // TODO: Optimise.
                switch (buff[i]) {
                        case '1':
                                num = 1;
                                break;
                        case '2':
                                num = 2;
                                break;
                        case '3':
                                num = 3;
                                break;
                        case '4':
                                num = 4;
                                break;
                        case '5':
                                num = 5;
                                break;
                        case '6':
                                num = 6;
                                break;
                        case '7':
                                num = 7;
                                break;
                        case '8':
                                num = 8;
                                break;
                        case '9':
                                num = 9;
                                break;
                        case '0':
                                num = 0;
                                break;
                        default:
                                // Invalid command it.
                                return -1;
                                break;
                }
                command_id = command_id * 10 + num;
                i++;
        }
        return command_id;
}
