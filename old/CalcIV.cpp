#include <cstdio>
#include <stack>
using namespace std;
stack <int> num;
stack <char> op;
char now;
int main()
{
	while (now=getchar(),now!='@')
	{
		if ('0'<=now&&now<='9')
		{
			int tmp=now-'0';
			while (now=getchar(),now!='.')
			{
				tmp=tmp*10+now-'0';
			}
			num.push(tmp);
		}
		else
		{
			int a,b; op.push(now);
			b=num.top(); num.pop();
			a=num.top(); num.pop();
			switch (op.top())
			{
				case '+':num.push(a+b);break;
				case '-':num.push(a-b);break;
				case '*':num.push(a*b);break;
				case '/':num.push(a/b);break;
			}
			op.pop();
		}
	}
	printf("%d",num.top());
}
