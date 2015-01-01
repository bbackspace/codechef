#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<iomanip>
#include<stdint.h>
#include<unistd.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)

ll a[100000], L[100000], R[100000], sum[100000], cum[100001], diff[100000];
ll N, ans, Q, x, y, t;

int main()
{
	sll(N);
	for(int i = 0; i < N; i++)
		sll(a[i]);
	cum[0] = 0;
	for(int i = 1; i <= N; i++)
		cum[i] = cum[i - 1] + a[i - 1];
	for(int i = 0; i < N; i++)
	{
		sll(L[i]);
		sll(R[i]);
		sum[i] = cum[R[i]] - cum[L[i] - 1];
	}
	memset(diff, 0, sizeof(diff));
	sll(Q);
	while(Q--)
	{
		sll(t);
		sll(x);
		sll(y);
		if(t == 1)
		{
			for(int i = 0; i < N; i++)
			{
				if(L[i] <= x && x <= R[i])
				{
					diff[i] += y - a[x - 1];
				}
			}
			a[x - 1] = y;
		}
		else
		{
			ans = 0;
			for(int i = x - 1; i < y; i++)
			{
				ans += sum[i] + diff[i];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}  