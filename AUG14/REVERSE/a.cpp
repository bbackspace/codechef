#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cassert>
#include<algorithm>
#include<vector>
#include<map>
#include<deque>
#include<stdint.h>
#include<unistd.h>
using namespace std;
typedef multimap<int, int> mmii;
typedef pair<int, int> pii;

//#define DEBUG
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
mmii in;
mmii out;
deque<int> vqueue;
int N, M;
int dp[100001];
int visited[100001];
FastInput fi;
int main()
{
	N = fi.ReadNext();
	assert(N >= 1 && N <= 100000);
	M = fi.ReadNext();
	assert(M >= 1 && M <= 100000);
	dp[1] = 0;
	visited[1] = 0;
	for(int i = 2; i <= N; i++)
	{
		dp[i] = INT_MAX;
		visited[i] = 0;
	}
	for(int e = 0; e < M; e++)
	{
		int from = fi.ReadNext();
		int to = fi.ReadNext();
		assert(from >= 1 && from <= N);
		assert(to >= 1 && to <= N);
		in.insert(pii(from, to));
		out.insert(pii(to, from));
	}
#ifdef DEBUG
	printf("IN\n");
	for(mmii::iterator it = in.begin(); it != in.end(); it++)
		printf("%d -> %d\n", it->first, it-> second);
	printf("OUT\n");
	for(mmii::iterator it = out.begin(); it != out.end(); it++)
		printf("%d -> %d\n", it->first, it-> second);
#endif
	vqueue.push_back(1);
	while(!vqueue.empty())
	{
		int v = vqueue.front();
		vqueue.pop_front();
		if(visited[v])
			continue;
		for(mmii::iterator it = in.find(v); it != in.end() && it->first == v; it++)
		{
			if(dp[it->second] > dp[v])
			{
				dp[it->second] = dp[v];
				visited[it->second] = 0;
			}
			vqueue.push_back(it->second);
		}
		for(mmii::iterator it = out.find(v); it != out.end() && it->first == v; it++)
		{
			if(dp[it->second] > dp[v] + 1)
			{
				dp[it->second] = dp[v] + 1;
				visited[it->second] = 0;
			}
			vqueue.push_back(it->second);
		}
		visited[v] = 1;
	}
	if(dp[N] != INT_MAX)
	{
		assert(0 <= dp[N] && dp[N] <= N);
		printf("%d\n", dp[N]);
	}
	else
		printf("-1\n");
#ifdef DEBUG
	for(int i = 1; i <= N; i++)
		printf("%d ", dp[i]);
	printf("\n");
#endif
	return 0;
}