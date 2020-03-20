#include <cstdio>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
const int MAXN=5e4+1;
int min(int a,int b)
{
	return a<b?a:b;
}
struct cow{
	int start,end;
	inline void get()
	{
		scanf("%d%d",&start,&end);
	}
	friend bool operator < (cow a,cow b)
	{
		if (a.start!=b.start) return a.start<b.start;
		else return a.end<b.end;
	}
}c[MAXN];
struct stall{
	int num,last;
	friend bool operator < (stall a,stall b)
	{
		return a.last>b.last;
	}
};
int n,cnt;
priority_queue <int,vector<int>,greater<int> > q;
int main()
{
	//freopen("in(1).txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		c[i].get();
	sort(c+1,c+1+n);
	cnt=1; q.push(c[1].end);
	for (int i=2;i<=n;i++)
	{
		if (c[i].start<=q.top())
		{
			//printf("New thanks to (%d,%d)\n",c[i].start,q.top());
			cnt++;
		}
		else
		{
			q.pop();
		}
		q.push(c[i].end);
	}
	printf("%d",cnt);
}
//DHOJ http://47.104.154.247/problem.php?cid=1115&pid=1
