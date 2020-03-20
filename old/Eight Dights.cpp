#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
using namespace std;
const int ans[3][3]={{1,2,3},{8,0,4},{7,6,5}};
const int mov_x[5]={0,0,1,0,-1};
const int mov_y[5]={0,-1,0,1,0};
int n;
int bac[3][3];
set <int> go;
struct state{
	int num,zero_x,zero_y,step,close,a_ster;
	bool operator < (const state &a) const{
		return a.step<step;
	}
};
void back(int num)
{
	for (int y=2;y>=0;y--)
		for (int x=2;x>=0;x--)
		{
			bac[y][x]=num%10;
			num/=10;
		}
}
int abstract()
{
	int ans=0;
	for (int y=0;y<=2;y++)
		for (int x=0;x<=2;x++)
		{
			ans*=10;
			ans+=bac[y][x];
		}
	return ans;
}
int judge(int num)
{
	int temp=0;
	back(num);
	for (int y=0;y<=2;y++)
		for (int x=0;x<=2;x++)
			if (bac[y][x]!=ans[y][x])
				temp++;
	return temp;
}
int bfs()
{
	priority_queue <state> q;
	state start;
	start.num=n;
	back(start.num);
	for (int y=0;y<=2;y++)
		for (int x=0;x<=2;x++)
			if (bac[y][x]==0)
			{
				start.zero_x=x;
				start.zero_y=y;
				break;
			}
	start.close=judge(start.num);
	start.step=0;
	start.a_ster=start.close+start.step;
	go.insert(start.num);
	q.push(start);
	while (!q.empty())
	{
		state head;
		head=q.top();
		q.pop();
		back(head.num);
		if (head.close==0)
			return head.step;
		for (int i=1;i<=4;i++)
		{
			int now_x=head.zero_x+mov_x[i];
			int now_y=head.zero_y+mov_y[i];
			if (!(0<=now_x&&now_x<=2&&0<=now_y&&now_y<=2))
				continue;
			swap(bac[now_y][now_x],bac[head.zero_y][head.zero_x]);
			int now_num=abstract();
			if (go.count(now_num)==0)
			{
				state temp;
				temp.num=now_num,temp.close=judge(now_num),temp.zero_x=now_x,temp.zero_y=now_y;
				temp.step=head.step+1;
				temp.a_ster=temp.close+temp.step;
				go.insert(temp.num);
				q.push(temp);
			}
			swap(bac[now_y][now_x],bac[head.zero_y][head.zero_x]);
		}
	}
}
int main()
{
	scanf("%d",&n);
	printf("%d\n",bfs());
}
