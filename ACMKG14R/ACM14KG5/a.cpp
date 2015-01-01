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
ll DP[10000][10000];
ll T, N, K, ans;
FastInput fi;
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		K = fi.ReadNext();
		if(N == 1)
			printf("-1\n");
		else
		{
			for(int last = 1; last <= K; last++)
				DP[1][last] = 1;
			for(int i = 2; i <= N; i++)
			{
				for(ll last = 1; last <= K; last++)
				{
					DP[i][last] = 0;
					for(int j = 1; j <= min(last, K/last); j++)
						DP[i][last] = (DP[i][last] + DP[i - 1][j]) % MOD;
				}
			}
			for(int i = 1; i <= N; i++)
			{
				for(int j = 1; j <= K; j++)
					printf("%lld ", DP[i][j]);
				printf("\n");
			}
			ans = 0;
			for(int j = 1; j <= K; j++)
				ans = (ans + DP[N][j]) % MOD;
			printf("%lld\n", ans);
		}
	}
	return 0;
} 