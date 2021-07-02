/*   link list implementation  */

#include<iostream>
#include<conio.h>
using namespace std;

class Node{
	public:
		int Data;
		Node *Next;
	
		void insert(int x);
		void print();
		void delpos(int);
};
Node *Head;
main()
{
	Node list;
	Head = NULL;
	int size, number;
	cout<<"What is the size of list: ";
	cin>>size;
	for(int i = 1; i<=size; i++)
	{
		cout<<"\nEnter Number: ";
		cin>>number;
		list.insert(number);
		list.print();
	}
	list.delpos(1);
	list.print();
	getch();
}
void Node::insert(int x)
{
	Node *temp = new Node();
	temp->Data = x;
	temp->Next = Head;
	Head = temp;
}
void delpos(int pos)
{
	Node *ptr=Head;
	if(Head==NULL)
	{
		cout<<"list is empty"<<endl;
		return;
	}
	int ctr=0;
	while(ptr!=NULL)
	{
		ptr=ptr->Next;
		ctr++;
	}
	
	ptr=Head;
	if(pos==1)
	{
	Head=Head->Next;
	free(ptr);
	}
	else if(pos>1 && pos<ctr)
	{
		Node *preptr=ptr;
		for(int i=1;i<pos;i++)
		{
			preptr=ptr;
			ptr=ptr->Next;
		}
		preptr->Next=ptr->Next;
		free(ptr);
	}
	else if(pos==ctr)
	{
		Node *preptr;
		while(ptr->Next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->Next;
		}
		preptr->Next=NULL;
		free(ptr);
	}
	else
		cout<<"Postion out of range"<<endl;
}
void Node::print()
{
	Node *temp = Head;
	
	cout<<"List is: ";
	while(temp != NULL)
	{
		cout<<temp->Data<<" ";
		temp = temp->Next;
	}
}

