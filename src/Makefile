obj-m := switch.o
all:
	make -C /lib/modules/5.4.51-v7+/build M=$(shell pwd) modules
clean:
	make -C /lib/modules/5.4.51-v7+/build M=$(shell pwd) clean
