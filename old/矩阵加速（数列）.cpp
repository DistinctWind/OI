#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=4;
struct Matrix{
	int n,m;
	ll num[MAXN][MAXN];
	Matrix(){
		n=m=0;
		memset(num,0,sizeof(num));
	}
	void print(){
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				printf("%d%c",num[i][j],j==m?'\n':' ');
	}
};
Matrix operator * (const Matrix &a,const Matrix &b)
{
	Matrix c;
	if (a.m!=b.n)
	{
		c.n=c.m=-1;
		return c;
	}
	for (int i=1;i<=a.n;i++)
		for (int j=1;j<=b.m;j++)
			for (int k=1;k<=a.m;k++)
				c.num[i][j]=(c.num[i][j]+(a.num[i][k]*b.num[k][j])%mod)%mod;
	c.n=a.n,c.m=b.m;
	return c;
}
Matrix pow_plus(int x)
{
	Matrix tmp,b,res;
	tmp.n=1,tmp.m=3;
	for (int i=1;i<=3;i++)
		tmp.num[1][i]=1;
	res.n=3,res.m=3;
	for (int i=1;i<=3;i++)
		res.num[i][i]=1;
	b.n=3,b.m=3;
	b.num[1][3]=b.num[2][1]=b.num[3][2]=b.num[3][3]=1;
	while (x)
	{
		if (x&1) res=res*b;
		b=b*b;
		x>>=1;
	}
	return tmp*res;
}
int T;
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		ll x;
		scanf("%lld",&x);
		if (x<=3) printf("1\n");
		else printf("%lld\n",pow_plus(x-3).num[1][3]);
	}
}
