#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>

#define DEVICE "/dev/airlangga"

int fd = 0;
int ppos = 0;

int read_device() {
	int read_length = 0;
	ssize_t ret;
	char *data = (char *)malloc(1024 * sizeof(char));

	read_length = 500;

	memset(data, 0, sizeof(data));
	
	data[0] = '\0';
	ret = read(fd, data, read_length);
	
	printf("DEVICE_READ : %s\n", data);
	
	if (ret == -1)
		printf("reading failed\n");
	else
		printf("reading success\n");
	
	free(data);
	return 0;
}

int main()
{
  	char buff[500];

	fd = open(DEVICE, O_RDWR);

	read(fd, buff, 500);
	printf("Reading data from kernel: ");
	puts(buff);

	write(fd, "get_nama", 13);
	read_device();

	close(fd);
}