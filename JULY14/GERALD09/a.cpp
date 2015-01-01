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

#ifdef ONLINEJUDGE
#define pc(x) putchar_unlocked(x)
#else
#define pc(x) putchar(x)
#endif
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
int T, N, M, K;
FastInput fi;
char code[4] = {'A', 'C', 'G', 'T'};
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		M = fi.ReadNext();
		K = fi.ReadNext();
		int p = N * M * N * M;
		if (K > p / 5)
		{
			for(int i = 0; i < N; ++i)
			{
				for(int j = 0; j < M; ++j)
						pc(code[(j + i) % 4]);
				pc('\n');
			}
		}
		else
		{
			for(int i = 0; i < N; ++i)
			{
				for(int j = 0; j < M; ++j)
						pc('A');
				pc('\n');
			}
		}
	}
	return 0;
}