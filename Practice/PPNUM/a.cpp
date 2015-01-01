#include<stdio.h>
#define MOD 1000000007
long long pow10(int x)
{
	long long p = 1;
	for(int i = 0; i < x; ++i)
		p *= 10;
	return p;
}
long long sumrange(long long upper, long long lower)
{
	long long sum = (upper * (upper + 1) - lower * (lower + 1)) / 2;
	return sum % MOD;
}
long long sumr(int dig)
{
	long long lower = pow10(dig - 1);
	long long upper = pow10(dig) - 1;
	return (sumrange(upper, lower - 1) * dig) % MOD;
}
int numdigs(long long n)
{
	int i = 0;
	while(n > 0)
	{
		i++;
		n /= 10;
	}
	return i;
}
int T;
int L, R;
long long sum;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &L, &R);
		sum = 0;
		int i = numdigs(L);
		int j = numdigs(R);
		if (i != j)
		{
			sum = (i * sumrange(pow10(i) - 1, L - 1)) % MOD;
			//printf("%lld\n", (i * sumrange(pow(10, i) - 1, L - 1)) % MOD);
			for(int k = i + 1; k < j; ++k)
			{
				sum = (sum + sumr(k)) % MOD;
				//printf("%lld\n", sumrange(k));
			}
			sum = (sum + j * sumrange(R, pow10(j - 1) - 1)) % MOD;
			//printf("%lld\n", (j * sumrange(R, pow(10, j - 1) - 1)) % MOD);
		}
		else
			sum = (i * sumrange(R, L - 1)) % MOD;
		printf("%lld\n", sum % MOD);
	}
	return 0;
}