#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXL=101;
char a[MAXL],b[MAXL];
int len;
stack <int> s;
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf(" %s",a)!=EOF)
	{
		while (!s.empty()) s.pop();
		len=strlen(a);
		for (int i=0;i<len;i++)
		{
			switch (a[i])
			{
				case '(': b[i]='$'; break;
				case ')': b[i]='?'; break;
				default : b[i]=' '; break;
			}
		}
		for (int i=0;i<len;i++)
		{
			if (a[i]=='(')
				s.push(i);
			if (a[i]==')')
			{
				if (!s.empty())
				{
					int l=s.top();
					s.pop();
					b[i]=b[l]=' ';
				}
				else continue;
			}
		}
		printf("%s\n%s\n",a,b);
	}
}
