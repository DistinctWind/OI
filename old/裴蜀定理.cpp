#include <cstdio>
using namespace std;
const int MAXN=21;
int n,a[MAXN],ans;
int gcd(int a,int b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]=(a[i]<0?-a[i]:a[i]);
	ans=a[1];
	for (int i=2;i<=n;i++)
		ans=gcd(ans,a[i]);
	printf("%d",ans);
}
