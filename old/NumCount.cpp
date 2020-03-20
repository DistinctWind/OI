#include <cstdio>
#define MAXN 15
using namespace std;
long long a,b;
long long cnt1[MAXN],cnt2[MAXN];
long long ten[MAXN],f[MAXN];
inline void setup()
{
	ten[0]=1;
	for (int i=1;i<=14;i++)
	{
		ten[i]=ten[i-1]*10;
		f[i]=f[i-1]*10+ten[i-1];
	}
}
void solve(long long x,long long *cnt)
{
	long long num[MAXN]={0};
	int len=0;
	while (x!=0)
		num[++len]=x%10,x/=10;
	for (int i=len;i>=1;i--)
	{
		for (int j=0;j<=9;j++)
			cnt[j]+=f[i-1]*num[i];
		for (int j=0;j<num[i];j++)
			cnt[j]+=ten[i-1];
		long long temp=0;
		for (int j=i-1;j>=1;j--)
			temp=temp*10+num[j];
		cnt[num[i]]+=temp+1;
		cnt[0]-=ten[i-1];
	}
}
int main()
{
	scanf("%lld%lld",&a,&b);
	setup();
	solve(a-1,cnt1);
	solve(b,cnt2);
	for (int i=0;i<=9;i++)
		printf("%lld ",cnt2[i]-cnt1[i]);
}
/*
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int f[100];
int pow(int a,int x)
{
	if (x!=0) return pow(a,x-1)*a;
	else return 1;
}
int main()
{
	for (int i=1;i<=9;i++)
		f[i]=f[i-1]*10+pow(10,i-1);
	for (int i=1;i<=9;i++)
		cout<<f[i]<<endl;
}
/*const int MAXP=20;
int num1[MAXP],num2[MAXP];
ll a,b,f1[MAXP][10],f2[MAXP][10];
ll dfs1(int pos,int aim,bool pre_zero,bool limit)
{
	if (pos==-1) return 1;
	if (!limit&&f1[pos][aim]!=-1) return f1[pos][aim];
	int up=limit?num1[pos]:9;
	int res=0;
	for (int i=0;i<=up;i++)
		res+=dfs1(pos-1,aim,pre_zero&&i==0,limit&&i==up);
	if (!limit) f1[pos][aim]=res;
	return res;
}
ll dfs2(int pos,int aim,bool pre_zero,bool limit)
{
	if (pos==-1) return 1;
	if (!limit&&f2[pos][aim]!=-1) return f2[pos][aim];
	int up=limit?num2[pos]:9;
	int res=0;
	for (int i=0;i<=up;i++)
		res+=dfs2(pos-1,aim,pre_zero&&i==0,limit&&i==up);
	if (!limit) f2[pos][aim]=res;
	return res;
}
inline void solve()
{
	int pos1=0,pos2=0;
	memset(f1,-1,sizeof(f1));
	memset(f2,-1,sizeof(f2));
	while (a!=0)
		num1[pos1++]=a%10,a/=10;
	while (b!=0)
		num2[pos2++]=b%10,b/=10;
	for (int i=0;i<=9;i++)
		f1[pos1][i]=dfs1(pos1-1,i,true,true);
	for (int i=0;i<=9;i++)
		f2[pos2][i]=dfs2(pos2-1,i,true,true);
	for (int i=0;i<=9;i++)
		cout<<f2[pos2][i]-f1[pos1][i]<<' ';
}
int main()
{
	cin>>a>>b;
	solve();
}*/
//LOJ https://loj.ac/problem/10169
//LGOJ https://www.luogu.org/problemnew/show/P2602
