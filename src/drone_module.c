/**
 * As per: http://www.tldp.org/LDP/lkmpg/2.6/lkmpg.pdf
 */
#include <linux/module.h>
#include <linux/kernel.h>

#include "messages.h"
#include "drone_device.h"

/**
 * Method used for initialising the kernel module, by creating the drone device.
 * 
 * TODO: Handle errors.
 */
int init_module(void)
{
	// Let the user know we are creating a drone device.
	printk(KERN_DEBUG DEBUG_MESSAGE_PRE_INIT_DEVICE);

	// Create drone device.
	create_drone_device(); // TODO: Handle result.

	// Let the user know this has been a success.
	printk(KERN_DEBUG DEBUG_MESSAGE_POST_INIT_DEVICE);

	// Notify the user the kernel module is loaded.
	printk(KERN_INFO INFO_MESSAGE_INIT);

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

/**
 * Method used for unloading the kernel module, by disposing the drone device.
 */
void cleanup_module(void)
{
	// Remove drone device.
	remove_drone_device();

	// Notify user.
	printk(KERN_DEBUG DEBUG_MESSAGE_DEVICE_REMOVED);
	printk(KERN_INFO INFO_MESSAGE_CLEANUP);
}
