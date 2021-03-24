#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define INFILE "FIFO_ba"
#define OUTFILE "FIFO_ab"

#define INWORD "pong"
#define OUTWORD "ping"

#define STRCOUNT 4

int main (void) {

	int size;
	extern int errno;
	int errnum = errno;
	
	char * buff = (char *)malloc(5 * sizeof(char));
	char * tempBuff = "ping";
	
	printf("%d\n", mkfifo(INFILE, 0666));
	fprintf(stderr, "Error creating file: %s, %s\n", OUTFILE, strerror( errno ));
	
	/*if (mkfifo(INFILE, 0666) < 0) {
		
		fprintf(stderr, "Error creating file: %s, %s\n", INFILE, strerror( errnum ));
		printf("Output value from error was: %d\n", errno);
		//exit(0);
	}
	if (mkfifo(OUTFILE, 0666) < 0) {
		
		fprintf(stderr, "Error creating file: %s, %s\n", OUTFILE, strerror( errnum ));
		printf("Output value from error was: %d\n", errno);
		//exit(0);
	}*/
	
	//int fdOUT = open(OUTFILE, O_WRONLY | O_NONBLOCK);
	//int fdIN = open(INFILE, O_RDONLY | O_NONBLOCK);
	
	/*if (fdOUT < 0) {
		
		//printf("Error opening the %s file\n", OUTFILE);
		printf("%d", errnum);
		fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
		exit(0);
	}
	
	if (fdIN < 0) {
		
		//printf("Error opening the %s file\n", INFILE);
		printf("%d", errnum);
		fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
		exit(0);
		
	}
	
	write(fdOUT, tempBuff, STRCOUNT);
	
	while(1) {
		
		if((size = read(fdIN, buff, STRCOUNT)) > 0) {

		buff[STRCOUNT] = '\0';

		if (strcmp(buff, INWORD) == 0) {

			printf("%s\n", buff);
			write(fdOUT, OUTWORD, STRCOUNT);
		}
	}
	usleep(300000);
}*/

	return 0;

}


