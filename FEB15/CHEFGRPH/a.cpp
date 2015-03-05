#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
#include<stdint.h>
#include<unistd.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
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

ll T, N, M, K, ans;
ll e[4][50000];
int main()
{
	sll(N);
	sll(M);
	sll(K);
	for(int i = 0; i < K; i++)
		scanf("%lld %lld %lld %lld", &e[0][i], &e[1][i], &e[2][i], &e[3][i]);
	ans = powmod(M, N, MOD);
	for(int i = 0; i < K; i++)
	{
		ll t = powmod(M, max(e[0][i] - 1, 0LL), MOD);
		t = (t * powmod(M, max(N - e[2][i], 0LL), MOD)) % MOD;
		ans = (ans + t) % MOD;
	}
	for(int i = 0; i < K - 1; i++)
	{
		for(int j = i + 1; j < K; j++)
		{
			if(e[2][i] < e[0][j] || (e[2][i] == e[0][j] && e[3][i] == e[1][j]))
			{
				ll t = powmod(M, max(e[0][i] - 1, 0LL), MOD);
				t = (t * powmod(M, max(N - e[2][j], 0LL), MOD)) % MOD;
				t = (t * powmod(M, max(e[0][j] - e[2][i] - 1, 0LL), MOD)) % MOD;
				ans = (ans + t) % MOD;
			}
			else if(e[2][j] < e[0][i] || (e[2][j] == e[0][i] && e[3][j] == e[1][i]))
			{
				ll t = powmod(M, max(e[0][j] - 1, 0LL), MOD);
				t = (t * powmod(M, max(N - e[2][i], 0LL), MOD)) % MOD;
				t = (t * powmod(M, max(e[0][i] - e[2][j] - 1, 0LL), MOD)) % MOD;
				ans = (ans + t) % MOD;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}