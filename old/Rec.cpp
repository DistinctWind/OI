#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int MAXN=5e5+10;
int n,m,w,l;
long long ans;
struct Rec{
	int x1,x2,y1,y2;
}rec[MAXN];
vector <Rec> c2,cro;
int read()
{
	int x=0;
	char a=getchar(); 
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
bool cmpx(Rec a,Rec b)
{
	if (a.x1==b.x1) return a.y1<b.y1;
	else return a.x1<b.x1;
}
bool cmpy(Rec a,Rec b)
{
	if (a.y1==b.y1) return a.x1<b.x1;
	else return a.y1<b.y1;
}
int queryx(int x)
{
	int l=1,r=n,res;
	int mid=l+r>>1;
	while (l<=r)
	{
		mid=l+r>>1;
		if (rec[mid].x1<x) res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}
int queryy(int y)
{
	int l=0,r=c2.size()-1,res;
	int mid=l+r>>1;
	while (l<=r)
	{
		mid=l+r>>1;
		if (c2[mid].y1<y) res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}
long long calc(Rec a,Rec b)
{
	long long crox,croy;
	crox=min(a.x2,b.x2)-max(a.x1,b.x1);
	croy=min(a.y2,b.y2)-max(a.y1,b.y1);
	if (crox<0||croy<0) return 0;
	else return crox*croy;
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); m=read(); w=read(); l=read();
	for (int i=1;i<=n;i++)
		rec[i].x1=read(),rec[i].y1=read(),rec[i].x2=read(),rec[i].y2=read();
	sort(rec+1,rec+1+n,cmpx);
	Rec now;
	for (int i=1,sx,ex,sy,ey;i<=m;i++)
	{
		now.x1=read(); now.y1=read(); now.x2=read(); now.y2=read();
		c2.clear(); cro.clear(); ans=0;
		sx=queryx(now.x2);
		for (ex=sx;ex<=n;ex++)
		{
			if (rec[ex].x1<now.x2) c2.push_back(rec[ex]);
			else {ex--; break;}
		}
		sort(c2.begin(),c2.end(),cmpy);
		sy=queryy(now.y2);
		for (ey=sy;ey<=n;ey++)
		{
			if (rec[ey].y1<now.y2) cro.push_back(rec[ey]);
			else{ey--; break;}
		}
		for (vector<Rec>::iterator i=cro.begin();i!=cro.end();i++)
			ans+=calc(now,*i);
		printf("%lld\n",ans);
	}
}
