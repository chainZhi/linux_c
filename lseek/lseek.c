/* lseek-02.c */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd=-1;
    ssize_t size=-1;
    off_t offset=-1;
    char buf1[]="01234567";
    char buf2[]="abcdefgh";
    char filename[]="hole.txt";
    int len=8;

    fd = open (filename,O_RDWR|O_CREAT,00700);

    if ( -1 == fd) {
	return -1;
    }

    size =write(fd,buf1,len);
    if(size!=len) {
	return -1;
    }

    offset = lseek(fd,32,SEEK_SET);
    if (-1==offset) {
	return -1;
    }

    size = write(fd,buf2,len);
    if(size !=len) {
	return -1;
    }

    close (fd);
    return 0;
}
