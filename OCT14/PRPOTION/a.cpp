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
int r, g, b, t;
int T, R, G, B, M;
FastInput fi;
int &maxof(int &a, int &b, int &c)
{
	if(a > b)
	{
		if(a > c)
			return a;
		else
			return c;
	}
	else
	{
		if(b > c)
			return b;
		else
			return c;
	}
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		R = fi.ReadNext();
		G = fi.ReadNext();
		B = fi.ReadNext();
		M = fi.ReadNext();
		r = 0;
		g = 0;
		b = 0;
		for(int i = 0; i < R; ++i)
			if((t = fi.ReadNext()) > r)
				r = t;
		for(int i = 0; i < G; ++i)
			if((t = fi.ReadNext()) > g)
				g = t;
		for(int i = 0; i < B; ++i)
			if((t = fi.ReadNext()) > b)
				b = t;
		while(M--)
		{
			maxof(r, g, b) /= 2;
		}
		printf("%d\n", maxof(r, g, b));
	}
	return 0;
} 