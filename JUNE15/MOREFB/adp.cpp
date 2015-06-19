#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cassert>
#include<algorithm>
#include<vector>
#include<map>
#define MOD 99991
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
ll a[50001];
ll dp[2001][2001][2] = {0};
int T, N, K;
ll ans, sum;
inline ll fmod(ll n)
{
	if(n < MOD)
		return n;
	return n % MOD;
}
ll cr[2][2], s[31][2][2];
ll mat[2][2] = {{1, 1}, {1, 0}}, res[2][2];
inline void matmulmod(ll a[2][2], ll b[2][2], ll res[2][2])
{
	cr[0][0] = fmod(a[0][0] * b[0][0] + a[0][1] * b[1][0]);
	cr[0][1] = fmod(a[0][0] * b[0][1] + a[0][1] * b[1][1]);
	cr[1][0] = fmod(a[1][0] * b[0][0] + a[1][1] * b[1][0]);
	cr[1][1] = fmod(a[1][0] * b[0][1] + a[1][1] * b[1][1]);
	res[0][0] = cr[0][0];
	res[0][1] = cr[0][1];
	res[1][0] = cr[1][0];
	res[1][1] = cr[1][1];
}
inline void matpowmod(ll b) // res = mat ^ b
{
	res[0][0] = res[1][1] = 1;
	res[0][1] = res[1][0] = 0;
	int si = 0;
    while(b)
    {
        if(b & 1)
            matmulmod(res, s[si], res);
        b >>= 1;
		si++;
    }
}
inline int next_perm(int v)
{
	unsigned int t = v | (v - 1);
	return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}
/*ll fs(int N, int K)
{
	ll ans = 0;
	for(int v = (1 << K) - 1; v < (1 << N); v = next_perm(v))
	{
		sum = 0;
		for(int i = 0; i < N; i++)
			if(v & (1 << i))
				sum += a[i + 1];
        ans = (ans + fib(sum)) % MOD;
	}
	return ans;
}*/
void precompute_s()
{
    s[0][0][0] = s[0][0][1] = s[0][1][0] = 1;
	s[0][1][1] = 0;
	for(int i = 1; i < 31; i++)
        matmulmod(s[i - 1], s[i - 1], s[i]);
}
int main()
{
	precompute_s();
	si(N);
	si(K);
	for(int i = 1; i <= N; ++i)
		sll(a[i]);
	matpowmod(a[1]);
	dp[1][1][0] = fmod(res[1][0]);
	dp[1][1][1] = fmod(2 * res[1][1] + res[1][0]);
	dp[1][0][1] = 2;
	for(int n = 2; n <= N; n++)
	{
		dp[n][0][1] = 2;
		for(int k = 1; k <= K; k++)
		{
			matpowmod(a[n]);
			ll fib = fmod(res[1][0]);
			ll luc = fmod(2 * res[1][1] + res[1][0]);
			dp[n][k][0] = fmod(fmod((dp[n-1][k-1][0] * luc + dp[n-1][k-1][1] * fib) * 49996) + dp[n-1][k][0]); // 49996 = 2^-1 mod 99991
			dp[n][k][1] = fmod(fmod((5 * dp[n-1][k-1][0] * fib + dp[n-1][k-1][1] * luc) * 49996) + dp[n-1][k][1]);
		}
	}
	/*for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= i; j++)
			printf("%lld ", FS[i][j]);
		printf("\n");
	}
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= i; j++)
			printf("%lld ", LS[i][j]);
		printf("\n");
	}
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= i; j++)
			printf("%lld ", fs(i, j));
		printf("\n");
	}*/
	printf("%lld\n", dp[N][K][0]);
	return 0;
}