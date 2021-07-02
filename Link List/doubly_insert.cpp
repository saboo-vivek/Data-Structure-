/*   Double link list implementation--->INSERTION   */
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
class Node
{
	public:
	int data;
	Node *pre;
	Node *next;
	
	void insert_beg(int);
	void insert_end(int);
	void insert_at(int,int);
	void print();
  void print(int);
};
Node *Head;
int main()
{
	Node list;
	Head=NULL;
	int size, number;
	cout<<"What is the size of list: ";
	cin>>size;
	for(int i = 1; i<=size; i++)
	{
		cout<<"Enter Number: "<<endl;
		cin>>number;
		list.insert_end(number);
		
	}
	list.print();
	list.insert_at(3,13);
	list.print();
  list.print(4);
	return 0;
}
void Node::insert_beg(int x)
{
	Node *new_node=new Node();
	new_node->data=x;
	new_node->pre=NULL;
	new_node->next=Head;
	if(Head!=NULL)
		Head->pre=new_node;
	Head=new_node;
}
void Node::insert_end(int x)
{
	Node *new_node=new Node();
	new_node->data=x;
	new_node->next=NULL;
	if(Head==NULL)
	{
		new_node->pre=Head;
		Head=new_node;
		return;
	}
	Node *ptr=Head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->pre=ptr;
}
void Node::insert_at(int pos,int x)
{
  cout<<"\n NEW ELEMENT INSERTED"<<endl;
	Node list;
	if(pos==1)
	{
		list.insert_beg(x);
		return;
	}
	Node *ptr=Head;
	int ctr=0;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		ctr++;
	}
	if(pos==ctr)
	{
		list.insert_end(x);
		return;
	}
	if(pos>1 && pos<ctr)
	{
		Node *new_node=new Node();
		new_node->data=x;
		Node *preptr,*nextptr;
		ptr=Head;
		for(int i=1;i<pos;i++)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=new_node;
		new_node->pre=preptr;
		new_node->next=ptr;
		ptr->pre=new_node;
	}
	else
		cout<<"\n position out of range"<<endl;
}
		
void Node::print()
{
	if(Head==NULL)
	{
		cout<<"\n List is empty";
		return;
	}
	Node *ptr=Head;
	Node *ptr1;
	cout<<"\n";
	cout<<"\n Traverse in forward direction: ";
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"  ";
		ptr1=ptr;
		ptr=ptr->next;
	}
	cout<<"\n";
	cout<<"\n Traverse in reverse direction: ";
	while(ptr1!=NULL)
	{
		cout<<ptr1->data<<"  ";
		ptr1=ptr1->pre;
	}
}
void Node::print(int pos)
{
	if(Head==NULL)
	{
		cout<<"\n List is empty";
		return;
	}
	Node *ptr=Head;
	Node *preptr;
  for(int i=1;i<pos;i++)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
	cout<<"\n";
	cout<<"\n The elements from "<<pos<<" position ";
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"  ";
		ptr=ptr->next;
	}
	cout<<"\n";
	cout<<"\n The elements before "<<pos<<" position ";
  Node *ptr1=Head;
	while(ptr1!=preptr->next)
	{
		cout<<ptr1->data<<"  ";
	  ptr1=ptr1->next;
	}
}
	
	
	
	

	
	
	
	

	