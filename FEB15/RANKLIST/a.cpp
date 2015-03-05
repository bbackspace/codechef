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
ll a[100010];
ll T, N, S, ans;
int main()
{
	sll(T);
	while(T--)
	{
		sll(N);
		sll(S);
		ll x = N * (N + 1) / 2;
		ans = 0;
		ll i = N - 1;
		while(x > S)
		{
			x -= i;
			i--;
			ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
