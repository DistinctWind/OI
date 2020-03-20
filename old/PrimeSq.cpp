#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
const int MAXNUM=100001;
int sum,top,cnt,a[6][6];
bool isPrime[MAXNUM],ans;
struct Res{
	int res[6][6];
	friend bool operator < (Res a,Res b)
	{
		int x[6],y[6];
		for (int i=1;i<=5;i++)
		{
			x[i]=a.res[i][1]*10000+a.res[i][2]*1000+a.res[i][3]*100+a.res[i][4]*10+a.res[i][5];
			y[i]=b.res[i][1]*10000+b.res[i][2]*1000+b.res[i][3]*100+b.res[i][4]*10+b.res[i][5];
		}
		return (x[1]<y[1])||
			   (x[1]==y[1]&&x[2]<y[2])||
			   (x[1]==y[1]&&x[2]==y[2]&&x[3]<y[3])||
			   (x[1]==y[1]&&x[2]==y[2]&&x[3]==y[3]&&x[4]<y[4])||
			   (x[1]==y[1]&&x[2]==y[2]&&x[3]==y[3]&&x[4]==y[4]&&x[5]<y[5]);
	}
}r[MAXNUM];
inline void calc()
{
	for (int i=2;i<=100000;i++)
		isPrime[i]=true;
	for (int i=2;i<=sqrt(100000);i++)
		for (int j=2;i*j<=100000;j++)
			isPrime[i*j]=false;
}
bool check(int a,int b,int c,int d,int e)
{
	int tmp=a*10000+b*1000+c*100+d*10+e;
	if (tmp<10000||!isPrime[tmp]) return false;
	return true;
}
inline void solve()
{
	for (a[1][5]=1;a[1][5]<=9;a[1][5]+=2)
	{
		for (a[5][5]=1;a[5][5]<=9;a[5][5]+=2)
		{
			for (a[5][1]=1;a[5][1]<=9;a[5][1]+=2)
			{
				for (a[4][2]=0;a[4][2]<=9;a[4][2]++)
				{
					for (a[3][3]=0;a[3][3]<=9;a[3][3]++)
					{
						a[2][4]=sum-(a[1][5]+a[3][3]+a[4][2]+a[5][1]);
						if (a[2][4]<0||a[2][4]>9) continue;
						//printf("1 %d\n",a[5][1]*10000+a[4][2]*1000+a[3][3]*100+a[2][4]+a[1][5]);
						if (!check(a[5][1],a[4][2],a[3][3],a[2][4],a[1][5])) continue;
						for (a[4][4]=0;a[4][4]<=9;a[4][4]++)
						{
							a[2][2]=sum-(a[1][1]+a[3][3]+a[4][4]+a[5][5]);
							if (a[2][2]<0||a[2][2]>9) continue;
							if (!check(a[1][1],a[2][2],a[3][3],a[4][4],a[5][5])) continue;
							for (a[1][2]=0;a[1][2]<=9;a[1][2]++)
							{
								for (a[1][3]=0;a[1][3]<=9;a[1][3]++)
								{
									a[1][4]=sum-(a[1][1]+a[1][2]+a[1][3]+a[1][5]);
									if (a[1][4]<0||a[1][4]>9) continue;
									if (!check(a[1][1],a[1][2],a[1][3],a[1][4],a[1][5])) continue;
									for (a[3][4]=0;a[3][4]<=9;a[3][4]++)
									{
										a[5][4]=sum-(a[1][4]+a[2][4]+a[3][4]+a[4][4]);
										if (a[5][4]<0||a[5][4]>9) continue;
										if (!check(a[1][4],a[2][4],a[3][4],a[4][4],a[5][4])) continue;
										for (a[3][1]=0;a[3][1]<=9;a[3][1]++)
										{
											for (a[3][2]=0;a[3][2]<=9;a[3][2]++)
											{
												a[3][5]=sum-(a[3][1]+a[3][2]+a[3][3]+a[3][4]);
												if (a[3][5]<0||a[3][5]>9) continue;
												if (!check(a[3][1],a[3][2],a[3][3],a[3][4],a[3][5])) continue;
												a[5][2]=sum-(a[1][2]+a[2][2]+a[3][2]+a[4][2]);
												if (a[5][2]<0||a[5][2]>9) continue;
												if (!check(a[1][2],a[2][2],a[3][2],a[4][2],a[5][2])) continue;
												a[5][3]=sum-(a[5][1]+a[5][2]+a[5][4]+a[5][5]);
												if (a[5][3]<0||a[5][3]>9) continue;
												if (!check(a[5][1],a[5][2],a[5][3],a[5][4],a[5][5])) continue;
												for (a[4][5]=1;a[4][5]<=9;a[4][5]+=2)
												{
													a[2][5]=sum-(a[1][5]+a[3][5]+a[4][5]+a[5][5]);
													if (a[2][5]<0||a[2][5]>9) continue;
													if (!check(a[1][5],a[2][5],a[3][5],a[4][5],a[5][5])) continue;
													for (a[2][1]=0;a[2][1]<=9;a[2][1]++)
													{
														a[4][1]=sum-(a[1][1]+a[2][1]+a[3][1]+a[5][1]);
														if (a[4][1]<0||a[4][1]>9) continue;
														if (!check(a[1][1],a[2][1],a[3][1],a[4][1],a[5][1])) continue;
														a[4][3]=sum-(a[4][1]+a[4][2]+a[4][4]+a[4][5]);
														if (a[4][3]<0||a[4][3]>9) continue;
														if (!check(a[4][1],a[4][2],a[4][3],a[4][4],a[4][5])) continue;
														a[2][3]=sum-(a[2][1]+a[2][2]+a[2][4]+a[2][5]);
														if (a[2][3]<0||a[2][3]>9) continue;
														if (!check(a[2][1],a[2][2],a[2][3],a[2][4],a[2][5])) continue;
														if (!check(a[1][3],a[2][3],a[3][3],a[4][3],a[5][3])) continue;
														cnt++;
														for (int i=1;i<=5;i++)
															for (int j=1;j<=5;j++)
																r[cnt].res[i][j]=a[i][j];
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&sum,&top);
	a[1][1]=top;
	calc();
	solve();
	sort(r+1,r+1+cnt);
	for (int k=1;k<=cnt;k++)
	{
		for (int i=1;i<=5;i++)
		{
			for (int j=1;j<=5;j++)
				printf("%d",r[k].res[i][j]);
			putchar('\n');
		}
		putchar('\n');
	}
}
/*inline void setup()
{
	calc();
	for (int i=10003;i<=99999;i+=2)
	{
		if (isPrime[i])
		{
			int a[5]={i/10000,i/1000%10,i/100%10,i/10%10,i%10};
			if (a[0]+a[1]+a[2]+a[3]+a[4]!=sum) continue;
			qz[i/10000]=qz[i/1000]=qz[i/100]=qz[i/10]=qz[i]=true;
			hz[i%10000]=hz[i%1000]=hz[i%100]=hz[i%10]=hz[i]=true;
		}
	}
}
void print()
{
	for (int i=1;i<=5;i++)
		printf("%d\n",lin[i]);
	putchar('\n');
}
void dfs(int x,int y)
{
	if (y==6)
		x++,y=1;
	if (x<5)
	{
		bool ok1,ok2,ok3,ok4;
		for (int i=0;i<=9;i++)
		{
			ok1=qz[lin[x]*10+i];
			ok2=qz[lis[y]*10+i];
			ok3=(x!=y||(x==y&&qz[cro1*10+i]));
			ok4=(x+y!=6||(x+y==6&&hz[i*p[x]+cro2]));
			if (!(ok1&&ok2&&ok3&&ok4)) continue;
			lin[x]=lin[x]*10+i;
			lis[y]=lis[y]*10+i;
			if (x==y) cro1=cro1*10+i;
			if (x+y==6) cro2=i*p[x]+cro2;
			dfs(x,y+1);
			lin[x]/=10;
			lis[y]/=10;
			if (x==y) cro1/=10;
			if (x+y==6) cro2%=p[x];
		}
	}
	if (x==5)
	{
		int i;
		bool flag=true;
		int tmp[6]={0};
		for (i=1;i<=5;i++)
		{
			tmp[i]=sum-(lis[i]/1000+lis[i]/100%10+lis[i]/10%10+lis[i]%10);
			if (tmp[i]<=0)
			{
				for (i--;i>=1;i--)
				{
					lin[x]/=10;
					lis[i]/=10;
					if (i==1) cro2%=p[x];
					if (i==5) cro1/=10;
				}
				return;
			}
			lin[x]=lin[x]*10+tmp[i];
			lis[i]=lis[i]*10+tmp[i];
			if (i==1)
				cro2=tmp[i]*p[x]+cro2;
			if (i==5)
				cro1=cro1*10+tmp[i];
			if (!(qz[lin[x]]&&qz[lis[i]]&&qz[cro1]&&hz[cro2]))
			{
				flag=false;
				break;
			}
		}
		if (flag)
		{
			ans=true;
			print();
		}
		for (i=i>5?5:i;i>=1;i--)
		{
			lin[x]/=10;
			lis[i]/=10;
			if (i==1) cro2%=p[x];
			if (i==5) cro1/=10;
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	//clock_t start,end;
	//start=clock();
	scanf("%d%d",&sum,&top);
	setup();
	lin[1]=lis[1]=cro1=top;
	dfs(1,2);
	if (!ans) printf("NONE\n");
	//end=clock();
	//printf("%.3lf",(double)(end-start)/CLOCKS_PER_SEC);
}*/
