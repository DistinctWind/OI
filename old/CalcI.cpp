#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXL=101;
char now[MAXL];
double calc()
{
	scanf("%s",&now);
	switch (now[0])
	{
		case '+' : return calc()+calc();
		case '-' : return calc()-calc();
		case '*' : return calc()*calc();
		case '/' : return calc()/calc();
		default : return (double)atof(now);
	}
}
int main()
{
	printf("%lf",calc());
}
