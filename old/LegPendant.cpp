#include <cstdio>
using namespace std;
const int LOGN=30;
const int MAXN=200010;
int n,q;
int tot,root[MAXN];
struct Trie{
	int ch[2],cnt;
}trie[MAXN*(LOGN+1)];
void modify(int &p,int x,int dep)
{
	int last=p;
	trie[p=++tot]=trie[last];
	trie[p].cnt++;
	if (dep==-1) return;
	int o=(x>>dep)&1;
	modify(trie[p].ch[o],x,dep-1);
}
int query(int rtl,int rtr,int x,int dep)
{
	if (dep==-1) return 0;
	int o=(x>>dep)&1;
	if (trie[trie[rtl].ch[o^1]].cnt<trie[trie[rtr].ch[o^1]].cnt)
		return query(trie[rtl].ch[o^1],trie[rtr].ch[o^1],x,dep-1)|(1<<dep);
	else 
		return query(trie[rtl].ch[o],trie[rtr].ch[o],x,dep-1);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		root[i]=root[i-1];
		modify(root[i],x,LOGN-1);
	}
	for (int i=1,x,l,r;i<=q;i++)
	{
		scanf("%d%d%d",&x,&l,&r);
		printf("%d\n",query(root[l],root[r+1],x,LOGN-1));
	}
}
