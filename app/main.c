#include <stdio.h>

#define device "/dev/airlangga"

int main() {
	FILE *fp;
	char buffer[256];

	printf("Demo calling kernel module using character device driver\n");
	printf("Reading file %s...\n",device);

	fp = fopen(device,"r");

	if(fp == NULL) {
		printf("Can't open file %s\n",device);
		return 0;
	}

	char messageToSend[] = "get_nama";

	fwrite(messageToSend , 1 , sizeof(messageToSend), fp);
	fclose(fp);
	
	return 0;
}