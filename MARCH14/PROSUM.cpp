#include<cstdio>
#include<cstdlib>
unsigned long long a;
unsigned long long v;
unsigned long long T, N, i, j, N2;
int main()
{
	scanf("%llu", &T);
	while(T--)
	{
		v = 0;
		N2 = 0;
		scanf("%llu", &N);
		for(i = 0; i < N; ++i)
		{
			scanf("%llu", &a);
			switch(a)
			{
			case 0:
			case 1:
				i--;
				N--;
				break;
			case 2:
				N2++;
			}
		}
		v = (N*(N-1))/2 - (N2*(N2-1))/2;
		printf("%llu\n", v);
	}
	return 0;
}