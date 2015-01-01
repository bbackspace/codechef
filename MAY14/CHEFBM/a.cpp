#include<cstdio>
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

map<int, int> a[100000];
int n, m, p, i, j, cost;
FastInput fi;
int main()
{
	n = fi.ReadNext();
	m = fi.ReadNext();
	p = fi.ReadNext();
	for(int k = 0; k < p; ++k)
	{
		i = fi.ReadNext() - 1;
		j = fi.ReadNext();
		if(a[i].count(j) == 0)
			a[i][j] = 1;
		else
			a[i][j] = a[i][j] + 1;
	}
	for(i = 0; i < n; ++i)
	{
		map<int, int>::iterator it;
		if(a[i].count(m) > 0)
			cost = a[i][m] + m;
		else
			cost = m;
		if(a[i].count(1) > 0)
			cost -= a[i][1] + 1;
		else
			cost--;
		
		for(it = a[i].begin(); it != a[i].end(); it++)
		{
			j = it->first;
			if(j == m)
				break;
			int suc = 0;
			if(a[i].count(j + 1) > 0)
				suc = a[i][j + 1];
			if(it -> second > suc + 1)
			{
				cost = -1;
				break;
			}
		}
		printf("%d\n", cost);
	}
	return 0;
}