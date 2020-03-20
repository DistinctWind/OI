#include <cstdio>
#include <set>
#include <queue>
#include <iostream>
using namespace std;
const int MAXN=10010;
const int MAXM=1010;
int n,m,k,mp;
int u[MAXN],d[MAXN];
bool check[MAXN],ip[MAXN];
set <int> able[MAXN];
struct State{
	int x,y,c,f;
};
bool operator < (State a,State b)
{
	return a.c>b.c;
}
inline void bfs()
{
	priority_queue <State> q;
	State start;
	if (check[0])
	{
		mp=1;
		for (set<int>::iterator i=able[0].begin();i!=able[0].end();i++)
		{
			start.x=0,start.y=*i;
			start.c=0,start.f=0;
			q.push(start);
		}
	}
	else
	{
		for (int i=1;i<=m;i++)
		{
			start.x=0,start.y=i;
			start.c=0,start.f=0;
			q.push(start);
		}
	}
	while (!q.empty())
	{
		State h=q.top(); q.pop();
		//print(h);
		if (h.x==n)
		{
			printf("1\n%d",h.c);
			return;
		}
		for (int i=0;;i++)
		{
			if (check[h.x])
			{
				if (able[h.x].count(h.y)==0) break;
				if (i==0)
				{
					State tmp;
					tmp.x=h.x+1,tmp.y=h.y-d[h.x];
					tmp.c=h.c,tmp.f=h.f+(ip[tmp.x]?1:0);
					mp=max(mp,tmp.f);
					if (tmp.y<=0) continue;
					q.push(tmp);
					//print(tmp,h);
				}
				else
				{
					State tmp;
					tmp.x=h.x+1,tmp.y=h.y+i*u[h.x];
					tmp.c=h.c+i,tmp.f=h.f+(ip[tmp.x]?1:0);
					mp=max(mp,tmp.f);
					if (tmp.y>m)
					{
						tmp.y=m;
						q.push(tmp);
						break;
					}
					q.push(tmp);
					//print(tmp,h);
				}
			}
			else
			{
				if (i==0)
				{
					State tmp;
					tmp.x=h.x+1,tmp.y=h.y-d[h.x];
					tmp.c=h.c,tmp.f=h.f;
					if (tmp.y<=0) continue;
					q.push(tmp);
					//print(tmp,h);
				}
				else
				{
					State tmp;
					tmp.x=h.x+1,tmp.y=h.y+i*u[h.x];
					tmp.c=h.c+i,tmp.f=h.f;
					if (tmp.y>m)
					{
						tmp.y=m;
						q.push(tmp);
						break;
					}
					q.push(tmp);
					//print(tmp,h);
				}
			}
		}
	}
	printf("0\n%d",mp);
}
int main()
{
	//freopen("bird.in","r",stdin);
	//freopen("bird.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++)
		scanf("%d%d",&u[i],&d[i]);
	for (int i=1,p,l,h;i<=k;i++)
	{
		scanf("%d%d%d",&p,&l,&h);
		check[p-1]=true; check[p]=true; ip[p]=true;
		for (int j=l+1;j<h;j++)
		{
			able[p].insert(j);
			if (j+d[p-1]>m) able[p-1].insert(m);
			else able[p-1].insert(j+d[p-1]);
			for (int k=1;k*u[p-1]<j;k++)
				able[p-1].insert(j-k*u[p-1]);
		}
	}
	/*for (int i=0;i<n;i++)
	{
		if (check[i])
		{
			printf("%d:\n",i);
			for (set<int>::iterator j=able[i].begin();j!=able[i].end();j++)
				printf("%d ",*j);
			putchar('\n');
		}
	}*/
	bfs();
}
