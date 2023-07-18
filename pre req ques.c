
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void genr_num(int n1, int n2,int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
    {
		int num = (rand() %(n2 - n1 + 1)) + n1;
		printf("%d ", num);
	}
}


int main()
{
	int n1 = 5, n2 = 7, cnt = 3;
	srand(time(0));
	genr_num(n1, n2, cnt);

	return 0;
}
