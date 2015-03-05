#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define sll(x) scanf("%lld", &(x))
ll fact[10000001];
ll sumfact[10000001];
ll M, N;
ll P, ans = 0;
ll sigman(ll n)
{
	ll x;
	if(n % 2 == 0)
	{
		x = n + 1;
		n = n / 2;
	}
	else
	{
		x = (n + 1) / 2;
	}
	return ((x % M) * (n % M)) % M;
}
int main()
{
	sll(N);
	sll(M);
	fact[0] = 1;
	for(int i = 1; i <= max(10LL, M); i++)
		fact[i] = (i * fact[i - 1]) % M;
	sumfact[0] = 0;
	for(int i = 1; i <= max(10LL, M); i++)
		sumfact[i] = ((i * fact[i]) % M + sumfact[i - 1]) % M;
	for(int i = 0; i < N; i++)
	{
		sll(P);
		ans = (ans + sumfact[min(P, M - 1)]) % M;
		ans = (ans + (sigman(P) * (P % M)) % M) % M;
	}
	printf("%lld\n", ans);
	return 0;
}