#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

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