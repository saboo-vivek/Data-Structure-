/*  reverse a stack   */
#include<iostream>
#include<conio>
class stack
{
	public:
	int pop();
	void push(int);
	int top=-1;
	int stk[10];
};
int main()
{
	stack call;
	int n,val,arr[10];
	cout<<"\nEnter no of elements in array";
	cin>>n;
	cout<<"\nEnter elements in array";
	for(int i=0;i<n;i++)
        cin>>a[i];
	for(int i=0;i<n;i++)
		call.push(a[i]);
	for(int i=0;i<n;i++)
	{
		val=call.pop();
		a[i]=val;
	}
	cout<<"\nThe reversed list is";
	for(int i=0;i<n;i++)
		cout<<" "<<a[i];
	return 0;
}
void stack::push(int x)
{
	stk[++top]=x;
}
int stack::pop()
{
	int val=stk[top];
	top--;
	return val;
}

	 
	