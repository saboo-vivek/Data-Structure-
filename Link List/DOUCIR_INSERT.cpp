/*   circular double link list implementation--->INSERTION   */
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
Node *Last;
int len=0;
int main()
{
	Node list;
	Head=NULL;
	Last =NULL;
	int size, number;
	cout<<"What is the size of list: ";
	cin>>size;
	for(int i = 1; i<=size; i++)
	{
		cout<<"Enter Number: "<<endl;
		cin>>number;
		list.insert_end(number);
		list.print();
	}
	
	list.insert_at(3,13);
	list.print();
  list.print(4);
	return 0;
}
void Node::insert_beg(int x)
{
  Node *newnode=new Node();
	newnode->data=x;
  if(Head==NULL)
	{
    Head=newnode;
    Last=newnode;
    Head->next=Head;
    Head->pre=Head;
    cout<<"\n FIRST NODE INSERTED";
	  len++;
		return;
	}
  newnode->next=Head;
	Head->pre=newnode;
	newnode->pre=Last;
	Last->next=newnode;
	Head=newnode;
	len++;
}
void Node::insert_end(int x)
{
  Node *newnode=new Node();
	newnode->data=x;
  if(Head==NULL)
	{
    Head=newnode;
    Last=newnode;
    Head->next=Head;
    Head->pre=Head;
    cout<<"\n FIRST NODE INSERTED";
	  len++;
		return;
	}
  newnode->pre=Last;
  Last->next=newnode;
  newnode->next=Head;
  Head->pre=newnode;
  Last=newnode;
  len++;

}
void Node::insert_at(int pos,int x)
{
  Node list;
  if(pos==1)
  {
    list.insert_beg(x);
  }
  else if(pos==(len+1))
  {
    list.insert_end(x);
  }
  else if(pos>1 && pos<=len)
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
    newnode->next=ptr;
    ptr->pre=newnode;
    preptr->next=newnode;
    newnode->pre=preptr;
    len++;
  }
  else
  cout<<"\nPosition out of range"; 

}
void Node::print()
{
	if(Head==NULL)
	{
		cout<<"\n List is empty";
		return;
	}
  cout<<"List is: ";
	Node *ptr=Head;
	while(ptr->next!=Head)
	{
		cout<<" "<<ptr->data;
		ptr=ptr->next;
	}
  cout<<" "<<ptr->data;
  cout<<"\n";
 }
 void Node::print(int pos)
 {
   Node *ptr=Head;
   for(int i=1;i<pos;i++)
   ptr=ptr->next;
   Node *ptr1,*temp;
   ptr1=ptr;
   temp=ptr;
   cout<<"\ntraverse in right/forward direction"<<endl;
   while(ptr->next!= temp)
   {
     cout<<" "<<ptr->data;
     ptr=ptr->next;
   }
   cout<<" "<<ptr->data;
   cout<<"\n";
   cout<<"\ntraverse in left direction"<<endl;
   while(ptr1->pre!=temp)
   {
     cout<<" "<<ptr1->data;
     ptr1=ptr1->pre;

   }
    cout<<" "<<ptr1->data;

 }

		
		
	
	
		
		
	
