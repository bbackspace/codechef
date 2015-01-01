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
ll T, N, ans, M, Q, r;
FastInput fi;
void EE(ll a, ll b, ll& x, ll& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    ll temp = x;
    x = y;
    y = temp - y*(a/b);
}

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
		M = fi.ReadNext();
		f[1] = 1;
		invf[1] = powmod(1, M - 2, M);
		for(int i = 2; i <= N; i++)
		{
			f[i] = (f[i - 1] * pow(i, i));
			invf[i] = powmod(f[i], M - 2, M);
		}
		Q = fi.ReadNext();
		for(int i = 0; i < Q; ++i)
		{
			r = fi.ReadNext();
			if(N <= 5)
			{
				printf("%lld\n", (f[N]/f[N - r]/f[r]) % M);
			}
			else
			{
				ans = (f[N] * invf[r]) % M;
				ans = (ans * invf[N - r]) % M;
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
} 