/*   Circular singular link list implementation--->INSERTION   */

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
	
	void insert_beg(int);
	void insert_end(int);
	void insert_pos(int,int);
  void print();
};
int len=0;
Node *Head;
Node *Last;
int main()
{
	Node list;
	Last=NULL;
	Head=NULL;
	int size, number;
	cout<<"What is the size of list: ";
	cin>>size;
	for(int i = 1; i<=size; i++)
	{
		cout<<"\nEnter Number: ";
		cin>>number;
		list.insert_end(number);
		list.print();
	}
  list.insert_pos(3,13);
  list.print();
  cout<<"\n length : "<<len;
	return 0;
}
void Node::insert_beg(int x)
{	 
  
	if(Head==NULL)
	{
    Head=new Node();
		Head->next=Head;
    Head->data=x;
		Last=Head;
    len++;
		return;
	}
  Node *newnode=new Node();
  newnode->data=x;
	
	newnode->next=Head;
	Last->next=newnode;
	Head=newnode;
  len++;
}
void Node::insert_end(int x)
{
  if(Head==NULL)
	{
    Head=new Node();
		Head->next=Head;
    Head->data=x;
		Last=Head;
    len++;
		return;
	}
  Node *newnode=new Node();
  newnode->data=x;
  Last->next=newnode;
  newnode->next=Head;
  Last=newnode;
  len++;
}
void Node::insert_pos(int pos,int x)
{
  Node list;
  if(pos==1)
  {
    list.insert_beg(x);
    return;
  }
  if(pos==len)
  {
    list.insert_end(x);
    return;
  }
  if(pos>1 && pos<len)
  {
    Node *ptr=Head;
    Node *preptr;
    for(int i=1;i<pos;i++)
    {
      preptr=ptr;
      ptr=ptr->next;
    }
    Node *newnode=new Node();
    newnode->data=x;
    preptr->next=newnode;
    newnode->next=ptr;
    len++;
  }
  else 
  cout<<"\n insert postion not in range";
  
}
void Node::print()
{
	Node *ptr=Head;
	while(ptr->next!=Head)
	{
		cout<<" "<<ptr->data;
		ptr=ptr->next;
	}
  cout<<" "<<ptr->data;
  cout<<"\n";
}

		
	
	
		