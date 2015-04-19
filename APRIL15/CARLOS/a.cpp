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
int m[201][201];
int a[200000];
int dp[200001];
int T, N, M, K, ans, x, y;
FastInput fi;
inline void warshall()
{
	for(int k = 1; k <= M; k++)
		for(int i = 1; i <= M; i++)
			for(int j = 1; j <= M; j++)
				m[i][j] = m[i][j] | (m[i][k] && m[k][j]);
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		memset(m, 0, sizeof(m));
		M = fi.ReadNext();
		K = fi.ReadNext();
		N = fi.ReadNext();
		for(int i = 0; i < K; ++i)
		{
			int x = fi.ReadNext();
			int y = fi.ReadNext();
			m[x][y] = m[y][x] = 1;
		}
		warshall();
		for(int i = 0; i < N; i++)
			a[i] = fi.ReadNext();
		ans = 0;
		dp[0] = 0;
		for(int i = 1; i <= N; i++)
			dp[i] = INT_MAX - 1;
		for(int j = 1; j <= M; j++)
		{
			for(int i = 1; i <= N; i++)
			{
				if(a[i - 1] == j)
					dp[i] = min(dp[i - 1], dp[i]);
				else if(m[a[i - 1]][j])
					dp[i] = min(dp[i - 1] + 1, dp[i]);
			}
		}
		if(dp[N] != INT_MAX - 1)
			printf("%d\n", dp[N]);
		else
			printf("-1\n");
	}
	return 0;
}