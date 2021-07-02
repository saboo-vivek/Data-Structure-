/*   Stack implementation using array --->menu driven   */
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class Stack
{
	public:
  	int a[MAX];
  
    int top=-1;
	void push(int);
	void pop();
	void peek();
	void print();
};
int main()
{
	Stack call;
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
void Stack::push(int x)
{
	if(top==(MAX-1))
		cout<<"\n Stack is full";
	else
	{
		top++;
		a[top]=x;
	}
}
void Stack::pop()
{
	if(top==-1)
		cout<<"\n Stack is empty";
	else
	{
	 int x=a[top];
	 top--;
	 printf("\n The value deleted from stack is: %d",x);
	}
}
void Stack::peek()
{
	if(top==-1)
		cout<<"\nStack is empty";
	else
	{
		int x=a[top];
		cout<<"\n The value at top peak is:"<<x;
	}
}
void Stack::print()
{
	if(top==-1)
		cout<<"\nStack is empty";
	else
	{
		for(int i=top;i>=0;i--)
			cout<<" "<<a[top];
	}
}
	
	
	