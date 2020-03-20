#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
const int MAXN=1e5+1;
const int MAXM=5e5+1;
int n,m,cnt;
int a[MAXN],ans[MAXM];
int rand_between(int a,int b)
{
	return (rand()%(b-a+1))+a;
}
int main()
{
	unsigned int seed=time(0);
	srand(seed);
	freopen("in.txt","w",stdout);
	n=rand_between(1,MAXN); m=rand_between(1,MAXM);
	printf("%d %d\n",n,m);
	for (int i=1;i<=m;i++)
	{
		int k=rand_between(1,2);
		if (k==1)
		{
			int l=rand_between(1,n);
			int r=rand_between(l,n);
			printf("%d %d %d\n",k,l,r);
			for (int i=l;i<=r;i++)
				a[i]=!a[i];
		}
		else if (k==2)
		{
			int pos=rand_between(1,n);
			printf("%d %d\n",k,pos);
			ans[++cnt]=a[pos];
		}
	}
	fclose(stdout);
	freopen("ans.txt","w",stdout);
	for (int i=1;i<=cnt;i++)
		printf("%d\n",ans[i]);
}
