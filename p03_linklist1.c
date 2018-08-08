#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};
typedef struct node node;

int main()
{
	node *head, *ptr;
	head = (node *)malloc(sizeof(node));
	ptr = head;
	int value,i;
	
	for(i=0;i<5;i++){
		scanf("%d", &value);
		ptr->data = value;
		
		if(i<4){
			ptr->next = (node *)malloc(sizeof(node));
			ptr = ptr -> next;
		}
		else{
			ptr->next = NULL;
		}
	}
	
	//¦L¥X 
	ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	return 0;
}
