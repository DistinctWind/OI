/*#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXP 10001
using namespace std;
struct PRODUCTION{
	int num,a,b,m;
	void setup(int n){
		m=min(a,b);
		num=n;
	}
}p[MAXP];
int n,work[MAXP];
int a=0,b=0;
bool operator < (PRODUCTION a,PRODUCTION b)
{
	if (a.m==b.m)
		return a.num<b.num;
	else return a.m<b.m;
}
inline void read()
{
	freopen("in.txt","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>p[i].a;
	for (int i=1;i<=n;i++)
		cin>>p[i].b;
}
inline void solve()
{
	for (int i=1;i<=n;i++)
		p[i].setup(i);
	sort(p+1,p+1+n);
	int r=0,l=n+1;
	for (int i=1;i<=n&&r<=l;i++)
	{
		if (p[i].m==p[i].a)
		{
			r++;
			work[r]=p[i].num;
		}
		else if (p[i].m==p[i].b)
		{
			l--;
			work[l]=p[i].num;
		}
	}
	for (int i=1;i<=n;i++)
	{
		a+=p[work[i]].a;
		if (b<a) b=a;
		b+=p[work[i]].b;
	}
}
inline void out()
{
	cout<<b<<endl;
	cout<<work[1];
	for (int i=2;i<=n;i++)
		cout<<' '<<work[i];
}
int main()
{
	read();
	solve();
	out();
}*/
#include <iostream>
using namespace std;
int ans[10005],n,k,t;
int a[10005],b[10005],m[10005],s[10005];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i];
	for (int i=1;i<=n;i++)
	{
		m[i]=min(a[i],b[i]);
		s[i]=i;
	}
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
			if (m[i]>m[j])
			{
				swap(m[i],m[j]);
				swap(s[i],s[j]);
			}
	k=0,t=n+1;
	for (int i=1;i<=n;i++)
		if (m[i]==a[s[i]])
		{
			k++;
			ans[k]=s[i];
		}
		else{
			t--;
			ans[t]=s[i];
		}
	k=0,t=0;
	for (int i=1;i<=n;i++)
	{
		k+=a[ans[i]];
		if(t<k)t=k;
		t+=b[ans[i]];
	}
	cout<<t<<endl;
	for (int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
}
//DHOJ http://47.104.154.247/problem.php?cid=1095&pid=3
//LGOJ https://www.luogu.org/fe/problem/P1248
// LOJ https://loj.ac/problem/10003
