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
#define MOD 1000003
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
inline ll fastmod(ll a, ll m)
{
	if(a < m)
		return a;
	return a % m;
}

inline ll powmod(ll a, ll b, ll m)
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
		s = fastmod(s * s, m);
	}
	return prod;
}
ll fact[MOD+1];
ll invfact[MOD+1];
void precompute_fact()
{
	fact[0] = 1;
	invfact[0] = 1;
	for(int i = 1; i <= MOD; i++)
	{
		fact[i] = (i * fact[i - 1]) % MOD;
		invfact[i] = (powmod(i, MOD - 2, MOD) * invfact[i - 1]) % MOD;
	}
}
ll choose(ll n, ll k) //computes choose(n, k) % MOD for small constant prime MOD, large n, r
{
	if(k > n)
		return 0;
	if(n < MOD)
		return (((fact[n] * invfact[n - k]) % MOD) * invfact[k]) % MOD;
	return (choose(n / MOD, k / MOD) * choose(n % MOD, k % MOD)) % MOD;
}

int T, N, L, R, ans;
FastInput fi;
int main()
{
	precompute_fact();
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		L = fi.ReadNext();
		R = fi.ReadNext();
		printf("%lld\n", (choose(R - L + 1 + N, N) + MOD - 1) % MOD);
	}
	return 0;
}