// http://www.linuxjournal.com/article/8110?page=0,1
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>

#include "drone_util.h"
#include "constants.h"
#include "messages.h"

int pin_write(int motor_pin, int power_value) {
	int len = 4 + (power_value < 10 ? 1 : power_value < 100 ? 2 : 3);
	char buffer[len]; // TODO: Ensure no more than this length is written!
	struct file *fp;
	mm_segment_t fs;
	loff_t pos;

	snprintf(buffer, len, "%d=%d\n", motor_pin, power_value);

	fp = filp_open(SERVOBLASTER_DEVICE_PATH, O_WRONLY | O_APPEND, 0644);
	if (IS_ERR(fp)) {
		printk(KERN_ERR ERROR_MESSAGE_CANNOT_OPEN_SERVOBLATER_DEVICE);
		return -1;
	}

	fs = get_fs();
	set_fs(KERNEL_DS);
	pos = 0;
	vfs_write(fp, buffer, strlen(buffer), &pos);
	pos = 0;
	filp_close(fp, NULL);
	set_fs(fs);
	return 0;
}