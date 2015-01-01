#include<cstdio>
#define MOD 1000000007
inline long long fastmod(long long a, long long m)
{
	if(a < m)
		return a;
	return a % m;
}

inline long long powmod(long long a, long long b, long long m)
{
	if(b == 0)
		return 1 % m;
	long long prod = 1;
	long long s = a;
	while(b)
	{
		if(b & 1)
			prod = fastmod(prod * s, m);
		b>>=1;
		s = fastmod(s * s, m);
	}
	return prod;
}

int T;
long long N, ans;
const long long inv25 = 280000002;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &N);
		if(N % 2)
		{
			N--;
			ans = powmod(26, N / 2 + 1, MOD);
		}
		else
			ans = 0;
		ans += fastmod(52 * fastmod((powmod(26, N/2, MOD) - 1) * inv25, MOD), MOD);
		printf("%lld\n", fastmod(ans, MOD));
	}
	return 0;
}