#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define INFILE "FIFO_ab"
#define OUTFILE "FIFO_ba"

#define INWORD "ping"
#define OUTWORD "pong"

#define STRCOUNT 4

int main (void) {

	int size;
	
	char * buff = (char *)malloc(5 * sizeof(char));
	
	mkfifo(INFILE, 0666);
	mkfifo(OUTFILE, 0666);
	
	int fdOUT = open(OUTFILE, O_WRONLY);
	int fdIN = open(INFILE, O_RDONLY);
	
	if (fdOUT < 0) {
		
		printf("Error opening the %s file\n", OUTFILE);
		exit(0);
	}
	
	while(1) {
		
		if((size = read(fdIN, buff, STRCOUNT)) > 0) {

		buff[STRCOUNT] = '\0';

		if (strcmp(buff, INWORD) == 0) {

			printf("%s\n", buff);
			write(fdOUT, OUTWORD, STRCOUNT);
		}
	}
	usleep(300000);
}

	return 0;

}



