#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define DEVICE "/dev/airlangga"

int main() {
	int ret, debug = 1, fd = 0, ppos = 0;
	char buffer[256];
	char stringToSend[256];

	printf("Demo calling kernel module using character device driver\n");
	printf("Reading file %s...\n", DEVICE);

	fd = open(DEVICE, O_RDWR);

	int write_length = 0;
	ssize_t ret;
	char *data = (char *)malloc(1024 * sizeof(char));

	printf("Please enter the data to write into device\n");
	scanf(" %[^\n]", data); /* a space added after"so that it reads white space,
							%[^\n] is   addeed so that it takes input until new line*/

	write_length = strlen(data);
	
	if (debug)
			printf("the length of dat written = %d\n", write_length);

	ret = write(fd, data, write_length, &ppos);
	
	if (ret == -1)
			printf("writting failed\n");
	else
			printf("writting success\n");
	if (debug)fflush(stdout); /*not to miss any log*/
	free(data);
	
	close(fd);
	return 0;
}
