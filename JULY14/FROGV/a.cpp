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

#define pii pair<int, int>
#define mmii multimap<int, int>

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
int A[100000];
int CC[100000];
mmii m;
int N, K, P;
FastInput fi;
int main()
{
	N = fi.ReadNext();
	K = fi.ReadNext();
	P = fi.ReadNext();
	for(int i = 0; i < N; i++)
	{
		A[i] = fi.ReadNext();
		m.insert(pii(A[i], i + 1));
	}
	mmii::iterator it = m.begin();
	int last = it -> first;
	int ccnum = 1;
	CC[it -> second - 1] = 1;
	
	for(it++; it != m.end(); it++)
	{
		if(it -> first - last > K)
			ccnum++;
		CC[it ->second - 1] = ccnum;
		last = it -> first;
	}
	for(int i = 0; i < P; i++)
	{
		int a = fi.ReadNext();
		int b = fi.ReadNext();
		if (CC[a - 1] == CC[b - 1])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}