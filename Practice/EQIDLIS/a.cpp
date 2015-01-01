#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<cmath>
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
//#define DEBUG
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
int a[3000];
int T, N, ans;
multimap<int, int> m;
FastInput fi;
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		m.clear();
		N = fi.ReadNext();
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			a[i] = fi.ReadNext();
			sum += a[i];
			m.insert(pair<int, int>(a[i], 1));
		}
		if(sum % N)
			printf("-1\n");
		else
		{
			ans = 0;
			while(m.begin()->first != m.rbegin()->first)
			{
				ans++;
				int minM = m.begin()->first;
				int maxM = m.rbegin()->first;
				int r = (maxM - minM + 1)/2;
				m.erase(m.begin());
				map<int, int>::iterator last = m.end();
				last--;
				m.erase(last);
				minM += r;
				maxM -= r;
				m.insert(pair<int, int>(minM, 1));
				m.insert(pair<int, int>(maxM, 1));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}