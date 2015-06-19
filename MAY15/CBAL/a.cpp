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
char P[100001];
int cum[100001][26];
ll T, N;
ll ans;
ll Q, type, A, B, L, R, X, Y;
vector<int> bal[100001];
vector<int> cumbal1[100001];
vector<ll> cumbal2[100001];
vector<ll> cumbal3[100001];

inline ll solve(int L, int R, int type)
{
	ll res = 0;
	switch(type)
	{
		case 0:
			for(int i = L; i < R; i++)
				res += cumbal1[i][R - i + 1];
			break;
		case 1:
			for(int i = L; i < R; i++)
				res += cumbal2[i][R - i + 1];
			break;
		case 2:
			for(int i = L; i < R; i++)
				res += cumbal3[i][R - i + 1];
	}
	return res;
}
void precalc()
{
	for(int j = 0; j < 26; j++)
		cum[0][j] = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j < 26; j++)
			cum[i][j] = cum[i - 1][j];
		cum[i][P[i - 1] - 'a']++;
	}
	for(int i = 1; i <= N; i++)
	{
		bal[i].clear();
		bal[i].reserve(N);
		for(int j = i; j <= N; j++)
		{
			bal[i].push_back(1);
			for(int k = 0; k < 26; k++)
				if((cum[j][k] - cum[i - 1][k]) % 2)
				{
					bal[i].back() = 0;
					break;
				}
		}
	}
	for(int i = 1; i <= N; i++)
	{
		cumbal1[i].clear();
		cumbal1[i].push_back(0);
		for(int j = i; j <= N; j++)
			cumbal1[i].push_back(cumbal1[i].back() + bal[i][j - i]);
	}
	for(int i = 1; i <= N; i++)
	{
		cumbal2[i].clear();
		cumbal2[i].push_back(0);
		for(int j = i; j <= N; j++)
			cumbal2[i].push_back(cumbal2[i].back() + bal[i][j - i] * (j - i + 1));
	}
	for(int i = 1; i <= N; i++)
	{
		cumbal3[i].clear();
		cumbal3[i].push_back(0);
		for(int j = i; j <= N; j++)
			cumbal3[i].push_back(cumbal3[i].back() + (ll)bal[i][j - i] * (j - i + 1) * (j - i + 1));
	}
}
int main()
{
	sll(T);
	while(T--)
	{
		ss(P);
		N = strlen(P);
		precalc();
		/*for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
				printf("%d ", bal[i][j]);
			printf("\n");
		}*/
		sll(Q);
		A = 0;
		B = 0;
		while(Q--)
		{
			sll(X);
			sll(Y);
			sll(type);
			L = ( X + A ) % N + 1;
			R = ( Y + B ) % N + 1;
			if (L > R)
				swap(L, R);
			ans = solve(L, R, type);
			//printf("%d %d %d: %lld\n", L, R, type, ans);
			printf("%lld\n", ans);
			A = B;
			B = ans;
		}
	}
	return 0;
}