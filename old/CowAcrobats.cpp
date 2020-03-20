#include <cstdio>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
const int MAXN=5e4+1;
struct Cow{
	int s,w;
	inline void get(){
		scanf("%d%d",&w,&s);
	}
	friend bool operator < (Cow a,Cow b){
		return a.s+a.w>b.s+b.w;
	}
}c[MAXN];
int n,sum[MAXN],tmp=INT_MAX;
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		c[i].get();
	sort(c+1,c+1+n);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+c[i].w;
		tmp=min(sum[i]+c[i].s,tmp);
	}
	printf("%d",sum[n]-tmp);
}
