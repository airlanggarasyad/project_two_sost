#include <stdio.h>

#define device "/dev/airlangga"

int main() {
	int ret;
	FILE *fp;
	char buffer[256];
	char stringToSend[256];

	printf("Demo calling kernel module using character device driver\n");
	printf("Reading file %s...\n", device);

	fp = fopen(device, "r");

	if(fp == NULL) {
		printf("Can't open file %s\n",device);
		return 0;
	}
	
	fread(buffer,sizeof(buffer),1,fp);
	printf("Respond from kernel: %s\n",buffer);

	printf("Type in a short string to send to the kernel module:\n");

	scanf("%s", stringToSend);                // Read in a string (with spaces)

	printf("Writing message to the device [%s].\n", stringToSend);

	ret = fwrite(stringToSend, 1, strlen(stringToSend), fp); // Send the string to the LKM

	if (ret < 0)
	{
		perror("Failed to write the message to the device.");
	}


	fclose(fp);
	return 0;
}
