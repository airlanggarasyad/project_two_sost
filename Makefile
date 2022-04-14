obj-m += startstop.o
startstop-objs := start.o stop.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	rm *.o *.symvers *.order *.mod.c

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

insmod:
	sudo insmod ./startstop.ko

rmmod:
	sudo rmmod startstop

modinfo:
	modinfo startstop.ko

showmessage:
	cat /var/log/syslog


