#include <cstdio>
#define MAXN 50001
using namespace std;
int head[MAXN],cnt_edge;
int n,val[MAXN];
struct EDGE{
	int next,to;
}edge[MAXN*2+5];
void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].next=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b); add(b,a);
	}
	for (int i=1;i<=n;i++)
		scanf("%d",&val[i]);
}
//DHOJ http://47.104.154.247/problem.php?cid=1091&pid=3
//POJ http://poj.org/problem?id=2152
