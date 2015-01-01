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
char g[1010][1010];
int T, N, ans;
int blocks[1010];
int main()
{
	si(T);
	getchar();
	while(T--)
	{
		si(N);
		getchar();
		for(int i = 0; i < N; ++i)
		{
			ss(g[i]);
			getchar();
		}
		for(int i = 0; i < N; ++i)
		{
			blocks[i] = 0;
			for(int j = N - 1; j >= 0; j--)
			{
				if(g[j][i] == '#')
				{
					blocks[i] = j + 1;
					break;
				}
			}
		}
		ans = N * N;
		/*for(int i = 0; i < N; ++i)
			printf("%d ", blocks[i]);
		printf("\n");*/
		for(int i = 0; i < N; ++i)
		{
			for(int j = N - 1; j >= 0; j--)
			{
				if(g[i][j] == '#')
				{
					ans -= j + 1;
					break;
				}
				if(blocks[j] >= i + 1)
					ans--;
			}
			//printf("%d = %d\n", i, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}