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
#include<stdint.h>
#include<unistd.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
 
class FastInput {
	public:
		FastInput() {
			m_dataOffset = 0;
			m_dataSize = 0;
			m_v = 0x80000000;
		}
		uint32_t ReadNext() {
			if (m_dataOffset == m_dataSize) {
				int r = read(0, m_buffer, sizeof(m_buffer));
				if (r <= 0) return m_v;
				m_dataOffset = 0;
				m_dataSize = 0;
				int i = 0;
				if (m_buffer[0] < '0') {
					if (m_v != 0x80000000) {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
					}
					for (; (i < r) && (m_buffer[i] < '0'); ++i);
				}
				for (; i < r;) {
					if (m_buffer[i] >= '0') {
						m_v = m_v * 10 + m_buffer[i] - 48;
						++i;
					} else {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
						for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
					}
				}
			}
			return m_data[m_dataOffset++];
		}
	public:
		uint8_t m_buffer[32768];
		uint32_t m_data[16384];
		size_t m_dataOffset, m_dataSize;
		uint32_t m_v;
};

inline long long fastmod(long long a, long long m)
{
	if(a < m)
		return a;
	return a % m;
}
 
inline long long powmod(long long a, long long b, long long m)
{
	if(b == 0)
		return 1 % m;
	long long prod = 1;
	long long s = a;
	while(b)
	{
		if(b & 1)
			prod = fastmod(prod * s, m);
		b>>=1;
		s = fastmod(s * s, m);
	}
	return prod;
}
vector<ll> primes;
int isComp[100001];
inline void eratosthenes_sieve()
{
	primes.reserve(9600);
	memset(isComp, 0, sizeof(isComp));
	for(ll i=2; i<= 100000; i++)
		if(!isComp[i])
		{	
			primes.push_back(i);
			for(ll k = i * i; k <= 100000; k += i)
				isComp[k] = true;
		}
}

ll f[100001];
ll T, N, ans, M, Q, r;
FastInput fi;
inline ll removepow(ll N, ll M)
{
	while(__gcd(N, M) != 1)
		N /= __gcd(N, M);
	return N;
}
inline void precompute(ll M)
{
	if(M == 1)
		return;
	f[1] = 1;
	for(ll i = 2; i <= N; i++)
		f[i] = (f[i - 1] * powmod(removepow(i, M), i, M)) % M;
}
ll countPow(ll n, ll p, ll r)
{
	ll k = 0, pk = p;
    while(n > pk)
    {
        k += pk * (((n/pk) * (n/pk + 1) - (r/pk) * (r/pk + 1) - ((n-r)/pk) * ((n-r)/pk + 1)) / 2);
        pk *= p;
		if (k > 0)
			return 1;
    }
    return k;
}
vector<ll> factors;
void factorize(ll N) //spits out unique factors of N into the vector factors[]
{
	factors.clear();
	for(int j = 0; j < primes.size() && primes[j] * primes[j] <= N; j++)
	{
		if(N <= 1)
			return;
		if(N % primes[j] == 0)
			factors.push_back(primes[j]);
		while(N % primes[j] == 0)
			N /= primes[j];
	}
	factors.push_back(N);
}
int main()
{
	eratosthenes_sieve();
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		M = fi.ReadNext();
		precompute(M);
		factorize(M);
		Q = fi.ReadNext();
		for(int i = 0; i < Q; i++)
		{
			r = fi.ReadNext();
			if(M == 1)
				ans = 0;
			else
			{
				ans = f[N];
				ans = (ans * powmod(f[r], M - 2, M)) % M;
				ans = (ans * powmod(f[N - r], M - 2, M)) % M;
				for(int j = 0; j < factors.size(); j++)
				{
					ans = (ans * powmod(factors[j], countPow(N, factors[j], r), M)) % M;
					if (ans == 0)
						break;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
