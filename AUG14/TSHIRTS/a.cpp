#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define MOD 1000000007LL
int tshirts[10][101];
long long dp[10][101];
int T, N;
long long ans;
int t, offset;
char line[401], *str;
int main()
{
	scanf("%d\n", &T);
	while(T--)
	{
		memset(tshirts, 0, sizeof(tshirts));
		memset(tshirts, 0, sizeof(dp));
		scanf("%d\n", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%[^\n]\n", line);
			str = line;
			while(1 == sscanf(str, "%d%n", &t, &offset))
			{
				str += offset;
				tshirts[i][t] = 1;
				tshirts[i][0]++;
			}
		}
		for(int j = 1; j <= 100; j++)
			dp[0][j] = tshirts[0][j];
		for(int i = 1; i < N; i++)
		{
			for(int j = 1; j <= 100; j++)
			{
				if(tshirts[i][j])
				{
					for(int k = 1; k <= 100; k++)
						if(tshirts[i - 1][k])
							dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
					
				}
			}
		}
		ans = 0;
		for(int i = 0; i < N; i++)
		{
			for(int j = 1; j <= 5; j++)
				printf("%lld ", dp[i][j]);
			printf("\n");
		}
		for(int i = 1; i <= 100; i++)
			ans = (ans + dp[N - 1][i]) % MOD;
		printf("%lld\n", ans);
		
	}
	return 0;
}