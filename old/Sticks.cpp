#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int MAXN=101;
int cnt,sum,a[MAXN],nxt[MAXN],used[MAXN],n,m,len;
bool ok;
void dfs(int k,int last,int rest)
{
	if (rest==0)
	{
		if (k==m)
		{
			ok=true;
			return;
		}
		int i;
		for (i=1;i<=cnt;i++)
			if (!used[i])
				break;
		used[i]=true;
		dfs(k+1,i,len-a[i]);
		used[i]=false;
		if (ok) return;
	}
	int l=last+1,r=cnt;
	while (l<r)
	{
		int mid=l+r>>1;
		if (a[mid]<=rest) r=mid;
		else l=mid+1;
	}
	for (int i=l;i<=cnt;i++)
	{
		if (!used[i])
		{
			used[i]=1;
			dfs(k,i,rest-a[i]);
			used[i]=0;
			if (ok) return;
			if(rest==a[i]) return;
			i=nxt[i];
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if (tmp>50) continue;
		a[++cnt]=tmp;
		sum+=tmp;
	}
	sort(a+1,a+1+cnt,greater<int>());
	nxt[cnt]=cnt;
	for (int i=cnt-1;i>=1;i--)
	{
		if (a[i]==a[i+1]) nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
	for (len=a[1];len<=sum/2;len++)
	{
		if (sum%len!=0) continue;
		m=sum/len;
		used[1]=1;
		dfs(1,1,len-a[1]);
		used[1]=0;
		if (ok)
		{
			printf("%d",len);
			return 0;
		}
	}
	printf("%d",sum);
}
