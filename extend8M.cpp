#include <stdio.h>
#include <stdlib.h>

int main()
{
    char pad = 0;
    unsigned int curpos, length;
    unsigned int totalCount = 8192*1024;
    unsigned int writeCount = 0;

    FILE* fp;
    fp=fopen("boot.img-Tom","r");

    if(fp==0) {
        puts("error");
        exit(0);
    }
    curpos = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    length = ftell(fp);
    printf("The original length of the file is %d\n", length);
    fclose(fp);

    fp=fopen("boot.img-Tom","ab+");

    if(fp==0) {
        puts("error");
        exit(0);
    }


    for(int i=0;i<(totalCount-length);i++)
        fwrite(&pad,sizeof(char),1,fp);
    fclose(fp);

    return 0;
}
