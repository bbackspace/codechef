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

ll T, X, K, num, den;
ll twotofloorlog2(ll x)
{
	while(x & (x - 1))
		x = x & (x - 1);
	return x;
}
int main()
{
	sll(T);
	while(T--)
	{
		sll(X);
		sll(K);
		num = (1 + 2 *(K - twotofloorlog2(K)));
		den = 2 * twotofloorlog2(K);
		printf("%lf\n", ((double)X * num) / den);
	}
	return 0;
} 