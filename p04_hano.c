#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hanoi (int n, char from, char mid, char to, int *ct)
{   // �b�h�ʲ�n�Ӷ�L��
    if(n==0)
        return ;
    // ���N��n-1�Ӷ�L�h�졨������
    hanoi(n-1,from, to, mid, ct);
    // �N�ۤv�h�졨�ؼж�
    printf("plate %d from %c -> %c\n",n,from,to);
    ct[n-1]++;
    // �A�N��n-1�Ӷ�L�q�������𡨷h�^��
    hanoi(n-1,mid, from, to, ct);
}
//���^ �e����,�O�¨t��

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





