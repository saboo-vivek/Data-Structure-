/*   Double link list implementation--->DELETION   */
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
	void print();
  void del(int);
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
		list.insert_beg(number);
		
	}
	list.print();
	list.del(1);
    list.print();
	list.del(7);
    list.print();
	list.del(3);
    list.print();
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
	cout<<"\n Traverse in reverse direction: ";
	while(ptr1!=NULL)
	{
		cout<<ptr1->data<<"  ";
		ptr1=ptr1->pre;
	}
	cout<<"\n";
	cout<<"\n";
}
void Node::del(int pos)
{
  if(Head==NULL)
  {
    cout<<"list is empty to be deleted"<<endl;
    return;
  }
  Node *ptr=Head;
  int ctr=0;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		ctr++;//no of link list calculated//
	}
	
	ptr=Head;
	if(pos==1)
	{
	Head=Head->next;
	Head->pre=NULL;
	free(ptr);
	}
  else if(pos==ctr)
  {
    while(ptr->next!=NULL)
      ptr=ptr->next;
	ptr->pre->next=NULL;
	free(ptr);
  }
  else if(pos>1 && pos<ctr)
  {
	  Node *preptr;
	  for(int i=1;i<pos;i++)
	  {
		  preptr=ptr;
		  ptr=ptr->next;
	  }
	  preptr->next=ptr->next;
	  ptr->next->pre=preptr;
	  free(ptr);
  }
  else
	  cout<<"\npostion to be deleted is out of range";
  
}

	
	
	
	

	
	
	
	

	