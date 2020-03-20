#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=1e6+1;
int n,q;
long long addsum[MAXN*4];
int read()
{
	int x=0,k=1;
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
	return k*x;
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
void modify(int k,int l,int r,int x,int y,int v)
{
	if (r<x||l>y) return;
	if (x<=l&&r<=y)
	{
		addsum[k]+=v;
		return;
	}
	int mid=l+r>>1;
	modify(k*2,l,mid,x,y,v);
	modify(k*2+1,mid+1,r,x,y,v);
}
long long query(int k,int l,int r,int p)
{
	if (l==r) return addsum[k];
	int mid=l+r>>1;
	if (p<=mid) return query(k*2,l,mid,p)+addsum[k];
	else return query(k*2+1,mid+1,r,p)+addsum[k];
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); q=read();
	for (int i=1;i<=n;i++)
	{
		int tmp=read();
		modify(1,1,n,i,i,tmp);
	}
	for (int i=1;i<=q;i++)
	{
		int k=read();
		if (k==1)
		{
			int l=read(),r=read(),x=read();
			modify(1,1,n,l,r,x);
		}
		else if (k==2)
		{
			int p=read();
			write(query(1,1,n,p));
			putchar('\n');
		}
	}
}
//LGOJ https://www.luogu.org/problem/P3368
