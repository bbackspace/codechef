#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
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
ll ans;
int di, pi;
int main()
{
	si(T);
	while(T--)
	{
		si(N);
		for(int i = 0; i < N; ++i)
			si(a[i]);
		di = pi = 0;
		ans = 0LL;
		while(1)
		{
			while(di < N && a[di] >= 0)
				di++;
			while(pi < N && a[pi] <= 0)
				pi++;
			if(pi >= N || di >= N)
				break;
			int d = min(-a[di], a[pi]);
			printf("ans=%d, di=%d, pi=%d, a[di]=%d, a[pi]=%d, d=%d, stepcost=%d\n", ans, di, pi, a[di], a[pi], d, abs(pi - di) * d);
			a[di] += d;
			a[pi] -= d;
			ans += (ll)abs(pi - di) * d;
		}
		printf("%lld\n", ans);
	}
	return 0;
}