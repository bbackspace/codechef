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
pair<int, int> a[100000];
int p[100000];
int T, N, ans;
FastInput fi;
int inv()
{
	int cnt = 0;
	for(int i = 0; i < N - 1; i++)
		for(int j = i + 1; j < N; j++)
		  if(p[i] > p[j])
			cnt++;
	return cnt;
}
bool valid()
{
	for(int i = 0; i < N; i++)
		if(!(a[i].first <= p[i] && p[i] <= a[i].second))
			return false;
	return true;
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		for(int i = 0; i < N; ++i)
		{
			int L = fi.ReadNext();
			int R = fi.ReadNext();
			a[i] = pair<int, int>(L, R);
		}
		int m, n;
		m = n = 0;
		for(int i = 0; i < N; i++)
			p[i] = i + 1;
		do
		{
			if(!valid())
				continue;
			int v = inv();
			if(v % 2 == 0)
				m++;
			else
				n++;
		} while(next_permutation(p, p + N));
		if(m == n)
			printf("Draw\n");
		else if(m > n)
			printf("Alex\n");
		else
			printf("Fedor\n");
	}
	return 0;
}