#include <cstdio>
using namespace std;
int cntEdge,nxt[MAXN],ver[MAXN],head[MAXN];
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
int main()
{
	
} 
