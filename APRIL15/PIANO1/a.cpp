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
char s[101];
int T, N, ans;
int main()
{
	si(T);
	while(T--)
	{
		ss(s);
		si(N);
		int window = 0;
		for(int i = 0; s[i]; i++)
			if(s[i] == 'S')
				window ++;
			else
				window += 2;
		ans = 0;
		for(int i = window; i <= 12 * N; i += window)
			ans += 12 * N - i;
		printf("%d\n", ans);
	}
	return 0;
}