#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN=1e6+1;
int rand_between(int l,int r)
{
	return rand()%(r-l+1)+l;
}
struct Random{
	int n,q,cnt,num[MAXN],ans[MAXN];
	inline void rebuild()
	{
		srand((unsigned int)time(0));
	}
	inline void setup()
	{
		n=q=cnt=0;
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
	}
	inline void build()
	{
		freopen("in.txt","w",stdout);
		n=rand_between(1,5); q=rand_between(1,5);
		printf("%d %d\n",n,q);
		for (int i=1;i<=n;i++)
		{
			num[i]=rand_between(-10,10);
			printf("%d ",num[i]);
		}
		putchar('\n');
		for (int i=1;i<=q;i++)
		{
			int k=rand_between(1,2);
			if (k==1)
			{
				int l=rand_between(1,n);
				int r=rand_between(l,n);
				int x=rand_between(-10,10);
				printf("%d %d %d %d\n",k,l,r,x);
				for (int j=l;j<=r;j++)
					num[i]+=x;
			}
			else if (k==2)
			{
				int l=rand_between(1,n);
				int r=rand_between(l,n);
				int res=0;
				printf("%d %d %d\n",k,l,r);
				for (int j=l;j<=r;j++)
					res+=num[i];
				ans[++cnt]=res;
			}
		}
		fclose(stdout);
		freopen("ans.txt","w",stdout);
		for (int i=1;i<=cnt;i++)
			printf("%d\n",ans[i]);
		fclose(stdout);
	}
}r;
int main()
{
	r.rebuild();
	while (true)
	{
		clock_t start,end;
		r.setup();
		r.build();
		start=clock();
		system("SumIII.exe");
		end=clock();
		if (system("fc ans.txt out.txt")==0)
		{
			printf("Accepted in %.3lf\n",(double)(end-start)/CLOCKS_PER_SEC);
		}
		else
		{
			printf("Wrong Answer");
			break;
		}
	}
}
