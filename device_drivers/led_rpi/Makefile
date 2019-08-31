obj-m:= led_blink_rpi.o
KERNELVER=$(shell uname -r)

all:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) clean
