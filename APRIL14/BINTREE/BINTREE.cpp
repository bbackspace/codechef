#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<stdint.h>
#include<unistd.h>
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
unsigned N, i, j, t, dist, fbiti, fbitj;
unsigned firstBit(unsigned x)
{
	unsigned i = 0;
	while(x)
	{
		x>>=1;
		++i;
	}
	return i - 1;
}
int main()
{
	N = fi.ReadNext();
	while(N--)
	{
		i = fi.ReadNext();
		j = fi.ReadNext();
		if (i > j)
		{
			unsigned t = i;
			i = j;
			j = t;
		}
		dist = firstBit(j) - firstBit(i);
		j >>= dist;
		while(i != j)
		{
			i >>= 1;
			j >>= 1;
			dist+=2;
		}
		printf("%u\n", dist);
	}
	return 0;
}
