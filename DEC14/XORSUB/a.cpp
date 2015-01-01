#include<bits/stdc++.h>
using namespace std;
int T, a[1000], N, K;
int DP[1001][1024];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &K);
		for(int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i <= 1023; i++)
			DP[0][i] = i;
		for(int i = 1; i <= N; i++)
			for(int k = 0; k <= 1023; k++)
				DP[i][k] = max(DP[i - 1][k], DP[i - 1][k ^ a[i - 1]]);
		printf("%d\n", DP[N][K]);
	}
}