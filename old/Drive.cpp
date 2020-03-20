#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100010;
const int LOGN=20;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m1[MAXN],m2[MAXN];
int f[MAXN][LOGN];
ll h[MAXN],suma[MAXN][LOGN],sumb[MAXN][LOGN];
ll a[MAXN],b[MAXN];
map <ll,int> mp;
struct Node{
	ll h,ab;
}t[5];
bool cmp(Node a,Node b)
{
	if (a.ab==b.ab) return a.h<b.h;
	else return a.ab<b.ab;
}
inline void setup()
{
	set <ll> s;
	s.insert(-inf-1); s.insert(-inf); s.insert(inf); s.insert(inf+1);
	for (int i=n;i>=1;i--)
	{
		s.insert(h[i]);
		t[2].h=*--s.lower_bound(h[i]);
		t[1].h=*--s.lower_bound(t[2].h);
		t[3].h=*s.upper_bound(h[i]);
		t[4].h=*s.upper_bound(t[3].h);
		for (int j=1;j<=4;j++)
			t[j].ab=abs(t[j].h-h[i]);
		sort(t+1,t+1+4,cmp);
		a[i]=t[2].ab; m1[i]=mp[t[2].h];
		b[i]=t[1].ab; m2[i]=mp[t[1].h];
		if (m1[i]) suma[i][0]=t[2].ab,f[i][0]=m1[i];
		if (m2[m1[i]]) suma[i][1]=t[2].ab,sumb[i][1]=b[m1[i]],f[i][1]=m2[m1[i]];
		for (int k=2;k<LOGN;k++)
		{
			if (f[f[i][k-1]][k-1])
			{
				f[i][k]=f[f[i][k-1]][k-1];
				suma[i][k]=suma[i][k-1]+suma[f[i][k-1]][k-1];
				sumb[i][k]=sumb[i][k-1]+sumb[f[i][k-1]][k-1];
			}
			else break;
		}
	}
}
double ask1(int x,ll p)
{
	ll sum1=0,sum2=0;
	for (int i=LOGN-1;i>=0;i--)
	{
		if (f[x][i]&&sum1+sum2+suma[x][i]+sumb[x][i]<=p)
		{
			sum1+=suma[x][i];
			sum2+=sumb[x][i];
			x=f[x][i];
		}
	}
	return (sum2==0?inf:(double)sum1/(double)sum2);
}
void ask2(int x,ll p)
{
	ll sum1=0,sum2=0;
	for (int i=LOGN-1;i>=0;i--)
	{
		if (f[x][i]&&sum1+sum2+suma[x][i]+sumb[x][i]<=p)
		{
			sum1+=suma[x][i];
			sum2+=sumb[x][i];
			x=f[x][i];
		}
	}
	if (m1[x]&&sum1+sum2+suma[x][0]<=p) sum1+=suma[x][0];
	printf("%lld %lld\n",sum1,sum2);
}
inline void solve()
{
	double minn=inf;;
	int pos;
	ll x0;
	scanf("%lld",&x0);
	for (int i=1;i<=n;i++)
	{
		double now=ask1(i,x0);
		if (now<minn) minn=now,pos=i;
	}
	printf("%d\n",pos);
	int m;
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x; ll p;
		scanf("%d%lld",&x,&p);
		ask2(x,p);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&h[i]),mp[h[i]]=i;
	setup();
	solve();
}
