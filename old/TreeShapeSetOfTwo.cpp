#include <cstdio>
using namespace std;
const int MAXN=4097;
const int MAXM=4097;
long long n,m,bit[MAXN][MAXM];
long long lowbit(long long x)
{
	return x&(~x+1);
}
inline void update(long long x,long long y,long long k)
{
	for (long long i=x;i<=n;i+=lowbit(i))
		for (long long j=y;j<=m;j+=lowbit(j))
			bit[i][j]+=k;
}
long long sum(int x,int y)
{
	long long res=0;
	for (long long i=x;i>0;i-=lowbit(i))
		for (long long j=y;j>0;j-=lowbit(j))
			res+=bit[i][j];
	return res;
}
inline void read(long long &x)
{
	long long k=1;
	x=0;
	char tmp=getchar();
	while (tmp<'0'||tmp>'9')
	{
		if (tmp=='-') k=-1;
		tmp=getchar();
	}
	while ('0'<=tmp&&tmp<='9')
	{
		x=x*10+tmp-'0';
		tmp=getchar();
	}
	x=x*k;
}
void write(long long x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(n); read(m);
	long long s;
	while (scanf("%lld",&s)!=EOF)
	{
		if (s==1)
		{
			long long x,y,k;
			read(x); read(y); read(k);
			update(x,y,k);
		}
		else if (s==2)
		{
			long long a,b,c,d;
			read(a); read(b); read(c); read(d);
			write(sum(c,d)-sum(c,b-1)-sum(a-1,d)+sum(a-1,b-1));
			putchar('\n');
		}
	}
}
//LOJ https://loj.ac/problem/133
