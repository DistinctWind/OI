#include <cstdio>
#include <algorithm>
#define MAXN 20001
using namespace std;
int n,k,e[11];
struct Person{
	int id,w;
}p[MAXN];
bool cmp(Person a,Person b)
{
	if (a.w==b.w)
		return a.id<b.id;
	return a.w>b.w;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=10;i++)
		scanf("%d",&e[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i].w);
		p[i].id=i;
	}
	sort(p+1,p+1+n,cmp);
	for (int i=1;i<=n;i++)
		p[i].w+=e[(i-1)%10+1];
	sort(p+1,p+1+n,cmp);
	for (int i=1;i<=k;i++)
		printf("%d ",p[i].id);
}
