#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=10001;
const int MAXL=1000001;
const int p=6024115;
unsigned long long pow[MAXN],sum[MAXL];
int t;
char s1[MAXN],s2[MAXL];
int main()
{
	scanf("%d",&t);
	pow[0]=1;
	for (int i=1;i<=10000;i++)
		pow[i]=pow[i-1]*p;
	while (t--)
	{
		scanf(" %s %s",s1+1,s2+1);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		sum[0]=0;
		for (int i=1;i<=len2;i++)
			sum[i]=sum[i-1]*p+(unsigned long long)(s2[i]-'A'+1);
		unsigned long long res=0;
		for (int i=1;i<=len1;i++)
			res=res*p+(unsigned long long)(s1[i]-'A'+1);
		int ans=0;
		for (int i=0;i<=len2-len1;i++)
			if (res==sum[i+len1]-sum[i]*pow[len1]) ans++;
		printf("%d\n",ans);
	}
}
