/* open-02.c O_CREATE O_EXCL*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = -1;
    char filename[] ="test2.txt";

    fd =open(filename,O_RDWR|O_CREAT|O_EXCL,00700);
    if(-1 == fd) {
	printf("File %s is exist,reopen it",filename);
	fd =open (filename,O_RDWR);
	printf("fd:%d",fd);
    } else {
	printf("File %s open success,fd:%d\n",filename,fd);
    }
    return 0;
}

