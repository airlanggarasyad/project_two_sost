#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <malloc.h>

#define DEVICE "/dev/airlangga"

int main()
{
	if (access(DEVICE, F_OK) == -1) {
			printf("Module %s not loaded\n", DEVICE);
			return 0;
	} else
			printf("Module %s loaded\n", DEVICE);

	fd = open(DEVICE, O_RDWR);

	write(fd, "Hello World", 13);

	read(fd, buff, 500);
	printf("Reading data from kernel: \t");
	puts(buff);

	close(fd);
}