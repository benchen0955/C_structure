#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p, n;
	int qsc; 
	//printf("請輸入人數:");
	scanf("%d", &n);
	//int ary[n];
	p = (int *)malloc(sizeof(int)*n);
	int i;
	//輸入 
	for(i=0;i<n;i++){
		//scanf("%d", &p[i]);
		scanf("%d", p+i);
	}	
	//尋找
	int found = 0;
	//printf("請輸入要找的數字:");
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
