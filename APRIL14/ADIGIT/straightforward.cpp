#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<stdint.h>
#include<unistd.h>
#define ABS(x) (((x) > 0) ? (x) : -(x))
int n, m, x;
uint8_t a[100000];
int main()
{
	scanf("%u %u ", &n, &m);
	for(int i = 0; i < n; ++i)
		a[i] = getchar() - '0';
	int M = m;
	while(m--)
	{
		scanf("%d", &x);
		//x = n - m;
		long long ans = 0;
		x--;
		for(int i = 0; i < x; ++i)
		{
			ans += ABS(a[x] - a[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
