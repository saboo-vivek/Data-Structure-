/*   circular singular link list implementation--->DELETION   */

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
	void del_pos(int);
	void del_all();
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
		list.insert_beg(number);
		list.print();
	}
  list.del_pos(3);
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
void Node::del_pos(int pos)
{
	if(Head==NULL)
	{
		cout<<"\nlist is empty,nothing to be deleted";
		return;
	}
	Node *ptr=Head;
	if(pos==1)
	{
		Head=Head->next;
    free(ptr);
    Last->next=Head;
    len--;
    return;
  }
  if(pos>1 && pos<=len)
  { 
    Node *preptr;
    for(int i=1;i<pos;i++)
    {
      preptr=ptr;
      ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    if(pos==len)
    Last=preptr;
    len--;
  }
  else
  cout<<"\n deleted position out of range";
}
void Node:: del_all();
{
	Node *ptr=Head;
	while(ptr->next!=Head)
	{
		Head=Head->next;
		free(ptr);
	ptr=ptr->next;
	}
}
		
	


	
		