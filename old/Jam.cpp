#include <cstdio>
using namespace std;
const int MAXL=51;
int s,t,w,b,limit,num[MAXL];
char a[MAXL];
inline void print()
{
	for (int i=1;i<=w;i++)
		printf("%c",num[i]+'a'+s-1);
}
inline bool get_next()
{
	for (int i=w;i>=limit;i--)
		if (num[i]+1<b&&(i==w||num[i]+1<num[i+1]))
		{
			num[i]++;
			for (int j=i+1;j<=w;j++)
				num[j]=num[j-1]+1;
			return true;
		}
	return false;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&s,&t,&w);
	for (int i=1;i<=w;i++)
	{
		scanf(" %c",&a[i]);
		num[i]=a[i]-('a'+s-1);
	}
	b=t-s+1;
	limit=w-b<1?1:w-b;
	for (int i=1;i<=5;i++)
		if (get_next())
		{
			print();
			putchar('\n');
		}
		else break;
}
