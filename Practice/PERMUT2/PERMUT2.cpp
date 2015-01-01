#include<cstdio>
#include<cstdlib>
#include<stdint.h>
#include<unistd.h>
unsigned n;
unsigned a[100000];

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

int main()
{
	FastInput fi;
	while(1)
	{
		n = fi.ReadNext();
		if(n == 0)
			break;
		for(unsigned i = 0; i < n; ++i)
			a[i] = fi.ReadNext();
		int flag = 1;
		for(unsigned i = 0; i < n; ++i)
		{
			if(a[a[i] - 1] != i + 1)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
	}
	return 0;
}