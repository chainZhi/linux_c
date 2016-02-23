/* write.c */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
    int fd = -1;
    char buf[]="quick brown fox jumps over the lazy dog";
    ssize_t size;
    char filename[]="test.txt";

    fd = open(filename,O_RDWR);
    if(-1 == fd ) {
	printf("Open file %s failure,fd:%d\n",filename,fd);
    } else {
	printf("open file %s success,fd:%d\n",filename,fd);
    }

    size = write (fd,buf,strlen(buf));
    printf("write %d bytes to file %s\n",size,filename);
    close(fd);

    return 0;
}
