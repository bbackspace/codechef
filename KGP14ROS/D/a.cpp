#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()
struct Less{
	inline bool operator()(const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.second >= b.second;
	}
};
pair<int, int> a[110];
int T, N, ans;
int dp[110][20010];
int main()
{
	si(T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case %d: ", t);
		si(N);
		for(int i = 0; i < N; ++i)
		{
			int k;
			si(k);
			a[i] = make_pair(k, 0);
		}
		int noret = 0;
		for(int i = 0; i < N; ++i)
		{
			int k;
			si(k);
			a[i].second = k;
			if(a[i].second != -1)
				a[i].second -= 30;
			else
				noret++;
		}
		sort(a, a + N, Less());
		/*printf("\n");
		for(int i = 0; i < N; i++)
			printf("%d ", a[i].first);
		printf("\n");
		for(int i = 0; i < N; i++)
			printf("%d ", a[i].second);
		printf("\n");*/
		N -= noret;
		for(int j = 0; j < 10000; j++)
			dp[0][j] = 0;
		for(int i = 1; i <= N; i++)
		{
			for(int j = 0; j < 10000; j++)
			{
				dp[i][j] = dp[i - 1][j] + 1;
				if(j + a[i - 1].first <= a[i - 1].second)
				{
					if(j + a[i - 1].first < 10000)
						dp[i][j] = min(dp[i][j], dp[i - 1][j + a[i - 1].first]);
				}
			}
		}
		/*for(int i = 0; i <= N; i++)
		{
			for(int j = 0; j < 100; j++)
				printf("%d ", dp[i][j]);
			printf("\n");
		}*/
		printf("%d\n", dp[N][0]);
	}
	return 0;
}