#include<cstdio>
#include<cmath>
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
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()

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

int T, ans, S;
char tim[5];
int main()
{
	si(T);
	while(T--)
	{
		ss(tim);
		si(S);
		int hh = (tim[0] - '0') * 10 + tim[1] - '0';
		int mm = (tim[2] - '0') * 10 + tim[3] - '0';
		int m = ceil((double)S / 60.0);
		mm += m;
		hh += mm / 60;
		hh = hh % 24;
		mm = mm % 60;
		if(hh == 0 && mm == 0 && S % 60 != 0)
			printf("2359\n");
		else
			printf("%02d%02d\n", hh, mm);
	}
	return 0;
}