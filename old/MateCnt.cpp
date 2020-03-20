#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXL=200001;
int n,m,q,p[MAXL],f[MAXL],cnt[MAXL];
char a[MAXL],b[MAXL];
inline void setup()
{
	p[1]=0;
	int j=0;
	for (int i=1;i<m;i++)
	{
		while (j>0&&b[i+1]!=b[j+1]) j=p[j];
		if (b[i+1]==b[j+1]) j++;
		p[i+1]=j;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	scanf(" %s %s",a+1,b+1);
	setup();
	for (int i=1,j=0;i<=n;i++)
	{
		while (j>0&&a[i]!=b[j+1]) j=p[j];
		if (a[i]==b[j+1]) j++;
		f[i]=j;
		if (j==m) j=p[j];
	}
	for (int i=1;i<=n;i++)
		cnt[f[i]]++;
	for (int i=m;i>=1;i--)
		cnt[p[i]]+=cnt[i];
	for (int i=1;i<=q;i++)
	{
		int query;
		scanf("%d",&query);
		printf("%d\n",cnt[query]-cnt[query+1]);
	}
}
