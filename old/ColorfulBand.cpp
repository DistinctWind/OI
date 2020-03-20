#include <cstdio>
#include <limits.h>
using namespace std;
const int MAXN=10000000;
struct POI{
	bool light[61];
	POI(){
		for (int i=0;i<=60;i++)
			light[i]=false;
	}
}poi[MAXN];
int n,k,len,ans=INT_MAX;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
	{
		int num;
		scanf("%d",&num);
		for (int j=1;j<=num;j++)
		{
			int temp=0;
			scanf("%d",&temp);
			poi[temp].light[i]=true;
			if (len<temp)
				len=temp;
		}
	}
	for (int i=1;i<=len;i++)
		for (int j=i;j<=len;j++)
		{
			bool find[61];
			for (int a=1;a<=k;a++)
				find[a]=false;
			for (int a=i;a<=j;a++)
				for (int b=1;b<=k;b++)
					if (poi[a].light[b]==true)
						find[b]=true;
			bool check=true;
			for (int a=1;a<=k;a++)
				if (find[a]==false)
					check=false;
			if (check)
				if (j-i<ans)
					ans=j-i;
		}
	printf("%d",ans);
}
