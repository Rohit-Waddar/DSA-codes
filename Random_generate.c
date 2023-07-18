#include<stdio.h>
int main()
{
int n,i,p,q;
double a[10000];
FILE *fp;
printf("Enter no of numbers to generate\n");
scanf("%d",&n);
printf("Enter Range P and Q\n");
scanf("%d%d",&p,&q);
fp=fopen("input.txt","w");
for(i=0;i<n;i++)
{
    a[i]=(rand()%(p-q+1))+p;
    a[i]=a[i]/2.875;

    fprintf(fp,"%f\t",a[i]);

}
fclose(fp);
}


