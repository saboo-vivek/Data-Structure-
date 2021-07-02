/*   MENU DRIVEN circular queue program   */
#include<iostream>
#include<conio>
#define MAX 10
using namespace std;
int que[MAX];
int front==1,rear=-1;
void insert(int);
void del();
void peek();
void display();
int main()
{
	int val, option;
    do
    {
	    printf("\n *****MAIN MENU*****");
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. PEEK");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			printf("\n Enter the number to be INSERTED in queues: ");
			scanf("%d", &val);
			insert(val);
			break;

		case 2:
			del();
			break;

		case 3:
			peek();
			break;

		case 4:
			display();
			break;
		}
	}while(option != 5);
	return 0;
}
void insert(int x)
{
	if(front==-1 && rear==-1)
	{
		rear=front=0;
		que[rear]=x;
	}
	else if(front==0 && rear==MAX-1)
		cout<<"\n OVERFLOW";
	else if(front!=0 && rear==MAX-1)
	{
		rear=0;
		que[rear]=x;
	}
	else
	{
		rear++;
		if(rear==front)
			cout<<"\n OVERFLOW";
		else
			que[rear]=x;
	}
}
void del()
{
	if(front==-1&& rear==-1)
		cout<<"\n UNDERFLOW";
	int temp=que[front];
	cout<<"\nDeleted element is: "<<temp;
	
    if(rear==front)
		front=rear=-1;
	else if(front==MAX-1)
		front=0;
	else 
		front++;
}
void peek()
{
	if(front==-1&& rear==-1)
		cout<<"\n UNDERFLOW <EMPTY> ";
	else
	{
		int temp=que[front];
		cout<<"\n The top element is : "<<temp;
	}
}
void display()
{
	int i;
	cout<<"\n";
	if(front==-1&& rear==-1)
		cout<<"\n <EMPTY> ";
	else
	{
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
				cout<<que[i]<<" ";
		}
		else
		{
			for(i=front;i<MAX;i++)
				cout<<que[i]<<" ";
			for(i=0;i<=rear;i++)
				cout<<que[i]<<" ";
		}
	}
}
			
			
	
	
	
	
	
		
	
		