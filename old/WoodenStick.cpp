#include <cstdio>
#define MAXN 66
using namespace std;
int w[MAXN],cnt,sum,maxl=-1e9,minl=1e9;
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a>b?b:a;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if (temp<=50)
			cnt++,w[cnt]=temp,sum+=temp;
	}
	for (int d=1;sum/d>=&&(sum%d==0))
}
