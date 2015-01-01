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
int a[1000000];
bool isSq[1000001];
int sorta[1000001];
int T, N, K;
ll ans;
FastInput fi;
int main()
{
	memset(isSq, 0, sizeof(isSq));
	for(int i = 2; i <= 1000; i++)
		isSq[i * i] = true;
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		for(int i = 0; i < N; ++i)
			a[i] = fi.ReadNext();
		K = 0;
		for(int i = 0; i < N; i++)
		{
			if(isSq[__gcd(a[i], i + 1)])
				K++;
		}
		memset(sorta, 0, sizeof(sorta));
		for(int i = 0; i < N; i++)
			sorta[a[i]]++;
		ans = 1LL;
		int j = 1000000;
		while(K > 0)
		{
			if(sorta[j] > 0)
			{
				ans = (ans * j) % MOD;
				sorta[j]--;
				K--;
			}
			else
				j--;
		}
		printf("%lld\n", ans);
	}
	return 0;
} 