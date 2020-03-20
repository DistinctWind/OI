#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=1e3+1;
char a[MAXL],b[MAXL];
int la,lb,ans;
int p[MAXL];
inline void setup()
{
	int j=0;
	p[1]=0;
	for (int i=1;i<lb;i++)
	{
		while (j>0&&b[j+1]!=b[i+1]) j=p[j];
		if (b[j+1]==b[i+1]) j++;
		p[i+1]=j;
	}
}
inline void kmp()
{
	ans=0;
	int j=0;
	for (int i=0;i<la;i++)
	{
		while (j>0&&b[j+1]!=a[i+1])
			j=p[j];
		if (b[j+1]==a[i+1])
			j++;
		if (j==lb)
		{
			ans++;
			j=0;
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf(" %s",a+1)!=EOF)
	{
		la=strlen(a+1);
		if (la==1&&a[1]=='#') break;
		scanf(" %s",b+1);
		lb=strlen(b+1);
		setup();
		kmp();
		printf("%d\n",ans);
	}
}
//LOJ https://loj.ac/problem/10043
