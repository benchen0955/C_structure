#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node *getnode () /* ����Ʋ��ͤ@�ӷs�`�I */
{
	node *p;
	p = (node *) malloc(sizeof(node));
	  /* malloc �|�ʺA�a�t�m�j�p��sizeof ���O����*/
	  /* sizeof �|�Ǧ^�@�ӫ��A��node����*/
	if ( p == NULL)
	{
		printf ("�O���餣��");
		exit(1);
	}
	return(p);
}

void freenode (node *p) /* ����ƱN�`�I�ٵ��O���� */
{
	free(p);
}

node *insert_node (node *head, node *ptr, node data)
{ 
	node *new_node;            /* �s�`�I�����ܼ� */
	new_node = getnode();    /* �إ߷s�`�I,���o�@�ӥi�θ`�I */
	*new_node = data;          /* �إ߸`�I���e */
	new_node->next = NULL; /* �]�w���Ъ�� */
	
	if ( ptr == NULL ) /* ����ptr�O�_�ONULL */
	{
		/* �Ĥ@�ر��p: ���J�Ĥ@�Ӹ`�I */
		new_node->next = head; /* �s�`�I������C�}�l */
		head = new_node;
	}
	else
	{
		if ( ptr->next == NULL ) /* �O�_�O��C���� */
			/* �ĤG�ر��p: ���J�̫�@�Ӹ`�I */
			ptr->next = new_node; /* �̫���V�s�`�I */
		else
		{
			/* �ĤT�ر��p: ���J���������`�I */
			new_node->next = ptr->next; /* (3) �s�`�I���V�U�@�`�I (3)*/
			ptr->next = new_node; /* �`�Iptr���V�s�`�I (4)*/
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
		puts("i �[�J�̫�");
		puts("l �C�X�Ҧ����");
		
		scanf(" %c", &key);
		switch(key)
		{
			case 'i':
				printf("�п�J�n�[�J���ȡG");
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
				//�L�X��
				ptr = head;
				while(ptr!=NULL){
					printf("%d ", ptr->data);
					ptr = ptr->next;
				} 
				puts("");//����
				break;			
		}
		system("pause");
		system("cls");
	}
	
	return 0;
}





