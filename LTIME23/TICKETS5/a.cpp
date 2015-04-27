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
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()

char s[100000];
int T, N, ans;
int main()
{
	si(T);
	while(T--)
	{
		sline(s);
		ans = 1;
		for(int i = 2; s[i]; i++)
		{
			if(s[i] != s[i - 2] || s[i] == s[i - 1])
			{
				ans = 0;
				break;
			}
		}
		if(ans && s[0] != s[1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}