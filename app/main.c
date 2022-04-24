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

	read(fd, buff, 500);
	printf("Reading data from kernel: ");
	puts(buff);

	write(fd, "get_nama", 13);

	close(fd);
}