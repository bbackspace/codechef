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
#define MOD 1000000009
class paint
{
public:
	char c;
	int a;
	bool operator<(const paint &op2) const
	{
		return a < op2.a;
	}
} p[100010];
int T, N, M;
ll ans;
int main()
{
	si(T); getchar();
	while(T--)
	{
		si(N); getchar();
		si(M); getchar();
		for(int i = 0; i < M; i++)
		{
			sc(p[i].c); getchar();
			sll(p[i].a); getchar();
		}
		sort(p, p + M);
		ans = 1LL;
		for(int i = 1; i < M; i++)
			if(p[i - 1].c != p[i].c)
				ans = (ans * (p[i].a - p[i - 1].a)) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}