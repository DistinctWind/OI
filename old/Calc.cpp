#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXL=4000001;
stack <char> oper;
stack <int> num;
int len;
char a[MAXL];
bool judge(char now)//ture is wait
{
	if (oper.size()==0) return true;
	switch (now)
	{
		case '+':
			if (oper.top()=='*') return false;
			else return true;
			break;
		case '*':
			return true;
	}
}
void calc()
{
	if (num.size()==1) return;
	int a,b;
	a=num.top(); num.pop();
	b=num.top(); num.pop();
	switch (oper.top())
	{
		case '+':
			num.push((a+b)%10000);
			break;
		case '*':
			num.push((a*b)%10000);
			break;
	}
	oper.pop();
	if (oper.size()!=0)
		calc();
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf(" %s",a);
	len=strlen(a);
	int tmp=0;
	for (int i=0;i<len;i++)
	{
		if (a[i]!='+'&&a[i]!='*')
		{
			tmp=tmp*10+a[i]-'0';
		}
		else
		{
			num.push(tmp%10000);
			tmp=0;
			if (judge(a[i]))
			{
				oper.push(a[i]);
			}
			else
			{
				calc();
				oper.push(a[i]);
			}
		}
	}
	num.push(tmp%10000);
	calc();
	printf("%d",num.top()%10000);
}
//DHOJ http://47.104.154.247/problem.php?cid=1115&pid=0
