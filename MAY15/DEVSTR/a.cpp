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
#include<stdint.h>
#include<unistd.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()

char a[100010];
int end[100010];
ll T, N, k, ans, ans2;
int main()
{
	sll(T);
	while(T--)
	{
		sll(N);
		sll(k);
		ss(a);
		ans = 0;
		if(k == 1)
		{
			ll flen = 1;
			char prev = a[0];
			for(int i = 1; i < N; i++)
			{
				if(a[i] == prev)
					flen++;
				else
					flen = 1;
				if(flen > k)
				{
					a[i] = ((a[i] == '0') ? '1' : '0');
					flen = 1;
					ans++;
				}
				prev = a[i];
			}
			if(ans > N - ans)
			{
				ans = N - ans;
				for(int i = 0; i < N; i++)
					a[i] = ((a[i] == '0') ? '1' : '0');
			}
		}
		else
		{
			memset(end, 0, sizeof(end));
			ll flen = 1;
			for(int i = 1; i < N; i++)
			{
				if(a[i] == a[i - 1])
					flen++;
				else
				{
					flen = 1;
					end[i - 1] = 1;
				}
			}
			end[N - 1] = 1;
			flen = 1;
			ans = 0;
			for(int i = 0; i < N; i++)
			{
				if(end[i] == 0)
				{
					if(flen % (k + 1) == 0)
						a[i] = ((a[i] == '0') ? '1' : '0');
					flen++;
				}
				else
				{
					if(flen % (k + 1) == 0)
						a[i - 1] = ((a[i - 1] == '0') ? '1' : '0');
					ans += flen / (k + 1);
					flen = 1;
				}
			}
		}
		printf("%lld\n%s\n", ans, a);
	}
	return 0;
}