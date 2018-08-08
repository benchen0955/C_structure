#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 6

//#include<stdio.h>
//#include<stdlib.h>

//#define N 6

//void swap(int *a, int *b)
void swap(char *a, char *b)
{
     /*
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;*/
    char temp[180];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
    
    
}
//void print(int n, int *p)
void print(int n, char p[][N])
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("%s ", p[i]);
    }
    printf("\n");
}
//void bsort(int *data, int n)
void bsort(char data[][N], int n)//��w�Ƨ�
{
    //int data[5] = {34,12,5,66,1};  // ���ƧǪ����
    int i, j; 
    //int n=5;

    for(i=n; i>1; i--) 
    {
        for(j=0; j<i-1; j++)
        {
            //if(data[j+1] > data[j])
            if(strcmp(data[j+1],data[j])>0) 
            {
               swap(data[j+1], data[j]);
            }
        }
        print(n, data);
    }
    //print(n, data);
    //return 0;
}

void ssort(char data[][N], int n)//��ܱƧ�
{
    //int data[5] = {34,12,5,66,1};  // ���ƧǪ����
    int i, j, pos;  // pos: �����ثe�̤p�Ȧ�m
    //int n=5;
    for(i=0; i<n-1; i++)
    {
        pos = i;
        for(j=i+1; j<n; j++) // ��X�̤p��
        {
//            if(data[j] > data[pos]) 
            if(strcmp(data[j] , data[pos])>0)
                pos = j; 
        }
        // ��̤p�ȸ�� i �Ӱ��洫
        swap(data[i], data[pos]);
        print(n, data);
    }
    //print(n, data);
    //return 0;
}

void isort(char data[][N], int n)//�ƤJ�Ƨ�
{
    //int data[5] = {34,12,5,66,1};  // ���ƧǪ����
    int i, j; 
    char key[180];  // �����n�Q���J����
    //int n=5;
    for( i=1; i<n; i++) 
    {
//        key=data[i];
        strcpy(key,data[i]);
//        for(j=i-1; j>=0 && data[j]<key; j--)
//        for(j=i-1; j>=0 && strcmp(key,data[j]); j--)
        for(j=i-1; j>=0 ; j--)
        {
//            data[j+1] = data[j];
            if (strcmp(key,data[j])<0)
            {
               break;                       
            }
            strcpy(data[j+1],data[j]);
        }
//        data[j+1] = key;  //�Nkey���J
        strcpy(data[j+1],key);
        print(n, data);
    }
    //print(n, data);
    //return 0;
}

int main()
{
	
	char ary[180][N];
	int i;
	int op;
	for(i=0;i<N;i++){
		scanf("%s", ary[i]);
	}
	
	scanf("%d", &op);
	switch(op){
		case 1:
			bsort(ary, N);
			break;
		case 2:
			ssort(ary, N);
			break;
		case 3:
			isort(ary, N);
			break;
	}
	
	print(N, ary);
	system("PAUSE");
	
	return 0;
}
