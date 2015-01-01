#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
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
unsigned T, n, k, p;
unsigned a[500];
unsigned b[500];
bool test()
{
	map<unsigned, bool> hash;
	for(int i = 0; i < k; ++i)
		hash[a[i]] = true;
	for(int i = 0; i < p; ++i)
		if(hash.count(b[i]) == 0)
			return false;
	return true;
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		n = fi.ReadNext();
		k = fi.ReadNext();
		p = fi.ReadNext();
		for(int i = 0; i < k; ++i)
		{
			a[i] = fi.ReadNext();
			fi.ReadNext();
		}
		for(int i = 0; i < p; ++i)
		{
			b[i] = fi.ReadNext();
			fi.ReadNext();
		}
		if (test())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}