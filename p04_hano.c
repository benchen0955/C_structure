#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hanoi (int n, char from, char mid, char to, int *ct)
{   // 在搬動第n個圓盤時
    if(n==0)
        return ;
    // 先將第n-1個圓盤搬到”中間塔”
    hanoi(n-1,from, to, mid, ct);
    // 將自己搬到”目標塔”
    printf("plate %d from %c -> %c\n",n,from,to);
    ct[n-1]++;
    // 再將第n-1個圓盤從”中間塔”搬回來
    hanoi(n-1,mid, from, to, ct);
}
//遞回 河內塔,費氐系數

int main()
{
	int n,i;
	scanf("%d", &n);
	int *ary = (int *)malloc(sizeof(int)*n);
	memset(ary, 0, sizeof(int)*n);
	
	hanoi (n, 'A', 'B', 'C', ary);
	
	puts("");
	for(i=0;i<n;i++){
		printf("plate %d = %d\n", i+1, ary[i]);
	}
	
	free(ary);
	system("pause");
	
	return 0;
}





