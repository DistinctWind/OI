#include <cstdio>
using namespace std;
const int MAXN=5e4+1;
const int LOGN=16;
int n,q,h[MAXN],log[MAXN];
int f[MAXN][LOGN+1],g[MAXN][LOGN+1];
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b; 
}
inline void read(int &x)
{
	x=0;
	char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
}
void write(int x)
{
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
inline void setup()
{
	log[0]=-1;
	for (int i=1;i<=n;i++)
	{
		log[i]=log[i>>1]+1;
		f[i][0]=g[i][0]=h[i];
	}
}
inline void dp()
{
	for (int j=1;j<=LOGN;j++)
	{
		for (int i=1;i+(1<<j)-1<=n;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
			g[i][j]=min(g[i][j-1],g[i+(1<<j-1)][j-1]);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(n); read(q);
	for (int i=1;i<=n;i++)
		read(h[i]);
	setup();
	dp();
	for (int i=1;i<=q;i++)
	{
		int a,b;
		read(a); read(b);
		int k,maxn,minn;
		k=log[b-a+1];
		maxn=max(f[a][k],f[b-(1<<k)+1][k]);
		minn=min(g[a][k],g[b-(1<<k)+1][k]);
		write(maxn-minn);
		putchar('\n');
	}
}
//LOJ https://loj.ac/problem/10123
//LGOJ https://www.luogu.org/problem/P2880
//JOYOI http://www.joyoi.cn/problem/tyvj-2497
//VIJOS https://vijos.org/d/newbzoj/p/590c98d8d3d8a132109938d9
