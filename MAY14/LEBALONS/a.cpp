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
typedef long long ll;

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

vector<int> U[40];
int T, N, M;
int C[40], P[40];
FastInput fi;
double cost;
ll numsets;

/*int nchoosek(int n, int k)
{
	if(k < 0 || k > n)
		return 0;
    //if (k == 0) return 1;
    //return (n * nchoosek(n - 1, k - 1)) / k;
	int nck = 1;
	for(int i = 1; i <= k; ++i)
	{
		nck = (nck * (n - i + 1))/i;
	}
	return nck;
}*/
ll MultiChoose[41][41];
void buildMultiChoose(int ignore)
{
	for(int k = 0; k <= 40; ++k)
		MultiChoose[0][k] = 0;
	MultiChoose[0][0] = 1;
	for(int n = 1; n <= 40; ++n)
	{
		for(int k = 0; k <= 40; ++k)
			if(k > n)
				MultiChoose[n][k] = 0;
			else
			{
				ll L = (ignore == n - 1 ? 0 : (1LL << (U[n - 1].size())) - 1);
				MultiChoose[n][k] = MultiChoose[n - 1][k] + L * MultiChoose[n - 1][k - 1];
			}
	}
}
ll sum(vector<int> m)
{
	ll s = 0;
	for(int i = 0; i < m.size(); ++i)
	{
		s += P[m[i]];
	}
	return s;
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		M = fi.ReadNext();
		for(int i = 0; i < 40; ++i)
			U[i].clear();
		for(int i = 0; i < N; ++i)
		{
			C[i] = fi.ReadNext();
			P[i] = fi.ReadNext();
			U[C[i] - 1].push_back(i);
		}
		int K = 0;
		for(int i = 0; i < 40; ++i)
			if(!U[i].empty())
				K++;
		cost = 0.0;
		numsets = 0;
		for(int k = M; k <= K; ++k)
		{
			double subcost = 0.0;
			for(int c = 0; c < 40; ++c)
			{
				if(U[c].empty())
					continue;
				
				buildMultiChoose(c);
				/*for(int n = 0; n <= 5; ++n)
				{
					for(int k = 0; k <= 10; ++k)
						printf("%d ", MultiChoose[n][k]);
					printf("\n");
				}*/
				//printf("sum(U[c])=%'lld, MultiChoose[40][k - 1]=%lld, (1LL<<(U[c].size()-1))=%lld\n", sum(U[c]), (k>0?MultiChoose[40][k - 1]:0), (1LL<<(U[c].size()-1)));
				if(k > 0)
					subcost += (double)sum(U[c]) * MultiChoose[40][k - 1] * (1LL<<(U[c].size()-1));
			}
			//printf("k = %d subcost=%0.7lf\n", k, subcost);
			cost += subcost;
			buildMultiChoose(-1);
			numsets += MultiChoose[40][k];
			//printf("numsets:%lld\n", numsets);
		}
		//printf("cost: %0.7lf numsets:%d\n", cost, numsets);
		printf("%0.7lf\n", cost / numsets);
	}
	return 0;
}