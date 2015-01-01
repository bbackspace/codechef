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

ll a[7], M;
int T, N, ans;
int numsetbits(int n)
{
	int retval = 0;
	while(n > 0)
	{
		retval++;
		n = n & (n - 1);
	}
	return retval;
}
int main()
{
	si(T);
	while(T--)
	{
		si(N);
		sll(M);
		for(int i = 0; i < N; ++i)
			sll(a[i]);
		ans = 8;
		for(int x = 0; x < (1<<N); x++)
		{
			ll sum = 0LL;
			for(int i = 0; i < N; i++)
				if(x & (1 << i))
					sum += a[i];
			if(sum >= M)
				ans = min(ans, numsetbits(x));
		}
		if(ans != 8)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	return 0;
} 