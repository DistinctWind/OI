#include <cstdio>
#include <cstring>
using namespace std;
const int p=99991;
const int MAXN=100001;
int n,tot;
int snow[MAXN][6],head[p],nxt[MAXN];
int h(int *tmp)
{
	int sum=0,mul=1;
	for (int i=0;i<6;i++)
	{
		sum=(sum+tmp[i])%p;
		mul=(long long)mul*tmp[i]%p;
	}
	return (sum+mul)%p;
}
bool equal(int *a,int *b)
{
	for (int i=0;i<6;i++)
	{
		for (int j=0;j<6;j++)
		{
			bool eq=true;
			for (int k=0;k<6;k++)
				if (a[(i+k)%6]!=b[(j+k)%6])
					eq=false;
			if (eq) return true;
			eq=true;
			for (int k=0;k<6;k++)
				if (a[(i+k)%6]!=b[(j-k+6)%6])
					eq=false;
			if (eq) return true;
		}
	}
	return false;
}
bool insert(int *tmp)
{
	int val=h(tmp);
	for (int i=head[val];i;i=nxt[i])
		if (equal(snow[i],tmp)) return true;
	tot++;
	memcpy(snow[tot],tmp,6*sizeof(int));
	nxt[tot]=head[val];
	head[val]=tot;
	return false;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int tmp[6];
		for (int j=0;j<6;j++)
			scanf("%d",&tmp[j]);
		if (insert(tmp))
		{
			printf("Twin snowflakes found.\n");
			return 0;
		}
	}
	printf("No two snowflakes are alike.\n");
}

