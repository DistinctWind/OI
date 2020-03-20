#include <cstdio>
using namespace std;
const int MAXN=1e5+1;
const int LOGN=17;
int n,m;
int num[MAXN],log[MAXN],f[MAXN][LOGN];
int max(int a,int b)
{
	return a>b?a:b;
}
inline void setup()
{
	log[0]=-1;
	for (int i=1;i<=n;i++)
		f[i][0]=num[i],log[i]=log[i>>1]+1;
}
inline void dp()
{
	for (int j=1;j<=LOGN;j++)
	{
		for (int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
}
inline void read(int &x)
{
	int k=1; x=0;
	char a=getchar();
	while (a<'0'||a>'9') 
	{
		if (a=='-') k=-1;
		a=getchar();
	}
	while ('0'<=a&&a<='9')
	{
		x=x*10+a-'0';
		a=getchar();
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(n); read(m);
	for (int i=1;i<=n;i++)
		read(num[i]);
	setup();
	dp();
	for (int i=1;i<=m;i++)
	{
		int l,r;
		read(l); read(r);
		int k=log[r-l+1];
		printf("%d\n",max(f[l][k],f[r-(1<<k)+1][k]));
	}
}
//LOJ https://loj.ac/problem/10119
