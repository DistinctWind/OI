#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=20001;
struct Node{
	char s[36];
	int ans;
}q1[MAXN],q2[MAXN];
int n;
char a[10][50],b[10][50];
bool pd(char *s1,char *s2)
{
	int len1=strlen(s1),len2=strlen(s2);
	if (len1!=len2) return false;
	for (int i=0;i<len1;i++)
		if (s1[i]!=s2[i])
			return false;
	return true;
}
bool judge(char *str,int num,bool flag)
{
	char *now=flag?a[num]:b[num];
	for (int i=0;i<strlen(now);i++)
		if (str[i]!=now[i])
			return false;
	return true;
}
inline void bfs()
{
	int l1=1,r1=1,l2=1,r2=1;
	while (l1<=r1&&l2<=r2)
	{
		if (q1[l1].ans+q2[l2].ans>10)
		{
			printf("NO ANSWER!\n");
			return;
		}
		for (unsigned int i=0;i<strlen(q1[l1].s);i++)
		{
			for (int j=1;j<n;j++)
			{
				if (judge(q1[l1].s+i,j,1))
				{
					r1++;
					unsigned int k=0,l=0;
					while (k<i)
					{
						q1[r1].s[k]=q1[l1].s[k];
						k++;
					}
					while (l<strlen(b[j])) q1[r1].s[k++]=b[j][l++];
					l=i+strlen(a[j]);
					while (l<=strlen(q1[l1].s)) q1[r1].s[k++]=q1[l1].s[l++];
					q1[r1].s[k]=0;
					q1[r1].ans=q1[l1].ans+1;
					for (int w=1;w<=r2;w++)
						if (pd(q1[r1].s,q2[w].s))
						{
							printf("%d\n",q1[r1].ans+q2[w].ans);
							return;
						}
				}
			}
		}
		for (unsigned int i=0;i<strlen(q2[l2].s);i++)
		{
			for (int j=1;j<n;j++)
			{
				if (judge(q2[l2].s+i,j,0))
				{
					r2++;
					unsigned int k=0,l=0;
					while (k<i)
					{
						q2[r2].s[k]=q2[l2].s[k];
						k++;
					}
					while (l<strlen(a[j])) q2[r2].s[k++]=a[j][l++];
					l=i+strlen(b[j]);
					while (l<=strlen(q2[l2].s)) q2[r2].s[k++]=q2[l2].s[l++];
					q2[r2].s[k]=0;
					q2[r2].ans=q2[l2].ans+1;
					for (int w=1;w<=r1;w++)
						if (pd(q1[w].s,q2[r2].s))
						{
							printf("%d\n",q1[w].ans+q2[r2].ans);
							return;
						}
				}
			}
		}
		l1++; l2++;
	}
	printf("NO ANSWER!\n");
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf(" %s %s",q1[1].s,q2[1].s);
	n=1;
	q1[1].ans=q2[1].ans=0;
	while (scanf(" %s %s",a[n],b[n])!=EOF) n++;
	bfs();
}
