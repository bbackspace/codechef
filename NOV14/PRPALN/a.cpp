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
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()
char a[100001];
int T, N, l, r;
bool ans;
bool ispalin(int l, int r)
{
	for(; l < r; l++, r--)
	{
		if(a[l] != a[r])
			return false;
	}
	return true;
}
int main()
{
	si(T);
	while(T--)
	{
		ans = true;
		ss(a);
		N = strlen(a);
		l = 0;
		r = N - 1;
		while(r - l >= 2)
		{
			if(a[l] == a[r])
			{
				l++;
				r--;
			}
			else
			{
				ans = ispalin(l + 1, r) | ispalin(l, r - 1);
				break;
			}
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
} 