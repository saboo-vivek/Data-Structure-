/*   IMPLEMENTATION of priority queue   */
#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	int pri;
	Node *next;
	
	void insert(int,int);
	void del();
	void dis();
};
Node *Head;
int main()
{
	Node call;
	Head=NULL;
	int d,p;
	for(int i=1;i<5;i++)
	{
		cout<<"\nEnter the data and priority: ";
		scanf("%d %d",&d,&p);
		call.insert(d,p);
		call.dis();
	}
	call.del();
	call.dis();
	return 0;
}
void Node::insert(int x,int p)
{
	Node *newnode=new Node();
	newnode->data=x;
	newnode->pri=p;
	if(Head==NULL || p +<Head->pri)
	{
		newnode->next=Head;
		Head=newnode;
	}
	else
	{
		Node *ptr=Head;
		while(ptr->next!=NULL && ptr->next->pri<=p)
			ptr=ptr->next;
		newnode->next=ptr->next;
		ptr->next=newnode;
		
	}
}
void Node::del()
{
	if(Head==NULL)
	{
	cout<<"\nEmpty queues";
	}
	else
	{
		Node *ptr=Head;
		Head=Head->next;
		free(ptr);
	}
}
void Node::dis()
{
	cout<<"\n";
	Node *ptr=Head;
	if(Head==NULL)
		cout<<"\nEmpty Queues";
	else
	{
		while(ptr!=NULL)
		{
		cout<<ptr->data<<"[Priority "<<ptr->pri<<"] ---> ";
		ptr=ptr->next;
		}
	}
}
			
	
