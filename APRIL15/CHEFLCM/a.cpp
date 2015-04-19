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

#define PMAX 1000000
vector<ll> primes;
void sieve()
{
	bool isCom[PMAX + 10];
	memset(isCom, 0, sizeof(isCom));
	for(ll i = 2; i * i <= (ll)PMAX; i++)
	{
		if(!isCom[i])
		{	
			primes.push_back(i);
			for(ll k = i * i; k <= (ll) PMAX; k += i)
				isCom[k] = true;
		}
	}
}

ll factorize(ll N)
{
	ll sum = 1;
	for(int j = 0; j < primes.size() && primes[j] <= N; j++)
	{
		if(N <= 1)
			break;
		if(N % primes[j])
			continue;
		ll pa1 = primes[j];
		while(N % primes[j] == 0)
		{
			N /= primes[j];
			pa1 *= primes[j];
		}
		sum *= (pa1 - 1)/(primes[j] - 1);
	}
	return sum;
}

ll sumfactors(ll N)
{
	ll sum = 0, i = 1;
	for(i = 1; i * i < N; i++)
		if(N % i == 0)
			sum += i + (N / i);
	if(i * i == N)
		sum += i;
	return sum;
}
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
ll T, N, ans;
FastInput fi;
int main()
{
	/*sieve();
	for(int i = 0; i < 100; i++)
		printf("%lld ", primes[i]);
	printf("\n");*/
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		ans = sumfactors(N);
		printf("%lld\n", ans);
	}
	return 0;
}