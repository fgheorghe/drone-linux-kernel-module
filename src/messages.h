#ifndef MESSAGES
#define MESSAGES

#define INFO_MESSAGE_INIT "Drone kernel module initialised.\n"
#define INFO_MESSAGE_CLEANUP "Drone module unloaded.\n"
#define DEBUG_MESSAGE_PRE_INIT_DEVICE "Creating drone device.\n"
#define DEBUG_MESSAGE_POST_INIT_DEVICE "Drone device created.\n"
#define DEBUG_MESSAGE_DEVICE_REMOVED "Drone device removed.\n"
#define DEBUG_MESSAGE_DEVICE_INPUT_CHARACTER_COUNT "Drone device received %d characters.\n"
#define DEBUG_MESSAGE_DEVICE_ID "Drone device id: %d\n"
#define DEBUG_MESSAGE_COMMAND_ID "Drone command id: %d\n"
#define DEBUG_MESSAGE_COMMAND_PARAMETER "Drone command parameter: %d\n"
#define DEBUG_MESSAGE_MOTOR_POWER_SET "Drone motor %d power set to %d%% (%d)\n"
#define ERROR_MESSAGE_CANNOT_OPEN_SERVOBLATER_DEVICE "Drone can not access servoblaster device.\n"
#define DEBUG_MESSAGE_MOTOR_POWER_OFF "Drone motor %d off.\n"

#endif
