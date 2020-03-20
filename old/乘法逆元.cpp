#include <cstdio>
using namespace std;
const int MAXN=3e6+10;
int n,p;
int inv[MAXN];
int exgcd(int a,int b,int &x,int &y)
{
	if (b==0)
	{
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int z=x;
	x=y,y=z-(a/b)*y;
	return d;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&p);
	inv[1]=1;
	for (int i=2;i<=n;i++)
		inv[i]=(long long)(p-(p/i))*inv[p%i]%p;
	for (int i=1;i<=n;i++)
		printf("%d\n",inv[i]);
}
