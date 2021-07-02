#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
	
	void insert(int);
	void print();
	void reverse();
};
Node* Head;
int main()
{
	Node list;
	Head=NULL;
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
	cout<<"\n reversing...";
	list.reverse();
	list.print();
	return 0;
}
void Node::insert(int x)
{
	Node *new_node=new Node();
	new_node->data=x;
	new_node->next=Head;
	Head=new_node;
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
void Node::reverse()
{
	Node *pre_node,*curr_node;
	if(Head==NULL)
		cout<<"list is empty to be reversed"<<endl;
	else
	{
		pre_node=Head;
		curr_node=Head->next;
		Head=Head->next;
		pre_node->next=NULL;
		while(Head!=NULL)
		{
			Head=Head->next;
			curr_node->next=pre_node;
			
			pre_node=curr_node;
			curr_node=Head;
		}
		Head=pre_node;
		cout<<"\n list is reversed sucessfully.";
	}
}
		
		