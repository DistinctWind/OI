#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=1000010;
int nxt[MAXL];
char a[MAXL],b[MAXL];
int n,m;
inline void setup()
{
	nxt[1]=0;
	for (int i=2,j=0;i<=m;i++)
	{
		while (j>0&&b[i]!=b[j+1]) j=nxt[j];
		if (b[i]==b[j+1]) j++;
		nxt[i]=j;
	}
}
inline void Kmp()
{
	for (int i=1,j=0;i<=n;i++)
	{
		while (j>0&&a[i]!=b[j+1]) j=nxt[j];
		if (a[i]==b[j+1]) j++;
		if (j==m)
		{
			printf("%d\n",i-j+1);
			j=nxt[j];
		}
	}
}
int main()
{
	scanf(" %s %s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	setup();
	Kmp();
	for (int i=1;i<=m;i++)
		printf("%d ",nxt[i]);
}
