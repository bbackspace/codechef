#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
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

FastInput fi;
int T, N, k, S;
int A[2000];
int p[2000];
int f(int i)
{
	int ret = S;
	i--;
	while(ret - A[p[i]] > 0)
	{
		ret -= A[p[i]];
		i++;
	}
	return ret;
}
int cost()
{
	int sum=0;
	for(int i = 1; i <= k; ++i)
		sum += f(i);
	return sum;
}
void perm()
{
	multimap<int, int> m;
	for(int i = 0; i < N; ++i)
	{
		m.insert(make_pair(A[i],i + 1));
	}
	multimap<int, int>::iterator pos;
	int i;
	for(pos = m.begin(), i = 0; pos != m.end(); ++pos, ++i)
		p[i] = pos->second;
}
int minp[2000];
void arraycopy(int dest[], int src[], int N)
{
	while(N--)
	*dest++ = *src++;
}
bool improve()
{
	int iter = 0;
	int primacost = cost();
	int mincost = primacost;
	int newcost;
	while(prev_permutation(p, p + N) && iter < 80)
	{
		newcost = cost();
		/*printf("p = [ ");
		for(int i = 0; i < N; ++i)
			printf("%d ", p[i]);
		printf("] cost:%d\n", newcost);
		*/
		if(newcost < mincost)
		{
			arraycopy(minp, p, N);
			mincost = newcost;
		}
		iter++;
	}
	//printf("primacost: %d, mincost: %d. ", primacost, mincost);
	return mincost != primacost;
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		k = fi.ReadNext();
		S = fi.ReadNext();
		for(int i = 0; i < N; ++i)
			A[i] = fi.ReadNext();
		perm();
		if(improve())
			for(int i = 0; i < N; ++i)
				printf("%d ", minp[i]);
		else
			for(int i = 0; i < N; ++i)
				printf("%d ", p[i]);
		printf("\n");
	}
	return 0;
}