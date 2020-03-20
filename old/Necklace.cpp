#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXL=10001;
int n,m,ans,t,s,p[MAXL],f[2][MAXL];
char a[MAXL],b[MAXL];
inline void setup()
{
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
	//freopen("out.txt","w",stdout);
	int cnt=0;
	char tmp=getchar();
	while ('a'<=tmp&&tmp<='z')
	{
		a[++cnt]=tmp;
		tmp=getchar();
	}
	n=cnt; cnt=0; 
	while (tmp<'a'||'z'<tmp)
	{
		tmp=getchar();
	}
	while ('a'<=tmp&&tmp<='z')
	{
		b[++cnt]=tmp;
		tmp=getchar();
	}
	m=cnt;
	setup();
	memset(f,0xff,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		t=s,s=s^1;
		memcpy(f[s],f[t],sizeof(f[t]));
		for (int j=0;j<m;j++)
		{
			if (~f[t][j])
			{
				int l=j;
				while (l>0&&a[i]!=b[l+1]) l=p[l];
				if (a[i]==b[l+1]) l++;
				f[s][l]=max(f[s][l],f[t][j]+1);
			}
		}
	}
	for (int i=0;i<m;i++)
		ans=max(ans,f[n&1][i]);
	printf("%d",n-ans);
}
//DHOJ http://47.104.154.247/problem.php?cid=1124&pid=4
