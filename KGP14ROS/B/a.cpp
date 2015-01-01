#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()

char X[1001], Y[1001];
int DP[1001][1001];
ll T, P, Q;
int lcs()
{
	for(int i = 0; i <= P; i++)
		DP[i][0] = 0;
	for(int i = 0; i <= Q; i++)
		DP[0][i] = 0;
	for(int i = 1; i <= P; i++)
		for(int j = 1; j <= Q; j++)
			if(X[i - 1] == Y[j - 1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
	return DP[P][Q];
}
int main()
{
	sll(T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case %d: ", t);
		sll(P);
		sll(Q);
		ss(X);
		ss(Y);
		printf("%lld", P + Q - lcs());
		if(t < T)
			printf("\n");
	}
	return 0;
}