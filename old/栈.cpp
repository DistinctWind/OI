#include <cstdio>
using namespace std;
const int MAXN=20;
typedef long long ll;
int n;
ll c[MAXN<<1];
int main()
{
	scanf("%d",&n);
	c[0]=c[1]=1;
	for (int i=2;i<=n;i++)
		for (int j=0;j<i;j++)
			c[i]+=c[j]*c[i-j-1]; 
	printf("%lld",c[n]);
} 
