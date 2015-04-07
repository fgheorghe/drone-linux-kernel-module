obj-m += drone.o
drone-objs += drone_device.o drone_module.o drone_commands.o drone_motor.o drone_util.o
all:
	make clean && make compile && make unload ; make load
compile:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
load:
	insmod ./drone.ko
unload:
	rmmod drone
