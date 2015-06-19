#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
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
#define MOD 1000000007
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
ll T, N, K, ans;
FastInput fi;
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
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		K = fi.ReadNext();
		ll t1 = ((K * K * (powmod(K, 2 * N, MOD) + MOD - 1)) % MOD) * powmod(K * K - 1, MOD - 2, MOD);
		t1 = t1 % MOD;
		//printf("%lld\n", t1);
		ll t2 = ((K * K * (t1 + MOD - N)) % MOD) * powmod(K * K - 1, MOD - 2, MOD);
		t2 = t2 % MOD;
		//printf("%lld\n", t2);
		ll t3 = ((K * (powmod(K, N, MOD) + MOD - 1)) % MOD) * powmod(K - 1, MOD - 2, MOD);
		t3 = t3 % MOD;
		//printf("%lld\n", t3);
		ll t4 = ((2 * K * (t3 + MOD - N)) % MOD) * powmod(K - 1, MOD - 2, MOD);
		t4 = t4 % MOD;
		//printf("%lld\n", t4);
		ll t5 = ((N * (N + 1)) % MOD) * powmod(2, MOD - 2, MOD);
		t5 = t5 % MOD;
		//printf("%lld\n", t5);
		ll t6 = ((K * ((t2 + t5 + MOD - t4) % MOD)) % MOD) * powmod(K - 1, MOD - 2, MOD);
		t6 = t6 % MOD;
		//printf("%lld\n", t6);
		ll t7 = ((((N * (N + 1)) % MOD) * (N + 2)) % MOD) * powmod(6, MOD - 2, MOD);
		t7 = t7 % MOD;
		//printf("%lld\n", t7);
		ans = t6 + MOD - t7;
		ans = (6 * ans) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}