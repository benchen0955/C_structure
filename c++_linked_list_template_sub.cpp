#include <iostream>
#include <string>
//#include <conio.h>
#include <stdlib.h>
using namespace std;


template <class T>
class node
{
	public:
		T data;
 		node<T> *next;
};

template <class T>
class LinkedList
{
	public:
		LinkedList();
		void insert(T &value);
		void insertF(T &value);
		void remove(T &value);
		void find(T &value);
		void print();
		int length ();
	private:
		node<T> *getnode ();
		void freenode (node<T> *p) ;
		void insert_node (node<T> *ptr, T &value);
		void delete_node(node<T> *ptr);
		node<T> *find_node(T &num);
		

		node<T> *head;
		node<T> *tail;
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
}

template <class T>
node<T> *LinkedList<T>::getnode () /* ����Ʋ��ͤ@�ӷs�`�I */
{
	node<T> *p;
	p = new node<T>;
	if ( p == NULL)
	{
		cout << "�O���餣��" << endl;
		exit(1);
	}
	return(p);
}

template <class T>
void LinkedList<T>::freenode (node<T> *p) /* ����ƱN�`�I�ٵ��O���� */
{
	delete p;
}

template <class T>
void LinkedList<T>::insert_node ( node<T> *ptr, T &value)
{ 
	node<T> *new_node;            /* �s�`�I�����ܼ� */
	new_node = getnode();    /* �إ߷s�`�I,���o�@�ӥi�θ`�I */
	new_node->data = value; /* �إ߸`�I���e */
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
}

template <class T>
void LinkedList<T>::delete_node(node<T> *ptr)
{
	node<T> *previous; /* ���V�e�@�`�I */
	if ( ptr == head ) /* �O�_�O��C�}�l */
	/* �Ĥ@�ر��p: �R���Ĥ@�Ӹ`�I */
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while ( previous->next != ptr ) /* ��`�Iptr���e�`�I */
			previous = previous->next;
		if ( ptr->next == NULL ) /* �O�_�O��C���� */
		/* �ĤG�ر��p: �R���̫�@�Ӹ`�I */
			previous->next = NULL; /* �̫�@�Ӹ`�I */
		else
		/* �ĤT�ر��p: �R�������`�I */
			previous->next = ptr->next; /* ��(3)���B�J(1) */
	}
	freenode(ptr); /* ����ƱN�`�I�k�ٵ��O���� */
}
template <class T>
node<T> *LinkedList<T>::find_node(T &num)
{
	node<T> *ptr;
	ptr = head; /* ���V��C�_�l */
	while ( ptr != NULL ) /* ���X��C */
	{ 
		if ( ptr->data == num ) /* ��Mdata */
		return (ptr);
		ptr = ptr->next; /* ���V�U�@�`�I */
	} 
	return (ptr);
}
template <class T>
int LinkedList<T>::length () /* ����ƭp��`�I���쵲���� */
{
	int num=0;
	node<T> *q = head;
	while (q != NULL) 
	{
		num ++;
		q = q->next; 
	}
	return(num);
}

template <class T>
void LinkedList<T>::insert(T &value)
{
	if(head==NULL)
	{
		head = getnode();
		head->data=value;
		head->next=NULL;
		tail = head;
	}
	else
	{
		insert_node(tail, value);
		tail = tail->next;
	}
	//cout << "��ƴ��J���\!" <<  endl;
}

template <class T>
void LinkedList<T>::insertF(T &value)
{
	if(head==NULL)
	{
		head = getnode();
		head->data=value;
		head->next=NULL;
		tail = head;
	}
	else
	{
		insert_node(NULL, value);
	}
	//cout << "��ƴ��J�̫e���\!" <<  endl;
}



template <class T>
void LinkedList<T>::remove(T &value)
{
	node<T> *prev, *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		if(length()==1)
		{
			delete_node(ptr);
			tail = NULL;
		}
		else if(ptr->next==NULL)
		{
			prev = head;
			while(prev->next != ptr)
				prev = prev->next;
			delete_node(ptr);
			tail = prev;
		}
		else
		{
			delete_node(ptr);
		}
		cout << "Delete ok" <<  endl;
	}
	else
	{
		cout << "Not found" <<  endl;
	}
}

template <class T>
void LinkedList<T>::find(T &value)
{
	node<T> *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		cout << "found " <<  ptr->data << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
}

template <class T>
void LinkedList<T>::print()
{
	node<T> *q = head;
	while (q != NULL) 
	{
		cout << q->data << " ";
		q = q->next; 
	}
	cout << endl;
}

template <class T>
void tfunc(T a){
	LinkedList<T> list;
	T value;
	//char key;
	int key;
	while(1)
	{
		/*
		cout << "i: ���J" << endl;
		cout << "j: ���J�̫e" << endl;
		cout << "d: �R��" << endl;
		cout << "f: �M��" << endl;
		cout << "l: �C�L" << endl;
		cout << "e: ���}" << endl;
		cout << "> ";
		*/
		//key = getche();
		cin >> key;
		//cout << endl;
		switch(key)
		{
			case 1:
				//cout << "��J���J��Ƥ��e: ";
				cin >> value;
				list.insert(value);
				break;
			case 'j':
				cout << "��J���J��Ƥ��e: ";
				cin >> value;
				list.insertF(value);
				break;
			case 2:
				//cout << "��J�R����Ƥ��e: ";
				cin >> value;
				list.remove(value);
				break;
			case 3:
				//cout << "��J�M���Ƥ��e: ";
				cin >> value;
				list.find(value);
				break;
			case 6:
				list.print();
				break;
			case 4:
				//cout << "ByeBye!" << endl; 
				exit(0);
				break;
			case 5:
				cout << list.length() << endl;
				break;
			default:
				cout << "��J�ȿ��~!" << endl; 
		}
		//cout << endl; 
		
		system("pause");
		system("cls");
	}
}

int main()
{	
	int op;
	cin >> op;
	switch(op)
	{
		case 1:
			cout << "<Integer List>" << endl;
			tfunc(1);
			break;
		case 2:
			cout << "<Double List>" << endl;
			tfunc(1.1);
			break;
		case 3:
			cout << "<Char List>" << endl;
			tfunc('A');
			break;
		case 4:
			cout << "<String List>" << endl;
			string a;
			tfunc(a);
			break;
		
	}

	
	return 0;
}