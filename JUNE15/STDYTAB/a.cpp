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
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
#define MOD 1000000000
ll choose[4010][4010];
ll dp[2010][2010];
int T, N, M;
ll ans;
void genchoose()
{
	memset(choose, 0, sizeof(choose));
	choose[0][0] = 1;
	for(int i = 1; i <= 4000; i++)
	{
		choose[i][0] = 1;
		for(int j = 1; j <= i; j++)
			choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
	}
}
inline ll f(int i)
{
	return choose[M+i-1][i];
}
int main()
{
	genchoose();
	si(T);
	while(T--)
	{
		si(N);
		si(M);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= M; i++)
			dp[i][0] = 1;
		for(int j = 1; j <= N; j++)
			dp[0][j] = (f(0) * dp[0][j - 1]) % MOD;
		for(int i = 1; i <= M; i++)
			for(int j = 1; j <= N; j++)
				dp[i][j] = (dp[i - 1][j] + (f(i) * dp[i][j - 1]) % MOD) % MOD;
		/*for(int i = 0; i <= 10; i++)
		{
			for(int j = 0; j <= 10; j++)
				printf("%lld ", dp[i][j]);
			printf("\n");
		}
		*/
		printf("%lld\n", dp[M][N]);
	}
	return 0;
}