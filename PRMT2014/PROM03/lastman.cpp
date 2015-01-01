#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
#include<stdint.h>
#include<unistd.h>
int T, p;
int a[26];
bool valid(int p)
{
	for(int i = p ; i < 2 * p; ++i)
		if(a[i] == 0)
			return false;
	return true;
}
int josephus(int n, int k, int p)
{
	if (n == p)
	{
		return 1;
	}
	else
		return (josephus(n - 1, k, p) + k - 1) % n + 1;
}
int minM(int p)
{
	if(p == 1) return 2;
	int m;
	for(m = p + 1; ; ++m)
	{
		if (m % (2*p) == 0)
		{
			m += p;
			continue;
		}
		memset(a, 0, 26 * sizeof(int));
		int i = -1;
		while(1)
		{
			for(int j = 0; j < m; ++j)
			{
				do
				{
					i++;
					if(i == 2 * p)
						i = 0;
				} while (a[i]);
			}
			if (i < p)
				break;
			a[i] = 1;
		}
		/*printf("[ ");
		for(int i = 0; i < 2 * p; ++i)
			printf("%d ", a[i]);
		printf("] ");*/
		if (valid(p))
			break;
	}
	return m;
}
int main()
{
	//scanf("%d", &T);
	//while(T--)
	{
		//scanf("%d", &p);
		
		//printf("%d\n", minM(p));
	}
	int i;
	for(i = 5; i <= 30;++i)
	{
		printf("i = %d, josephus=%d\n", i, josephus(8,i,4));
	}
	printf("%d", i);
	return 0;
}