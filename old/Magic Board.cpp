#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
struct state{
	int num[9],step;
}e;
set <int> go;
int judge(state a)
{
	int ans=0;
	for (int i=1;i<=8;i++)
	{
		ans*=10;
		ans+=a.num[i];
	}
	return ans;
}
state exchange(state a,int dir)
{
	state temp;
	a.step++;
	switch (dir)
	{
		case 1:
			for (int i=1;i<=4;i++)
				swap(a.num[i],a.num[9-i]);
			return a;
			break;
		case 2:
			for (int i=1;i<=8;i++)
				temp.num[i]=a.num[i];
			a.num[1]=temp.num[4];
			a.num[2]=temp.num[1];
			a.num[3]=temp.num[2];
			a.num[4]=temp.num[3];
			a.num[5]=temp.num[6];
			a.num[6]=temp.num[7];
			a.num[7]=temp.num[8];
			a.num[8]=temp.num[5];
			return a;
			break;
		case 3:
			for (int i=1;i<=8;i++)
				temp.num[i]=a.num[i];
			a.num[2]=temp.num[7];
			a.num[3]=temp.num[2];
			a.num[6]=temp.num[3];
			a.num[7]=temp.num[6];
			return a;
			break;
	}
}
int bfs()
{
	queue <state> q;
	state start;
	for (int i=1;i<=8;i++)
		start.num[i]=i;
	start.step=0;
	go.insert(judge(start));
	q.push(start);
	while (!q.empty())
	{
		state head;
		head=q.front();
		q.pop();
		if (judge(head)==judge(e))
			return head.step;
		for (int i=1;i<=3;i++)
		{
			state now;
			now=exchange(head,i);
			if (go.count(judge(now))==0)
			{
				go.insert(judge(now));
				q.push(now);
			}
		}
	}
}
int main()
{
	for (int i=1;i<=8;i++)
		scanf("%d",&e.num[i]);
	printf("%d\n",bfs());
}
