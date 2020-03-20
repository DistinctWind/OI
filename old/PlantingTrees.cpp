#include <cstdio>
#include <algorithm>
#define MAXH 5001
#define MAXN 30001
using namespace std;
int n,h,cnt,ans;
bool plant[MAXN];
struct Person{
    int b,e,t;
}p[MAXH];
bool operator < (Person a,Person b)
{
    return a.e<b.e;
}
int main()
{
	scanf("%d%d",&n,&h);
    for (int i=1;i<=h;i++)
    {
        cnt++;
        scanf("%d%d%d",&p[cnt].b,&p[cnt].e,&p[cnt].t);
    }
    sort(p+1,p+1+h);
    for (int i=1;i<=h;i++)
    {
    	int ped=0;
    	for (int j=p[i].b;j<=p[i].e;j++)
    		ped+=plant[j]?1:0;
    	if (ped>=p[i].t)
    		continue;
    	for (int j=p[i].e;j>=p[i].b;j--)
    		if (ped<p[i].t&&!plant[j])
    		{
    			ans++;
    			plant[j]=true;
    			ped++;
    			if (ped==p[i].t)
    				break;
    		}
    }
    printf("%d",ans);
}
