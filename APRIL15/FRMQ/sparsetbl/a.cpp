#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cassert>
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
int ST[18][100010];
ll a[100010];
ll N, M, Nm1;
ll ans;
FastInput fi;
int p, q;
void initST()
{
	for(int i = 0; i < N; i++)
		ST[0][i] = i;
	for (int k = 1; (1 << k) <= N; k++)
	{
		for (int i = 0; i - 1 + (1 << k) < N; i++)
		{
			p = ST[k - 1][i];
			q = ST[k - 1][i + (1 << (k - 1))];
			if (a[p] > a[q])
				ST[k][i] = p;
			else
				ST[k][i] = q;
		}
	}
}
inline int fastmod(int a, int m)
{
	if(a < m)
		return a;
	else
		return a - m;
}
inline int queryST(int A, int B)
{
	int s = 31 - __builtin_clz(B - A + 1);
	return max(a[ST[s][A]], a[ST[s][B + 1 - (1 << s)]]);
}
int log2[100001];
int pow2[100001];
int main()
{
	N = fi.ReadNext();
	Nm1 = N - 1;
	for(int i = 0; i < N; ++i)
		a[i] = fi.ReadNext();
	M = fi.ReadNext();
	register int x, y, s;
	x = fi.ReadNext();
	y = fi.ReadNext();
	initST();
	if(M > 100000)
	{
		for(int i = 1; i <= 100000; i++)
			log2[i] = 31 - __builtin_clz(i);
		for(int i = 0; i <= 18; i++)
			pow2[i] = 1 << i;
		ans = queryST(min(x, y), max(x, y));
		int i;
		for(i = 2; i + 31 <= M; i += 32)
		{
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
			x = fastmod(x + 7, Nm1);
			y = fastmod(y + 11, N);
			if(x <= y)
			{
				s = log2[y - x + 1];
				ans += max(a[ST[s][x]], a[ST[s][y + 1 - pow2[s]]]);
			}
			else
			{
				s = log2[x - y + 1];
				ans += max(a[ST[s][y]], a[ST[s][x + 1 - pow2[s]]]);
			}
		}
		for(; i <= M; i++)
		{
			x = (x + 7) % (Nm1);
			y = (y + 11) % N;
			ans += queryST(min(x, y), max(x, y));
		}
	}
	else
	{
		ans = queryST(min(x, y), max(x, y));
		for(int i = 2; i <= M; i++)
		{
			x = (x + 7) % (Nm1);
			y = (y + 11) % N;
			ans += queryST(min(x, y), max(x, y));
		}
	}
	printf("%lld\n", ans);
	return 0;
}