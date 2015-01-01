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
using namespace std;

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
int a[100010];
int d[100010];
int m[100010];
int set[100010];
int T, N, M, L, R, ans;
FastInput fi;
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		ans = 1;
		memset(d, 0, sizeof(d));
		N = fi.ReadNext();
		M = fi.ReadNext();
		for(int i = 1; i <= N; i++)
			a[i] = fi.ReadNext();
		for(int j = 0; j < M; j++)
		{
			L = fi.ReadNext();
			R = fi.ReadNext();
			d[L] += 1;
			d[R] -= 1;
		}
		int c = 0;
		for(int i = 1; i <= N; i++)
		{
			c += d[i];
			if(c == 0 && d[i] == 0)
				m[i] = 0;
			else
				m[i] = 1;
		}
		int s = 0;
		m[0] = 0;
		for(int i = 1; i <= N; i++)
		{
			if(m[i] == 1 && m[i - 1])
				d[i] = s;
			else
			{
				d[i] = ++s;
				set[s] = i;
			}
			//printf("%d ", d[i]);
		}
		/*printf("\n");
		for(int i = 1; i <= s + 1; i++)
			printf("%d ", set[i]);
		printf("\n");*/
		set[s + 1] = N + 1;
		for(int i = 1; i <= s; i++)
		{
			for(int j = set[i]; j < set[i + 1]; j++)
				if(a[j] < set[i] || a[j] >= set[i + 1])
				{
					ans = 0;
					break;
				}
			if(ans == 0)
				break;
		}
		printf(ans ? "Possible\n" : "Impossible\n");
	}
	return 0;
}