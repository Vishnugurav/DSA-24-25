#include<stdio.h>

int main(){
    FILE *fp;
    char ch;
    fp=fopen("C:/Users/Vishnu/Desktop/dummy/polytxt","w");
    printf("Keep typing characters. Type q to terminate\n");
    scanf(" %c",&ch);
    while(ch!='q')
    {
        fputc(ch,fp);
    }
    fclose(fp);
    return 0;
}