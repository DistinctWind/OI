#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN=1001;
const int MAXP=10001;
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
struct Edge{
	int nxt,to,dis;
}edge[MAXP*2];
struct Poi{
	int dep,pos;
	bool operator < (const Poi &a) const{
		return dep<a.dep;
	}
};
int cnt_edge,head[MAXN],f[MAXP][MAXN];
bool iq[MAXP][MAXN];
int n,p,k;
inline void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
inline void spfa()
{
	queue <pair<int,int> > q;
	q.push(make_pair(0,1));
	memset(f,0x3f,sizeof(f));
	f[0][1]=0;
	while (!q.empty())
	{
		pair<int,int> front=q.front(); q.pop();
		iq[front.first][front.second]=false;
		for (int i=head[front.second];i;i=edge[i].nxt)
		{
			if (f[front.first][edge[i].to]>max(f[front.first][front.second],edge[i].dis))
			{
				f[front.first][edge[i].to]=max(f[front.first][front.second],edge[i].dis);
				if (!iq[front.first][edge[i].to])
				{
					q.push(make_pair(front.first,edge[i].to));
					iq[front.first][edge[i].to]=true;
				}
			}
			if (front.first+1<=k)
			{
				if (f[front.first+1][edge[i].to]>f[front.first][front.second])
				{
					f[front.first+1][edge[i].to]=f[front.first][front.second];
					if (!iq[front.first+1][edge[i].to])
					{
						iq[front.first+1][edge[i].to]=true;
						q.push(make_pair(front.first+1,edge[i].to));
					}
				}
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&p,&k);
	for (int i=1;i<=p;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		add(a,b,dis); add(b,a,dis);
	}
	spfa();
	if (f[k][n]==0x3f3f3f3f) printf("-1");
	else printf("%d\n",f[k][n]);
}
