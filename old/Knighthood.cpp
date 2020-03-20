#include <cstdio>
#include <queue>
#include <iostream>
#include <set>
#define MAXL 6
using namespace std;
const int final[5][5]={
	{'1','1','1','1','1'},
	{'0','1','1','1','1'},
	{'0','0','*','1','1'},
	{'0','0','0','0','1'},
	{'0','0','0','0','0'},
};
const int mov_i[9]={0,-1,-2,-2,-1,1,2,2,1};
const int mov_j[9]={0,-2,-1,1,2,2,1,-1,-2};
const int base=127,mod=10000007;
int n;
struct state{
	char map[MAXL][MAXL];
	int empty_i,empty_j,step,wrong,hash,weight;
	friend bool operator < (state a,state b)
	{
		return a.weight>b.weight;
	}
}start;
int judge(state now)
{
	int temp=0;
	for (int i=1;i<=5;i++)
		for (int j=1;j<=5;j++)
			if (now.map[i][j]!=final[i-1][j-1])
				temp++;
	return temp;
}
int myHash(state now)
{
	int temp=0;
	for (int i=1;i<=5;i++)
		for (int j=1;j<=5;j++)
			temp=(temp*base+now.map[i][j])%mod;
	return temp;
}
void copy(char a[MAXL][MAXL],char b[MAXL][MAXL])
{
	for (int i=1;i<=5;i++)
		for (int j=1;j<=5;j++)
			a[i][j]=b[i][j];
}
void print(state a)
{
	printf("Now map is:\n");
	for (int i=1;i<=5;i++)
	{
		for (int j=1;j<=5;j++)
			printf("%c",a.map[i][j]);
		putchar('\n');
	}
	printf("With the val=%d\n",a.weight);
}
int A_star()
{
	priority_queue <state> q;
	set <int> s;
	s.insert(start.hash);
	q.push(start);
	while (!q.empty())
	{
		state head;
		head=q.top();
		q.pop();
		if (head.step>15)
			return -1;
		if (head.wrong==0)
			return head.step;
		/*printf("Show the map first:\n");
		for (int i=1;i<=5;i++)
		{
			for (int j=1;j<=5;j++)
				printf("%c",head.map[i][j]);
			putchar('\n');
		}*/
		for (int i=1;i<=8;i++)
		{
			int now_empty_i=head.empty_i+mov_i[i];
			int now_empty_j=head.empty_j+mov_j[i];
			if ((1<=now_empty_i&&now_empty_i<=5&&1<=now_empty_j&&now_empty_j<=5)==false)
				continue;
			state temp;
			swap(head.map[head.empty_i][head.empty_j],head.map[now_empty_i][now_empty_j]);
			copy(temp.map,head.map);
			swap(head.map[head.empty_i][head.empty_j],head.map[now_empty_i][now_empty_j]);
			temp.hash=myHash(temp);
			if (s.count(temp.hash)==1)
			{
				//printf("This map has already been found.\n");
				continue;
			}
			temp.empty_i=now_empty_i; temp.empty_j=now_empty_j; temp.wrong=judge(temp);
			temp.step=head.step+1; temp.weight=temp.wrong+temp.step;
			//printf("Empty moved from (%d,%d) to (%d,%d)\n",head.empty_i,head.empty_j,temp.empty_i,temp.empty_j);
			//print(temp);
			s.insert(temp.hash);
			q.push(temp);
		}
	}
	return -1;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int t=1;t<=n;t++)
	{
		for (int i=1;i<=5;i++)
			for (int j=1;j<=5;j++)
			{
				scanf(" %c",&start.map[i][j]);
				if (start.map[i][j]=='*')
				{
					start.empty_i=i;
					start.empty_j=j;
				}
			}
		start.wrong=judge(start); start.step=0; start.weight=start.wrong+start.step; start.hash=myHash(start);
		printf("%d\n",A_star());
	}
}
