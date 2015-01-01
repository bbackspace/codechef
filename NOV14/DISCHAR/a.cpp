#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<iomanip>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)

int h[128];
int T, ans;
char str[100001];
int main()
{
	si(T); getchar();
	while(T--)
	{
		memset(h, 0, sizeof(h));
		ss(str); getchar();
		for(int i = 0; str[i]; ++i)
			h[str[i]] = 1;
		ans = 0;
		for(int i = 0; i < 128; i++)
			ans += h[i];
		printf("%d\n", ans);
	}
	return 0;
} 