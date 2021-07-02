#include<iostream>
#include<conio.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
	
		void insert(int x);
		void print();
		void update(int,int);
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
	list.update(1,9);
	cout<<"\n Updated list is :";
	list.print();
	getch();
}
void Node::insert(int x)
{
	Node *temp = new Node();
	temp->data = x;
	temp->next = Head;
	Head = temp;
}
void Node::update(int pos,int x)
{
	if(Head==NULL)
	{
		cout<<"list is empty to do update"<<endl;
		return;
	}
	Node *ptr=Head;
	int ctr=0;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		ctr++;
	}
	if(pos>=1 && pos<=ctr)
	{
	ptr=Head;
	for(int i=1;i<pos;i++)
	{
	ptr=ptr->next;
	}
	ptr->data=x;
	}
	else
		cout<<"\n update position not in range";
}
void Node::print()
{
	Node *temp = Head;
	
	cout<<"List is: ";
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}


