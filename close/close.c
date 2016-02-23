/* close-01.c */
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main (void)
{
    int fd=0;
    char filename[]="test.txt";
    int i=0;
    for(i=0;fd>=0;i++){
	fd = open(filename,O_RDONLY);
	if(fd>0) {
	    printf("fd:%d\n",fd);
	close(3);
	} else {
	    printf("error,can't open file\n");
	    exit(0);
	}
    }
}
