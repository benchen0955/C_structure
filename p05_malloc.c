#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p, n;
	int qsc; 
	//printf("�п�J�H��:");
	scanf("%d", &n);
	//int ary[n];
	p = (int *)malloc(sizeof(int)*n);
	int i;
	//��J 
	for(i=0;i<n;i++){
		//scanf("%d", &p[i]);
		scanf("%d", p+i);
	}	
	//�M��
	int found = 0;
	//printf("�п�J�n�䪺�Ʀr:");
	scanf("%d", &qsc);
	for(i=0;i<n;i++){
		if(qsc == p[i]){
			printf("found %d\n", p[i]);
			found = 1;
			break;
		}		
	}
	if(found==0){
		puts("not found");
	}	
	free(p);
	
	return 0;
}
