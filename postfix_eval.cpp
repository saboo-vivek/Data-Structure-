/* evaluation of postfix form  */
#include<iostream>
#include<cstdio>
#define MAX 100
using namespace std;
class eval
{
	public:
	void push(float);
	float pop();
};
float stk[MAX];
int top=-1;
int main()
{
	eval obj;
	string post;
	cout<<"\nEnter any postfix express";
	cin>>post;
	int i=0;
	float a,b,r;
	while(post[i]!='\0')
	{
		if(isdigit(post[i])
			obj.push(post[i])
		else
		{
			a=obj.pop();
			b=obj.pop();
			switch(post[i])
			{
				case '+':
				r=b+a;
				break;
				case '-':
				r=b-a;
				break;
				case '*':
				r=b*a;
				break;
				case '/':
				r=b/a;
				break;
				case '%':
				r=b%a;
				break;
			}
			obj.push(r);
		}
		i++;
	}
	cout<<"\nTHE FINAL RESULT IS:"<<obj.pop();
}
void eval::push(float x)
{
	top++;
	stk[top]=x;
}
float eval::pop()
{
	float x=stk[top];
	top--;
	return x;
}

	
