#include <cstdio>
#include <cmath>
using namespace std;
const int MAXC_P=500000;
int t;
int a,b,c,d;
int cnt,v[MAXC_P],prime[MAXC_P];
long long ans;
inline void calc()
{
	int limit=sqrt(2e9);
	for (int i=2;i<=limit;i++)
	{
		if (v[i]==0)
		{
			v[i]=i;
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt;j++)
		{
			if (prime[j]>v[i]||i*prime[j]>limit) break;
			v[i*prime[j]]=prime[j];
		}
	}
	/*for (int i=1;i<=cnt;i++)
		printf("%d ",prime[i]);*/
}
int pcount(int x,int p)
{
	int res=0;
	while (x%p==0)
	{
		x/=p;
		res++;
	}
	return res;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//calc();
	scanf("%d",&t);
	while (t--)
	{
		ans=0;
		scanf("%d%d%d%d",&a,&c,&b,&d);
		/*for (int i=1,ma,mb,mc,md,cx;i<=cnt;i++)
		{
			if (d%prime[i]!=0) break;
			ma=mb=mc=md=cx=0;
			ma=pcount(a,prime[i]);
			mb=pcount(b,prime[i]);
			mc=pcount(c,prime[i]);
			md=pcount(d,prime[i]);
			if (ma>mc&&mb<md&&mc==md) cx++;
			if (ma>mc&&mb==md&&mc<=md) cx++;
			if (ma==mc&&mb<md&&mc<=md) cx++;
			if (ma==mc&&mb==md&&mc<=md) cx+=md-mc+1;
			ans*=cx;
		}
		printf("%lld\n",ans);*/
		int p=d/b,q=a/c;
		for (int x=1,y;x*x<=d;x++)
		{
			if (d%x!=0) continue;
			if (x%c==0&&gcd(d/x,p)==1&&gcd(x/c,q)==1) ans++;
			y=d/x;
			if (x==y) continue;
			if (y%c==0&&gcd(d/y,p)==1&&gcd(y/c,q)==1) ans++;
		}
		printf("%lld\n",ans);
	}
}
