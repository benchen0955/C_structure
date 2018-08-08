#include<stdio.h>
#include<stdlib.h>

//int LinearSearch(int n, int *p, int value)
int LinearSearch(int n, char p[][128], char value[])//循序搜尋
{ 
    int i;
    for(i=0; i< n; i++)
    {
    	//比對 
    	printf("%d: %s\n", i,p[i]);
 //       if(p[i] == value) 
        if (strcmp(p[i],value)==0)
        {
            return i;  // 找到: 傳回資料位置
        }
    }
    return -1;  // 找不到: 回傳-1
}

//int BinarySearch(int n, int *p, int value) 
int BinarySearch(int n, char p[][128], char value[])//二元搜尋
{
    int low=0, high=n, mid;
    while(low <= high) 
    {
        mid = (low + high) / 2;
        //比對
        printf("%d: %s\n", mid,p[mid]);
//        if(p[mid] > value)      
        
        if (strcmp(p[mid],value)>0)        
            high = mid - 1;
//        else if(p[mid] < value)
        else if(strcmp(p[mid],value)<0)
            low = mid+1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    char data[10][128],value[128], key[128];
    int pos;
//	int ary[500], value, key, pos;
	int n=0;
	int op,i,j;
	
	while(1)
	{
		/*
		puts("1 insert");
		puts("2 search int by linear");
		puts("3 search int by binarry");
		puts("4 print all data");
		puts("5 exit");
		*/
		scanf("%d", &op);
		switch(op)
		{
			case 1:
//				scanf("%d", &value);
				scanf("%s", value);
				if(n==0){
//					ary[0] = value;
                    strcpy(data[0],value);
				}
				else{					
//					key=value;
					strcpy(key,value);
										
//			        for(j=n-1; j>=0 && ary[j]>key; j--)
			        for(j=n-1; j>=0 ; j--)       //排序
			        {
                        if (strcmp(key,data[j])>0)
                        {
                            break;                       
                        }
//                        ary[j+1] = ary[j]; 
                        strcpy(data[j+1],data[j]);
			        }
//			        ary[j+1] = key;  //將key插入
                    strcpy(data[j+1],key);
		        }
		        n++;
				break;
			case 2:
                 
//				scanf("%d", &value);
				scanf("%s", value);
//				pos = LinearSearch(n, ary, value);
				pos = LinearSearch(n, data, value);
				if(pos==-1){
					puts("not found");
				}
				else{
//                    printf("found %d\n", ary[pos]); 
					printf("found %s\n", data[pos]);
				}
				
				break;
			case 3:
                 
//				scanf("%d", &value);
				scanf("%s", value);
//				pos = BinarySearch(n, ary, value);
				pos = BinarySearch(n, data, value);
				if(pos==-1){
					puts("not found");
				}
				else{
//                    printf("found %d\n", ary[pos]); 
					printf("found %s\n", data[pos]);
				}
				
				break;
			case 4:
				for(i=0;i<n;i++){
//					printf("%s ", ary[i]);
					printf("%s ", data[i]);
				}
				puts("");
				break;
			case 5:
				return 0;
				break;
			
		}
		system("pause");
		system("cls");
	}

	return 0;
}





