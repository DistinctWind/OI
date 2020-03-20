#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN=3e5+10;
int n,m,q,mxr;
int cnt,data[MAXN*20],lson[MAXN*20],rson[MAXN*20];
vector<ll> etc[MAXN+1];
inline int read()
{
	int x=0; char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
void modify(int &k,int l,int r,int pos)
{
	if (!k) k=++cnt;
	data[k]++;
	if (l==r) return;
	int mid=l+r>>1;
	if (pos<=mid) modify(lson[k],l,mid,pos);
	else modify(rson[k],mid+1,r,pos); 
}
ll query(int k,int l,int r,int pos)
{
	if (l==r) return l;
	int mid=l+r>>1,delta=mid-l+1-data[lson[k]];
	if (pos<=delta) return query(lson[k],l,mid,pos);
	else return query(rson[k],mid+1,r,pos-delta);
}
int root[MAXN],rootLstCol;
ll del(int x,int y)
{
	int pos=query(root[x],1,mxr,y);
	modify(root[x],1,mxr,pos);
	if (pos<=m-1) return (ll)(x-1)*m+pos;
	else return etc[x][pos-m];
}
ll delLstCol(int x)
{
	int pos=query(rootLstCol,1,mxr,x);
	modify(rootLstCol,1,mxr,pos);
	if (pos<=n) return (ll)m*pos;
	else return etc[n+1][pos-n-1];
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); m=read(); q=read();
	mxr=max(n,m)+q;
	while (q--)
	{
		int x=read(),y=read();
		if (y==m)
		{
			ll ans=delLstCol(x);
			etc[n+1].push_back(ans);
			printf("%lld\n",ans);
		}
		else
		{
			ll ans1=del(x,y);
			ll ans2=delLstCol(x);
			etc[n+1].push_back(ans1);
			etc[x].push_back(ans2);
			printf("%lld\n",ans1);
		}
	}
}
