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
using namespace std;
typedef long long ll;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
inline ll fastmod(ll a, ll m)
{
	if(a < m)
		return a;
	return a % m;
}
inline ll bigpowmod(ll a, ll b, ll m)
{
	if(b == 0)
		return 1 % m;
	ll prod = 1;
	ll s = a;
	while(b)
	{
		if(b & 1)
			prod = fastmod(prod * s, m);
		b>>=1;
		s = fastmod(fastmod(s, m) * s, m);
	}
	return prod;
}

inline ll powmod(ll a, ll b, ll m)
{
	if (a > 3037000499LL && b > 1)
		return bigpowmod(a, b, m);
	if(b == 0)
		return 1 % m;
	ll prod = 1;
	ll s = a;
	while(b)
	{
		if(b & 1)
			prod = fastmod(prod * s, m);
		b>>=1;
		s = fastmod(s * s, m);
	}
	return prod;
}

ll sumiter(ll n, ll m)
{
	ll s = 0;
	for(ll i = 1; i <= n; i++)
		s = fastmod(s + fastmod(powmod(i, 4, m) * (n/i), m), m);
	return s;
}

ll sum(ll n, ll m) //returns sum(i^4) for 1<=i<=n
{
	ll m30 = m * 30;
	ll s = fastmod(powmod(n, 5, m30) * 6, m30);
	s = fastmod(s + fastmod(powmod(n, 4, m30) * 15, m30), m30);
	s = fastmod(s + fastmod(powmod(n, 3, m30) * 10, m30), m30);
	s = fastmod(s + m30 - fastmod(n, m30), m30);
	return fastmod(s / 30, m);
}
ll isqrt(ll n, ll approx)
{
	ll next = (approx + n / approx) / 2;
	ll eps = next - approx;
	if (eps == 0 || eps == -1)
		return next;
	return isqrt(n, next);
}
ll T, N, M, ans;
int main()
{
	si(T);
	while(T--)
	{
		sll(N);
		si(M);
		//ll sroot = isqrt(N, (long long)sqrt((double)N));
		ll sroot = (long long)sqrt((double)N);
		ans = 0LL;
		for(ll i = 1; i <= sroot; i++)
		{
			ans = fastmod(ans + sum(N/i, M), M);
		}
		ll last = sroot, next;
		for(ll i = N/sroot - 1; i >= 1; i--)
		{
			next = N/i;
			ans = fastmod(ans + fastmod(sum(i, M) * (next - last), M), M);
			last = next;
		}
		printf("%lld\n", ans);
	}
	return 0;
}