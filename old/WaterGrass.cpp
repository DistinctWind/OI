#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXP=100001;
int x,n,l,w,cnt,ans;
struct P{
	double a,b;
	P(){
		a=b=0;
	}
};
bool cmp(P a,P b)
{
	return a.a<b.a;
}
inline void setup()
{
	n=l=w=cnt=0;
	ans=0;
}
int main()
{
	freopen("in.txt","r",stdin);
	cin>>x;
	for (int k=1;k<=x;k++)
	{
		setup();
		P p[MAXP];
		cin>>n>>l>>w;
		for (int j=1;j<=n;j++)
		{
			int a,b;
			cin>>a>>b;
			if (b<=w/2.0) continue;
			cnt++;
			p[cnt].a=(double)a-sqrt(b*b-w*w/4.0);
			p[cnt].b=(double)a+sqrt(b*b-w*w/4.0);
		}
		sort(p+1,p+1+n,cmp);
		double t=0;
		int i=1;
		bool ok=true;
		while (t<l)
		{
			ans++;
			double s=t;
			for (;p[i].a<=s&&i<=n;i++)
				if (t<p[i].b)
					t=p[i].b;
			if (t==s&&s<l)
			{
				ok=false;
				cout<<-1<<endl;
				break;
			}
		}
		if (ok) cout<<ans<<endl;
	}
}
