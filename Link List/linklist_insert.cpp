#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
	public:
	
	int data;
	Node *next;
	
	void insert_begin(int);
	void insert_after(int,int);
	void insert_end(int);
	void print();
};
Node *Head;
int main()
{
	Node list;
	*Head=NULL;
	list.insert_after(2,5);
	list.insert_begin(5);
	list.insert_begin(8);
	list.insert_end(15);
	list.insert_after(3,23);
	list.insert_end(9);
	list.print();
	return 0;
}
void Node::insert_begin(int x)
{
	Node* new_node=new Node();
	new_node->data=x;
	new_node->next=Head;
	Head=new_node;
}
void Node::insert_after(int pos,int x)
{
	int ctr=0;
	Node* new_node=new Node();
	new_node->data=x;
	Node *pre_node,*temp;
	temp=Head;
	while(temp!=NULL)
	{
		temp=temp->next;
		ctr++;
	}
	if(pos==1)
	{
		
	    new_node->next=Head;
	    Head=new_node;
	}
	else if(pos>1 && pos <=ctr)
	{
		temp=Head;
		for(int i=1;i<pos;i++)
		{
			pre_node=temp;
			temp=temp->next;
		}
		new_node->next=pre_node->next;
		pre_node->next=new_node;
	}
	else
		cout<<"Postion out of range"<<endl;
}
void Node::insert_end(int x)
{
	Node* new_node=new Node();
	new_node->data=x;
	new_node->next=NULL;
	//if the list is empty//
	if(Head==NULL)
	{
		Head=new_node;
		return 0;
	}
	
	{
	Node *last=Head;
	while(last!=NULL)
		last=last->next;
	last->next=new_node;
	}
	
}
void Node::print()
{
	Node *temp=Head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
		
	
	
