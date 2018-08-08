#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node *getnode () /* 此函數產生一個新節點 */
{
	node *p;
	p = (node *) malloc(sizeof(node));
	  /* malloc 會動態地配置大小為sizeof 的記憶體*/
	  /* sizeof 會傳回一個型態為node之值*/
	if ( p == NULL)
	{
		printf ("記憶體不足");
		exit(1);
	}
	return(p);
}

void freenode (node *p) /* 此函數將節點還給記憶體 */
{
	free(p);
}

node *insert_node (node *head, node *ptr, node data)
{ 
	node *new_node;            /* 新節點指標變數 */
	new_node = getnode();    /* 建立新節點,取得一個可用節點 */
	*new_node = data;          /* 建立節點內容 */
	new_node->next = NULL; /* 設定指標初值 */
	
	if ( ptr == NULL ) /* 指標ptr是否是NULL */
	{
		/* 第一種情況: 插入第一個節點 */
		new_node->next = head; /* 新節點成為串列開始 */
		head = new_node;
	}
	else
	{
		if ( ptr->next == NULL ) /* 是否是串列結束 */
			/* 第二種情況: 插入最後一個節點 */
			ptr->next = new_node; /* 最後指向新節點 */
		else
		{
			/* 第三種情況: 插入成為中間節點 */
			new_node->next = ptr->next; /* (3) 新節點指向下一節點 (3)*/
			ptr->next = new_node; /* 節點ptr指向新節點 (4)*/
		}
	}
	return (head);
}



int main()
{
	node *head, *ptr;
	head = ptr = NULL;
	int value;
	char key;
	node input;
	
	while(1){
		puts("i 加入最後");
		puts("l 列出所有資料");
		
		scanf(" %c", &key);
		switch(key)
		{
			case 'i':
				printf("請輸入要加入的值：");
				scanf("%d", &input.data);
				
				if(head == NULL){
					head = insert_node (head, NULL, input);
				}
				else {
					ptr = head;
					while(ptr->next != NULL)
						ptr = ptr->next;
					head = insert_node (head, ptr, input);
				}
				break;
			case 'l':
				//印出來
				ptr = head;
				while(ptr!=NULL){
					printf("%d ", ptr->data);
					ptr = ptr->next;
				} 
				puts("");//換行
				break;			
		}
		system("pause");
		system("cls");
	}
	
	return 0;
}





