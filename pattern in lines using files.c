#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp1,*fp2;
    int k=0,l=0,i=0,m,q;
    char str[10][1000],temp[1000];
    fp1=fopen("par.txt","r");
    fp2=fopen("letdet.txt","w");
    if(fp1==NULL)
    {
        printf("File does not exist.\n");
        exit(0);
    }

    while(!feof(fp1))
    {
       fgets(str[i],1000,fp1);
       q=0;
       while(str[i][q]!='\0')
       {
           if(str[i][q]=='o'&&str[i][q+1]=='u'&&str[i][q+2]=='l'&&str[i][q+3]=='d')
           {
              puts(str[i]);
              fputs(str[i],fp2);
              l++;
           }
            q++;
       }
    }
    if(l==0)
    {
        printf("no line with ould pattern\n");
        fputs("no line with ould pattern\n",fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
