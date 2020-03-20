#include <cstdio>
#define MAXN 4196
using namespace std;
struct LINE{
	state sit[MAXN];
	int tot;
}line[MAXN];
struct state{
	int s[6];
};
int n,m;
int lock;
inline void dp()
{
	
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&lock);
	for (int i=1;i<=m;i++)
		scanf("%d",line[lock].s[i]);
	dp();
}
