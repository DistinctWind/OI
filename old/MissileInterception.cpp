#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int MAXN=100001;
int n,h[MAXN];
int ans,len1,len2,s1[MAXN],s2[MAXN];
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d",&h[n+1])!=EOF)
		n++;
	s1[1]=s2[1]=h[1]; len1=len2=1;
	for (int i=2;i<=n;i++)
	{
		if (h[i]<=s1[len1])
			s1[++len1]=h[i];
		else
		{
			int p=upper_bound(s1+1,s1+1+len1,h[i],greater<int>())-s1;
			s1[p]=h[i];
		}
		if (h[i]>s2[len2])
			s2[++len2]=h[i];
		else
		{
			int p=lower_bound(s2+1,s2+1+len2,h[i])-s2;
			s2[p]=h[i];
		}
	}
	printf("%d %d",len1,len2);
}
