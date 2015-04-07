/**
 * As per: http://www.linuxdevcenter.com/pub/a/linux/2007/07/05/devhelloworld-a-simple-introduction-to-device-drivers-under-linux.html?page=2
 */
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/uaccess.h>

#include "drone_device.h"
#include "drone_commands.h"
#include "constants.h"
#include "messages.h"

// Define prototype for use when defining device operations.
static ssize_t drone_device_write(struct file *filp, const char *buff, size_t len, loff_t *off);

// Drone device operations, as per: http://www.tldp.org/LDP/lkmpg/2.4/html/c577.htm
static const struct file_operations drone_device_file_operations = {
	.owner	= THIS_MODULE,
	.write	= drone_device_write,
};

// Configure device.
static struct miscdevice drone_device = {
	MISC_DYNAMIC_MINOR,
	DEVICE_NAME,
	&drone_device_file_operations
};

/**
 * Method used for creating the drone device at the defined path (DEVICE_PATH).
 */
int create_drone_device(void) {
	int result;

	// Create this device.
	result = misc_register(&drone_device);

	return result;
}

/**
 * Method used for removing the drone device.
 */
void remove_drone_device(void) {
	misc_deregister(&drone_device);
}

/**
 * Method called when write operations are done against the device.
 */
static ssize_t drone_device_write(struct file *filp, const char *buff, size_t len, loff_t *off) {
	// Log number of characters.
        printk(KERN_DEBUG DEBUG_MESSAGE_DEVICE_INPUT_CHARACTER_COUNT, (int) len);

	// Handle drone command.
	handle_drone_command(buff, len);

	// TODO: Return negative on failure.
	return len;
}
