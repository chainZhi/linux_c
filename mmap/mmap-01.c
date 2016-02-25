/* mmap-01.c */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h> /*mmset warning*/
#include <stdio.h>
#define FILELENGTH 80

int main(void)
{
    int fd =-1;
    char buf[]="quick brown fox jumps over the dog";
    char *ptr =NULL;
    char filename[]="mmap.txt";

    fd = open(filename,O_RDWR|O_CREAT|O_EXCL,S_IRWXU);
    if(-1 == fd) {
	printf("Open file %s failure.\n",filename);
        return -1;
    }

    lseek(fd,FILELENGTH-1,SEEK_SET);
    write(fd,"a",1);

    ptr =(char*)mmap(NULL,FILELENGTH,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if((char*)-1 == ptr) {
	printf("mmap falure");
	close(fd);
	return -1;
    }

    memcpy(ptr+16,buf,strlen(buf));

    munmap(ptr,FILELENGTH);
    close(fd);

    return 0;
}
