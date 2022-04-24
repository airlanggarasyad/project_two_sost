#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <malloc.h>

#define DEVICE "/dev/airlangga"

int main()
{
	int fd;
  	char buff[500];

	fd = open(DEVICE, O_RDWR);

	write(fd, "Hello World", 13);

	read(fd, buff, 500);
	printf("Reading data from kernel: \t");
	puts(buff);

	close(fd);
}