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
typedef long long ll;
int T;
ll N;
int end[23];
int start[23] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
ll count[10];
void conv(ll n)
{
	for(int i = 0; i < 23; ++i)
		end[i] = 0;
	for(int i = 0; i < 23; ++i)
	{
		end[i] = n % 10;
		n = n / 10;
	}
}

ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

void calc()
{
	memset(count, 0, 10 * sizeof(ll));
	
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &N);
		conv(N);
		calc();
		long long P = 0, Q = N * 10;
		for(int i = 0; i <= 9; ++i)
			P += count[i];
		long long GCD = gcd(P, Q);
		printf("%lld/%lld\n", P/GCD, Q/GCD);
	}
	return 0;
}