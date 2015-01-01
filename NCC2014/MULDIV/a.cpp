#include<cstdio>
int T;
long long N, K, M, ans;
int main()
{
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld %lld %lld", &N, &K, &M);
		ans = N;
		if(K != 1)
		{
			for(int i = 1; i <= M; ++i)
			{
				if(ans % K == 0)
				{
					ans /= K;
				}
				else
				{
					if((M - i) % 2 == 0)
						ans *= K;
					break;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}