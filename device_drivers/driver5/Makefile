obj-m:= driver5.o
KERNELVER= $(shell uname -r)

all:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) clean
