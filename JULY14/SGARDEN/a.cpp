#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
#include<stdint.h>
#include<unistd.h>
using namespace std;

#define pii pair<int, int>
#define mii map<int, int>

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
int A[100000];
bool used[100000];
int T, N;
long long ans;
unsigned primes[10000]; //10^4 primes before 10^5
int factors[10000];

void lcm(int k)
{
	for(int i = 0; primes[i] <= k; i++)
	{
		int t = k;
		int fac = 0;
		while(t > 0 && t % primes[i] == 0)
		{
			fac++;
			t /= primes[i];
		}
		if(fac > factors[i])
			factors[i] = fac;
	}
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

FastInput fi;
int main()
{
	int k = 0;
	memset(primes, -1, 10000 * sizeof(int));
	for(int n = 2; n <= 100000; n++)
	{
		bool flag = 1;
		int s = sqrt(n);
		for(int i = 0; primes[i] <= s; i++)
			if(n % primes[i] == 0)
			{
				flag = 0;
				break;
			}
		if(flag)
		{
			primes[k++] = n;
		}
	}
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		for(int i = 0; i < N; i++)
			A[i] = fi.ReadNext() - 1;
		memset(used, 0, sizeof(used));
		memset(factors, 0, sizeof(factors));
		for(int i = 0; i < N; i++)
		{
			int k = 1;
			if(!used[i])
			{
				int j = A[i];
				while(j != i)
				{
					k++;
					used[j] = true;
					j = A[j];
				}
				lcm(k);
			}
		}
		ans = 1;
		for(int i = 0; i < 10000; i++)
		{
			ans = fastmod(ans * powmod(primes[i], factors[i], MOD), MOD);
		}
		printf("%lld\n", ans);
	}
	return 0;
}