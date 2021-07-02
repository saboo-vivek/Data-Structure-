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
	void sort();
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
		cout<<"\nEnter Number: ";
		cin>>number;
		list.insert(number);
		list.print();
	}
	cout<<"\n sorted ::";
	list.sort();
	list.print();
	return 0;
}
void Node::insert(int x)
{
	Node* new_node=new Node();
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
void Node::sort()
{
	if(Head==NULL)
	{
		cout<<"list is empty to be sorted"<<endl;
		return;
	}
	Node *ptr,*ptr1;
	ptr=Head;
	//selection sort//
	while(ptr!=NULL)
	{
		for(ptr1=ptr->next;ptr1!=NULL;ptr1=ptr1->next)
		{
			int value;
			if(ptr->data > ptr1->data)
			{
				value=ptr->data;
				ptr->data=ptr1->data;
				ptr1->data=value;
			}
		}
		ptr=ptr->next;
	}
}
				
