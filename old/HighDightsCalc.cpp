#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1010;
int max(int a,int b)
{
	return a>b?a:b;
}
struct Bignum{
	int len;
	int num[10001];
	Bignum()
	{
		len=0;
		memset(num,0,sizeof(num));
	}
	void read()
	{
		int tmp; len=0;
		scanf("%d",&tmp);
		while (tmp)
		{
			len++;
			num[len]=tmp%10;
			tmp/=10;
		}
	}
	void write()
	{
		if (len==0) printf("0");
		for (int i=len;i>=1;i--)
			printf("%d",num[i]);
	}
};
int n;
bool operator < (Bignum a,Bignum b)
{
	if (a.len!=b.len) return a.len<b.len;
	for (int i=a.len;i>=1;i--)
		if (a.num[i]<b.num[i])
			return true;
		else if (a.num[i]>b.num[i]) 
			return false;
	return false;
}
Bignum translate (ll x)
{
	Bignum a;
	while (x)
	{
		a.len++;
		a.num[a.len]=x%10;
		x/=10;
	}
	return a;
}
Bignum operator + (Bignum a,Bignum b)
{
	Bignum c;
	c.len=max(a.len,b.len);
	for (int i=1;i<=c.len;i++)
	{
		c.num[i]+=a.num[i]+b.num[i];
		if (c.num[i]>9)
		{
			c.num[i+1]+=c.num[i]/10;
			c.num[i]%=10;
		}
	}
	if (c.num[c.len+1]>0) c.len++;
	return c;
}
Bignum operator - (Bignum a,Bignum b)
{
	Bignum c;
	c.len=max(a.len,b.len);
	for (int i=1;i<=c.len;i++)
	{
		if (a.num[i]-b.num[i]<0)
		{
			a.num[i]+=10;
			a.num[i+1]--;
		}
		c.num[i]=a.num[i]-b.num[i];
	}
	if (c.num[c.len]==0) c.len--;
	return c;
}
Bignum operator * (Bignum a,Bignum b)
{
	Bignum c;
	c.len=a.len+b.len-1;
	for (int i=1;i<=a.len;i++)
		for (int j=1;j<=b.len;j++)
		{
			int pos=i+j-1;
			c.num[pos]+=a.num[i]*b.num[j];
			if (c.num[pos]>9)
			{
				c.num[pos+1]+=c.num[pos]/10;
				c.num[pos]%=10;
			}
		}
	if (c.num[c.len+1]>0)
	{
		c.num[c.len+1]+=c.num[c.len]/10;
		c.num[c.len]%=10;
		c.len++;
	}
	return c;
}
Bignum operator / (Bignum a,ll b)
{
	Bignum c;
	ll r=0;
	for (int i=a.len;i>=1;i--)
	{
		r=r*10+a.num[i];
		if (r>=b)
		{
			if (c.len==0) c.len=i;
			c.num[i]=r/b;
			r=r%b;
		}
	}
	return c;
}
struct Person
{
	Bignum l;
	ll r;
}p[MAXN];
bool cmp (Person a,Person b)
{
	Bignum r1=translate(a.r);
	Bignum r2=translate(b.r);
	return a.l*r1<b.l*r2;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
	{
		p[i].l.read();
		scanf("%lld",&p[i].r);
	}
	sort(p+1,p+1+n,cmp);
	Bignum mul=p[0].l;
	Bignum ans;
	for (int i=1;i<=n;i++)
	{
		Bignum tmp=mul/p[i].r;
		if (ans<tmp)
		{
			ans=tmp;
		}
		mul=mul*p[i].l;
	}
	ans.write();
}
