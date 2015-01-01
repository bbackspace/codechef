#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
#define MOD 1000000007

char s[100001];
int T, N;
long long ans;
int main()
{
	si(T);
	while(T--)
	{
		ss(s);
		N = strlen(s);
		ans = 1;
		for(int i = 0; i < N; i++)
		{
			if(i % 2 == 0)
				if(s[i] == 'r')
					ans = ((ans << 1) + 2) % MOD;
				else
					ans = (ans << 1) % MOD;
			else
				if(s[i] == 'r')
					ans = ((ans << 1) + 1) % MOD;
				else
					ans = ((ans << 1) - 1) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}