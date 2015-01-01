#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>

int T;
char S[1000010];
int r;
int l;
int main()
{
	scanf("%d ", &T);
	while(T--)
	{
		r = 0;
		l = 0;
		scanf("%[^\n] ", S);
		for(int i = 0; S[i]; ++i)
		{
			int rank = (S[i] == '<' ? 1 : -1);
			if (r + rank < 0)
				break;
			r += rank;
			if (r == 0)
				l = i + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}