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
#define MAXN 5010
#define MAXLG 14
#define MOD 1000000007
char A[MAXN];
struct entry
{
    int n[2];
    int p;
} L[MAXN];
int P[MAXLG][MAXN];
int T, N, Q, k;
int stp, cnt;
int lcp[MAXN][MAXN];
int sum[MAXN];
ll ans[MAXN];
ll choose[MAXN][MAXN];
void genchoose()
{
	memset(choose, 0, sizeof(choose));
	choose[0][0] = 1;
	for(int i = 1; i <= 5000; i++)
	{
		choose[i][0] = 1;
		for(int j = 1; j <= i; j++)
			choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
	}
}

int cmp(entry a, entry b)
{
    return (a.n[0] < b.n[0]) || (a.n[0] == b.n[0] && a.n[1] < b.n[1]);
	//return a.n[0]==b.n[0] ?(a.n[1]<b.n[1] ?1: 0): (a.n[0]<b.n[0] ?1: 0);
}
int LCP(int x, int y)
{
    /*int k;
	int ret = 0;
    if (x == y)
        return N - x;
    for (k = stp - 1; k >= 0 && x < N && y < N; k--)
        if (P[k][x] == P[k][y])
		{
            x += 1 << k;
			y += 1 << k;
			ret += 1 << k;
		}
	return ret;*/
	int k, ret = 0;
    if (x == y)
        return N - x;
    for (k = stp - 1; k >= 0 && x < N && y < N; k --)
        if (P[k][x] == P[k][y])
            x += 1 << k, y += 1 << k, ret += 1 << k; return ret;
}
void build_suffix_array()
{
	for(int i = 0; i < N; i++)
        P[0][i] = A[i] - 'a';
    for(stp = 1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for(int i = 0; i < N; i++)
        {
            L[i].n[0] = P[stp - 1][i];
            L[i].n[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        sort(L, L + N, cmp);
        for(int i = 0; i < N; i++)
            P[stp][L[i].p] = (i > 0 && L[i].n[0] == L[i-1].n[0] && L[i].n[1] == L[i- 1].n[1]) ? P[stp][L[i - 1].p] : i;
    }
}
void build_LCP_array()
{
	sum[0] = 0;
	for(int i = 1; i < N; i++)
	{
		lcp[i][0] = LCP(L[i].p, L[i - 1].p);
		sum[0] += lcp[i][0];
	}
	for(int j = 1; j < N; j++)
	{
		sum[j] = 0;
		for(int i = j + 1; i < N; i++)
		{
			lcp[i][j] = min(lcp[i][j - 1], lcp[i - 1][j - 1]);
			sum[j] += lcp[i][j];
		}
	}
}
void precompute_k()
{
	ans[1] = (N * (N + 1)) / 2;
	for(int k = 2; k <= N; k++)
	{
		ans[k] = 0;
		for(int j = k - 2; j < N; j++)
			ans[k] = (ans[k] + (sum[j] * choose[j][k - 2]) % MOD) % MOD;
	}
}
int main()
{
    si(T);
	genchoose();
	while(T--)
	{
		si(N);
		si(Q);
		ss(A);
		build_suffix_array();
		build_LCP_array();
		precompute_k();
		while(Q--)
		{
			si(k);
			if(k <= N)
				printf("%lld\n", ans[k]);
			else
				printf("0\n");
		}
	}
	return 0;
}