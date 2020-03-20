#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXL=1e3+1;
int len;
char a[MAXL];
stack <char> tmp,op;
int order(char x)
{
	switch (x)
	{
		case '(': return 3;
		case '*':
		case '/': return 2;
		case '+':
		case '-': return 1;
		case ')': return 0;
		case '#': return -1;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf(" %s",a);
	op.push('#');
	len=strlen(a);
	for (int i=len-1;i>=0;i--)
	{
		switch (a[i])
		{
			case ')':
				op.push(a[i]);
				break;
			case '(':
				while (op.top()!=')')
				{
					tmp.push(op.top());
					op.pop();
				}
				op.pop();
				break;
			default :
				if ('0'<=a[i]&&a[i]<='9')
				{
					tmp.push(a[i]);
				}
				else
				{
					if (order(op.top())<=order(a[i]))
					{
						op.push(a[i]);
					}
					else
					{
						while (op.top()!='#')
						{
							tmp.push(op.top());
							op.pop();
						}
						op.push(a[i]);
					}
				}
		}
	}
	while (op.top()!='#')
	{
		tmp.push(op.top());
		op.pop();
	}
	while (tmp.size()>0)
	{
		putchar(tmp.top());
		tmp.pop();
	}
}
