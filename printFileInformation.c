#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
    char fileName[256];
    struct stat filestat;
    int ret;

    if(argc==2)
    {
        strcpy(fileName,argv[1]);
    }
    else
    {
        printf("Incorrect number of arguments \n");
        return 0;
    }

    ret = stat(fileName,&filestat);

    if(ret==-1)
    {
        printf("%s file information could not be found \n",fileName);
    }
    else
    {
        printf("\n %s File Inode number : %ld\n",fileName,filestat.st_ino);
    }


    return 0;
}

