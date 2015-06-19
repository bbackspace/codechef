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
int a[100000];
int T, N;
int main()
{
	si(T);
	while(T--)
	{
		si(N);
		for(int i = 0; i < N; ++i)
			si(a[i]);
		ll ans = a[0];
		for(int i = 1; i < N; i++)
			ans += max(a[i] - a[i - 1], 0);
		printf("%lld\n", ans);
	}
	return 0;
}