#include<stdio.h>
#include<stdlib.h>

int string_length(char str[]);

int main()
{
    FILE *fp1,*fp2;
    int k=0,l=0,i=0,m,q;
    char str[10][1000],temp[1000];
    fp1=fopen("line.txt","r");
    fp2=fopen("lgline.txt","w");
    if(fp1==NULL)
    {
        printf("File does not exist.\n");
        exit(0);
    }
    while(!feof(fp1))
    {
       fgets(str[i],1000,fp1);
       k=string_length(str[i]);
       if(l<k)
       {
           l=k;
           m=0;
           q=0;
           while(str[i][q]!='\0')
           {
               temp[m]=str[i][q];
               q++;
               m++;
           }
           temp[m]='\0';
       }
       fputs(str[i],fp2);
       puts(str[i]);
    }
    printf("\nThe longest line read is\n");
    puts(temp);
    fputs("\nThe longest line read is\n",fp2);
    fputs(temp,fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

int string_length(char str[])
{
    int k=0;
    while(str[k]!='\0')
    {
        k++;
    }
    return k;
}
