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
int isprime(unsigned n)
{
	unsigned sroot = sqrt((double)n);
	for(unsigned int i=2;i<=sroot;++i)
		if(!(n%i))
			return 0;
	return 1;
}
unsigned nextPrime(unsigned z)
{
	unsigned i;
	for(i = z + 1;!isprime(i);++i);
	return i;
}
FastInput fi;
unsigned T, x, y, z;
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		x = fi.ReadNext();
		y = fi.ReadNext();
		unsigned sum = x + y;
		z = nextPrime(sum);
		printf("%u\n", z - sum);
	}
	return 0;
}