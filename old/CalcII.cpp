#include <cstdio>
#include <stack>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXL=1e3+1;
char a[MAXL];
int len;
stack <char> op;
string s;
int order(char x)
{
	switch (x)
	{
		case ')': return 3;
		case '*':
		case '/': return 2;
		case '+':
		case '-': return 1;
		case '(': return 0;
		case '#': return -1;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf(" %s",a);
	len=strlen(a);
	op.push('#');
	for (int i=0;i<len;i++)
	{
		switch (a[i])
		{
			case '(':
				op.push('(');
				break;
			case ')':
				while (op.top()!='(')
				{
					s=s+op.top();
					op.pop();
				}
				op.pop();
				break;
			default :
				if ('0'<=a[i]&&a[i]<='9')
				{
					s=s+a[i];
				}
				else
				{
					if (order(op.top())<order(a[i]))
					{
						op.push(a[i]);
					}
					else
					{
						while (order(op.top())>=order(a[i]))
						{
							s=s+op.top();
							op.pop();
						}
						op.push(a[i]);
					}
				}
		}
	}
	while (op.top()!='#')
	{
		s=s+op.top();
		op.pop();
	}
	cout<<s<<endl;
}
