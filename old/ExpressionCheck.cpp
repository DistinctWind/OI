#include <cstdio>
using namespace std;
int main()
{
	char now;
	int l=0;
	while (scanf(" %c",&now),now!='@')
	{
		if (now=='(')
			l++;
		else if (now==')')
		{
			if (l!=0)
				l--;
			else
			{
				printf("NO");
				return 0;
			}
		}
	}
	if (l!=0)
		printf("NO");
	else printf("YES");
}
