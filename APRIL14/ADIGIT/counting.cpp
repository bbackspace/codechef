#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<stdint.h>
#include<unistd.h>
#define ABS(x) (((x) > 0) ? (x) : -(x))
const int szint = sizeof(int);
int n, m, x;
long long ans;
uint8_t a[100000];
int count[100000][10];
void build()
{
	memset(count[0], 0, 10 * szint);
	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j <= 9; ++j)
		{
			if(a[i - 1] == j)
				count[i][j] = count[i - 1][j] + 1;
			else
				count[i][j] = count[i - 1][j];
		}
	}
}
int main()
{
	scanf("%u %u ", &n, &m);
	for(int i = 0; i < n; ++i)
		a[i] = getchar() - '0';
	build();
	/*for(int i = 0; i < n; ++i)
	{
		printf("[ ");
		for(int j = 0; j <= 9; ++j)
			printf("%d ", count[i][j]);
		printf("]\n");
	}*/
	while(m--)
	{
		scanf("%d", &x);
		//x = n - m;
		ans = 0;
		x--;
		for(int i = 0; i <= 9; ++i)
		{
			ans += count[x][i] * ABS(a[x] - i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
