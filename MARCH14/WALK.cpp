#include<cstdio>
#include<ctime>
#include<cstdlib>
#define MAX(x,y) ( (x) > (y) ? (x) : (y) )
unsigned long long seg[100000] = {0}, v;
int T, N, i, j;
int main()
{
	srand(time(NULL));
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		//N = rand() % 100000;
		for(i = 0; i < N; ++i)
			scanf("%llu", &seg[i]);
			//seg[i] = rand() % 1000000;
		v = seg[N - 1];
		for(i = N - 2; i >= 0; --i)
		{
			v = MAX(seg[i], v + 1);
		}
		
		//Verify
		//for(i = 0; i < N; ++i)
		//{
			/*printf("Array(N=%d):\n", N);
			for(j = 0; j < N; ++j)
			{
				printf("%d ", seg[j]);
			}
			printf("\n");*/
			/*if (v < seg[i])
			{
				printf("Ruined\nArray(N=%d):\n", N);
				for(j = 0; j < N; ++j)
				{
					printf("%d ", seg[j]);
				}
				printf("\n");
				return 0;
			}
			v--;
		}*/
		printf("%llu", v);
	}
	return 0;
}