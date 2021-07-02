/*   stack implementation using link list------> Menu Driven  */
#include<iostream>
#include<cstdlib>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	void push(int);
	void pop();
	void peek();
	void print();
};
Node *top;
int main()
{
	top=NULL;
	Node call;
	int val, option;
    do
    {
	    printf("\n *****MAIN MENU*****");
		printf("\n 1. PUSH");
		printf("\n 2. POP");
		printf("\n 3. PEEK");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			printf("\n Enter the number to be pushed on stack: ");
			scanf("%d", &val);
			call.push(val);
			break;

		case 2:
			call.pop();
			break;

		case 3:
			call.peek();
			break;

		case 4:
			call.print();
			break;
		}
	}while(option != 5);
	return 0;
}
void Node::push(int x)
{
	Node *newnode=new Node();
	newnode->data=x;
	if(top==NULL)
	{
		newnode->next=NULL;
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void Node::pop()
{
	if(top==NULL)
		cout<<"\nStacks is empty";
	else
	{
		Node *ptr=top;
		top=top->next;
		cout<<"\nNode is successfully removed and the value of node is: "<<ptr->data;
		free(ptr);
	}
}
void Node::peek()
{
	if(top==NULL)
		cout<<"\nStacks is empty";
	else
		cout<<"Value on top is: "<<top->data;
}
void Node::print()
{
	Node *ptr=top;
	cout<<"\nThe stacks list is: ";
	cout<<"\n";
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"<- ";
		ptr=ptr->next;
	}
	cout<<"NULL";
}
	
