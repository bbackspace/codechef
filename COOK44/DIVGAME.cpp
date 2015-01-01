#include<cstdio>
#include<cstdlib>
#include<cmath>
#define TIM 1
#define MIKE 2
unsigned T;
unsigned N;
unsigned char a[100000001];

void precalc()
{
	a[0] = 0;
	a[1] = TIM;
	for(unsigned i = 2; i < 100000000u; ++i)
	{
		if(a[i - 1] == TIM)
		{
			a[i] = MIKE;
			continue;
		}
		unsigned root = (unsigned)sqrt((double)i);
		unsigned k;
		for(k = 2; k <= root; ++k)
			if(i % k == 0)
				if(a[k] == TIM || a[i / k] == TIM)
				{
					a[i] = MIKE;
					break;
				}
		if (k == root + 1)
			a[i] = TIM;
	}
}
int main()
{
	precalc();
	/*for(unsigned i = 1; i < 15; ++i)
	{
		printf("%u - %s\n", i, (a[i] == TIM ? "TIM": "MIKE"));
	}
	return 0;*/
	scanf("%u", &T);
	while(T--)
	{
		scanf("%u", &N);
		if(a[N] == TIM)
			printf("Tom\n");
		else
			printf("Mike\n");
	}
	return 0;
}