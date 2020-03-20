#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=10001;
int heap[MAXN],n,tot,ans;
inline void up(int p)
{
	while (p>1)
	{
		if (heap[p]<heap[p>>1])
		{
			swap(heap[p],heap[p>>1]);
			p>>=1;
		}
		else break;
	}
}
inline void down(int p)
{
	int s=p<<1;
	while (s<=tot)
	{
		if (s<n&&heap[s]>heap[s+1]) s++;
		if (heap[s]<heap[p]) swap(heap[s],heap[p]);
		p=s; s=p<<1;
	}
}
inline void insert(int val)
{
	heap[++tot]=val;
	up(tot);
}
int gettop()
{
	return heap[1];
}
inline void extract()
{
	heap[1]=heap[tot--];
	down(1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		insert(tmp);
	}
	while (tot>1)
	{
		int a,b;
		a=gettop(); extract();
		b=gettop(); extract();
		insert(a+b);
		ans=ans+a+b;
	}
	printf("%d",ans);
}
