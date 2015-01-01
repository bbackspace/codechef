#include<cstdio>
int dp[1000001][8];
int N, ans;
int main()
{
	scanf("%d", &N);
	for(int n = 0; n < N; n++)
		dp[n][7] = 1;
	for(int i = 6; i >= 1; i--)
	{
		dp[1][i] = dp[2][i] = 0;
		for(int n = 3; n <= N; n++)
			dp[n][i] = (dp[n - 2][i] + dp[n - 2][i + 1]) % 1000000007;
	}
	printf("%d\n", dp[N][1]);
	return 0;
}