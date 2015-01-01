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
 
int T, N, M;
int C[40], P[40];
FastInput fi;
double cost, subcost;
int numsets;
double subsetcost(long long subset)
{
	double subscost = 0.0;
	for(int i = 0; i < N; ++i)
	{
		if(subset & (1LL << i))
		{
			subscost += P[i];
		}
	}
	//printf("%lld - %lf\n", subset, subscost);
	return subscost;
}
int countcolors(long long subset)
{
	int cols[41] = {0};
	for(int i = 0; i < N; ++i)
	{
		if(subset & (1LL << i))
		{
			cols[C[i]] = 1;
		}
	}
	int c = 0;
	for(int i = 1; i <= N; ++i)
	{
		c += cols[i];
	}
	return c;
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		M = fi.ReadNext();
		for(int i = 0; i < N; ++i)
		{
			C[i] = fi.ReadNext();
			P[i] = fi.ReadNext();
		}
		cost = 0.0;
		subcost = 0.0;
		numsets = 0;
		for(int k = M; k < N; ++k)
		{
			subcost = 0.0;
			for(long long subset = 0; subset < (1<<N); ++subset)
			{
				if(countcolors(subset) == k)
				{
					subcost += subsetcost(subset);
					numsets += 1;
					printf("subset=%d, k=%d, subsetcost:%0.4lf\n", subset, k, subsetcost(subset));
				}
			}
			printf("subcost = %0.7lf\n", subcost);
			cost += subcost;
		}
		printf("cost: %0.7lf numsets:%d\n", cost, numsets);
		//printf("%0.7lf\n", cost / numsets);
	}
	return 0;
} 