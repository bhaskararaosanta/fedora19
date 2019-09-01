obj-m:=char_driver.o
KERNELVER= $(shell uname -r)

#char_appl: char_appl.o
#	gcc -o char_appl char_appl.o

#char_appl.o: char_appl.c
#	gcc -o char_appl.o -c char_appl.c

all:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(KERNELVER)/build M=$(PWD) clean
