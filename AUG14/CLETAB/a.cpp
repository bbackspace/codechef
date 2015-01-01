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
typedef multimap<int, int> mmii;
typedef pair<int, int> pii;

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
int count_unique(int C[], int M)
{
	int h[401] = {0};
	for(int i = 0; i < M; i++)
		h[C[i]] = 1;
	int c = 0;
	for(int i = 1; i <= 400; i++)
		c += h[i];
	return c;
}
int T, N, M, ans;
int C[400];
int tables[201];
int custTable[401];
mmii indices;
FastInput fi;

int nextIndex(int c, int currindex)
{
	for(mmii::iterator it = indices.find(c); it != indices.end() && it->first == c; it++)
		if(it->second > currindex)
			return it->second;
	return INT_MAX;
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		M = fi.ReadNext();
		for(int i = 0; i < M; ++i)
			C[i] = fi.ReadNext();

		int cu = count_unique(C, M);
		if(N >= cu)
			printf("%d\n", cu);
		else
		{
			ans = 0;
			indices.clear();
			for(int i = 0; i < M; i++)
				indices.insert(pii(C[i], i));
			//for(mmii::iterator it = indices.begin(); it != indices.end(); it++)
				//printf("%d - %d, ", it->first, it->second);
			for(int j = 1; j <= N; j++)
				tables[j] = -1;
			for(int k = 1; k <= 400; k++)
				custTable[k] = -1;
			for(int i = 0; i < M; i++)
			{
				if(custTable[C[i]] == -1)
				{
					ans++;
					int j;
					for(j = 1; j <= N; j++)
						if(tables[j] == -1)
						{
							custTable[C[i]] = j;
							tables[j] = C[i];
							break;
						}
					if(j <= N)
						continue;
					int max = 0, maxval = INT_MIN;
					for(int j = 1; j <= N; j++)
					{
						int next = nextIndex(tables[j], i);
						if(maxval < next)
						{
							max = j;
							maxval = next;
						}
					}
					custTable[C[i]] = max;
					custTable[tables[max]] = -1;
					tables[max] = C[i];
				}
				/*
				printf("[i=%d]", i);
				for(int k = 1; k <= 10; k++)
					printf("%d ", custTable[k]);
				printf("|");
				for(int k = 1; k <= N; k++)
					printf("%d ", tables[k]);
				printf("\n");*/
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}