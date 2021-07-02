/*    infix to postfix conversion    */
#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100

class post
{
	public:
	void push(char);
	char pop();
	int priority(char);
};
char stk[ MAX ];
 int top=-1;
int main()
{
  
	post call;
	string infix,postfix="";
	cout<<"\nEnter any infix: ";
	cin>>infix;
	int i=0;
	char temp;
	while(infix[i]!='\0')
	{
		if(infix[i]=='(')
		{
			call.push(infix[i]);
			i++;
		}
		else if(isalpha(infix[i]) || isdigit(infix[i]))
		{
			postfix=postfix+infix[i];
			i++;
		}
		else if(infix[i]==')')
		{
			while((top!=-1)&&(stk[top]!='('))
			{
				postfix=postfix+call.pop();
			}
			if(top==-1)
			{
				cout<<"\n INCORRECT EXPRESSION";
				return 0;
			}
            temp=call.pop();//remove left paren//
			i++;
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' ||infix[i]=='/' || infix[i]=='%')
		{
			while((top!=-1)&&(stk[top]!='(')&&(call.priority(stk[top])>call.priority(infix[i])))
			{
				postfix+=call.pop();
			}
		call.push(infix[i]);
		i++;
		}
		else
		{
			cout<<"\nINCORRECT ELEMENT IN THE EXPRESSION";
			return 0;
		}
	}
	cout<<"\n THE POSTFIX EXPRESSION IS :"<<postfix;
}
void post::push(char ch)
{
  top++;
	stk[top]=ch;
}
char post::pop()
{
	char ch;
	ch=stk[top];
	top--;
	return ch;
}
int post::priority(char op)
{
	if(op=='/' || op == '*' || op=='%')
        return 1;
    else if(op=='+' || op=='-')
        return 0;
}
	

			
			
				
			
	
	
	
	
	