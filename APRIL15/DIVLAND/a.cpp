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
pair<int, pair<int, int> > edge[1000000];
int T, N, M, ans;
FastInput fi;
struct subset
{
    int parent;
    int rank;
} subsets[1000000];

int find(int i)
{
	if(subsets[i].parent == i)
		return i;
	else
		return subsets[i].parent = find(subsets[i].parent);
}

void Union(int x, int y)
{
	int xroot = find(x);
	int yroot = find(y);

	if(xroot == yroot)
		return;
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int main()
{
	N = fi.ReadNext();
	M = fi.ReadNext();
	for(int i = 0; i < M; ++i)
	{
		edge[i].second = pair<int, int>(fi.ReadNext(), fi.ReadNext());
		edge[i].first = fi.ReadNext();
	}
	/*sort(edge, edge + M);
	int lastx = -1, lasty = -1;
	for(int i = M - 1; i > M/2; i--)
	{
		int x = edge[i].second.first;
		int y = edge[i].second.second;
		Union(x, y);
		//lastx = x;
		//lasty = y;
	}
	vector<int> a, b;
	int pa = -1, pb = -1;
	for(int i = 0; i < N; i++)
	{
		if(pa = -1)
		{
			pa = find(i);
			a.push_back(i);
		}
		else if(pa == find(i))
			a.push_back(i);
		else if(pb == -1)
		{
			pb = find(i);
			b.push_back(i);
		}
		else if(pb = find(i))
			b.push_back(i);
		else
		{
			if(a.size() <= b.size())
			{
				Union(pa, i);
				a.push_back(i);
			}
			else
			{
				Union(pb, i);
				b.push_back(i);
			}
		}
	}
	if(a.size() >= N/2)
		for(int i = 0; i < N/2; i++)
			printf("%d ", a[i]);
	else
		for(int i = 0; i < N/2; i++)
			printf("%d ", b[i]);*/
	int i;
	for(i = 0; i + 7 < N; i+=8)
		printf("%d %d %d %d ", i, i + 1, i + 5, i + 4);
	for(; i < N; i+=2)
		printf("%d ", i);
	return 0;
}