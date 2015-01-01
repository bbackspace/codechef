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
int N, T;
FastInput fi;
struct que
{
	int m;
	int t;
} exam[1001];
vector<int> set;
int DP[1001][10001];
int DP2[1001][10001];
int max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}
int max(int a, int b, int c)
{
	return max(a,max(b,c));
}
int main()
{
	N = fi.ReadNext();
	T = fi.ReadNext();
	for(int i = 1; i <= N; ++i)
		exam[i].m = fi.ReadNext();
	for(int i = 1; i <= N; ++i)
		exam[i].t = fi.ReadNext();
	for(int i = 0; i <= N; ++i)
	{
		for(int j = 0; j <= T; ++j)
		{
			if (i==0 || j==0)
				DP[i][j] = 0;
			else if (exam[i].t <= j)
				DP[i][j] = max(exam[i].m + DP[i-1][j-exam[i].t],  DP[i-1][j]);
			else
				DP[i][j] = DP[i-1][j];
			
			if (i==0 || j==0)
				DP2[i][j] = 0;
			else if (exam[i].t <= j)
				DP2[i][j] = max(2 * exam[i].m + DP[i-1][j-exam[i].t], exam[i].m + DP2[i-1][j-exam[i].t], DP2[i-1][j]);
			else
				DP2[i][j] = DP2[i-1][j];
		}
	}
	
	printf("%d\n", DP2[N][T]);
	return 0;
}