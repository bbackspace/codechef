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

int T, N, k, ans, a[1000];
char oper[4];
int main()
{
	si(T);
	while(T--)
	{
		scanf("%d %d %d", &N, &k, &ans);
		int oldans = ans;
		for(int i = 0; i < N; i++)
			si(a[i]);
		ss(oper);
		if (k == 0)
		{
			printf("%d\n", ans);
			continue;
		}
		if(oper[0] == 'A')
			for(int i = 0; i < N; i++)
				ans = ans & a[i];
		else if(oper[0] == 'O')
			for(int i = 0; i < N; i++)
				ans = ans | a[i];
		else
		{
			for(int i = 0; i < N; i++)
				ans = ans ^ a[i];
			if(k % 2 == 0)
				ans = oldans;
		}
		printf("%d\n", ans);
	}
	return 0;
}