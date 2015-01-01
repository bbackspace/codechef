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
int S[10001];
class Subset
{
public:
	int rank;
	int parent;
};

Subset subsets[10001];

int Find(int i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = Find(subsets[i].parent);
	return subsets[i].parent;
}

int Union(int x, int y)
{
	int xroot = Find(x);
	int yroot = Find(y);

	// Attach smaller rank tree under root of high rank tree
	// (Union by Rank)
	if (subsets[xroot].rank < subsets[yroot].rank)
	{
		subsets[xroot].parent = yroot;
		return yroot;
	}
	else if (subsets[xroot].rank > subsets[yroot].rank)
	{
		subsets[yroot].parent = xroot;
		return xroot;
	}

	// If ranks are same, then make one as root and increment
	// its rank by one
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
		return xroot;
	}
}
int T, N, Q;
FastInput fi;
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		for(int i = 1; i <= N; i++)
		{
			S[i] = fi.ReadNext();
			subsets[i].parent = i;
			subsets[i].rank = 0;
		}
		Q = fi.ReadNext();
		for(int i = 0; i < Q; i++)
		{
			int qtype = fi.ReadNext();
			if(qtype == 0)
			{
				int x = fi.ReadNext();
				int y = fi.ReadNext();
				int chefx = Find(x);
				int chefy = Find(y);
				if(chefx == chefy)
				{
					printf("Invalid query!\n");
				}
				else
				{
					if(S[chefx] > S[chefy])
					{
						subsets[Union(x, y)].parent = chefx;
						subsets[chefx].parent = chefx;
					}
					else if (S[chefx] < S[chefy])
					{
						subsets[Union(x, y)].parent = chefy;
						subsets[chefy].parent = chefy;
					}
				}
			}
			else
			{
				//printf("[%d %d]\n", subsets[1].parent, subsets[2].parent);
				printf("%d\n", Find(fi.ReadNext()));
			}
		}
	}
	return 0;
}