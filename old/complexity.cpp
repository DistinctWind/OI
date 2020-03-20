#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <stack>
using namespace std;
int t,L,hn,md;
string h,now,nam,l,r;
bool err;
struct Layer{
	string x;
	int depth;
};
map<string,bool> used;
stack<Layer> s;
inline void setup()
{
	hn=-1;
	md=0;
	err=false;
	while (!s.empty()) s.pop();
	used.clear();
}
int main()
{
	freopen("complexity.in","r",stdin);
	freopen("complexity.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		setup();
		scanf("%d",&L);
		cin>>h;
		if (h.size()==4) hn=0;
		else
		{
			int pos=4; hn=0;
			while ('0'<=h[pos]&&h[pos]<='9') hn=hn*10+h[pos]-'0',pos++;
		}
		for (int i=1;i<=L;i++)
		{
			cin>>now;
			if (now[0]=='E')
			{
				if (s.empty()) err=true;
				else
				{
					used[s.top().x]=false;
					s.pop();
				}
			}
			else
			{
				cin>>nam>>l>>r;
				if (used[nam]) err=true;
				used[nam]=true;
				Layer tmp;
				tmp.x=nam;
				if (!s.empty()&&s.top().depth==-1) tmp.depth=-1;
				else if (r[0]=='n') tmp.depth=(s.empty()?1:s.top().depth+1);
				else if (l[0]=='n') tmp.depth=-1;
				else tmp.depth=(s.empty()?0:s.top().depth);
				s.push(tmp);
				md=max(md,tmp.depth);
			}
		}
		if (!s.empty()) err=true;
		if (err) printf("ERR\n");
		else
		{
			if (md==hn) printf("Yes\n");
			else printf("No\n");
		}
	}
}
