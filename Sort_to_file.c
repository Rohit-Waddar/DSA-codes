#include<stdio.h>
#include<time.h>
int main()
{
    clock_t t;
    int b[10000],n=0;
    FILE *fp;
    t=clock();
    fp=fopen("input.txt","r");
    while(!feof(fp))
{
    fscanf(fp,"%d\n",&b[n]);
    n++;
}
fclose(fp);
bubble(b,n);
fp=fopen("output.txt","w");
fprintf(fp,"BUBBLE SORT:\n");
for(int i=0;i<n;i++)
{
    fprintf(fp,"%d\t",b[i]);
}
fprintf(fp,"\n");
fclose(fp);
t=clock()-t;
double time=((double)t)/CLOCKS_PER_SEC;
printf("This took %f seconds to execute \n",time);
fp=fopen("logs.txt","w");
fprintf(fp,"BUBBLE SORT : %f\t",time);
fprintf(fp,"\n");
fclose(fp);
}

void bubble(int b[10000],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(b[j]>b[j+1])
                {
                    int temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
        }
    }
}
