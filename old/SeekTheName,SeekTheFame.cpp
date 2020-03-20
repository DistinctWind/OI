#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXL=400001;
int len,p[MAXL];
char a[MAXL];
inline void setup()
{
	memset(p,0,sizeof(p));
	len=strlen(a+1);
	for (int i=2,j=0;i<=len;i++)
	{
		while (j>0&&a[i]!=a[j+1]) j=p[j];
		if (a[i]==a[j+1]) j++;
		p[i]=j;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf(" %s",a+1)!=EOF)
	{
		setup();
		int j=len;
		stack <int> s;
		s.push(j);
		while (j>0)
		{
			j=p[j];
			if (j!=0)
				s.push(j);
		}
		while (!s.empty())
		{
			printf("%d ",s.top());
			s.pop();
		}
		putchar('\n');
	}
}
