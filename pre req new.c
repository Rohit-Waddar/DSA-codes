
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void genr_num(int n1, int n2,int cnt)
{
	int i,a1[10];
	FILE *fp1, *fp2;
	fp1=fopen("input.txt","w");
	for (i = 0; i < cnt; i++)
    {
		int num = (rand() %(n2 - n1 + 1)) + n1;
		printf("%d ", num);
		a1[i]=num;
		printf("%d ",a1[i]);

		puts(a1[i]);
		fputs(num,fp1);
	}
}


int main()
{

	int n1 = 10, n2 = 50, cnt = 6;
	srand(time(0));
	genr_num(n1, n2, cnt);

	return 0;
}
