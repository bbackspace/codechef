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
int a[100000];
int diff[100000];
int T, N, M, ans, type, l, r;
FastInput fi;
int acopy[100000];
void move(int a[], int l, int r)
{
	for(int i = 0; i < l; i++)
		acopy[i] = a[i];
	for(int i = l; i <= r; i++)
		a[i - l] = a[i];
	for(int i = r - l + 1; i <= r; i++)
		a[i] = acopy[i - r + l - 1];
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		for(int i = 0; i < N; ++i)
			a[i] = fi.ReadNext();
		diff[0] = 0;
		for(int i = 1; i < N; i++)
			diff[i] = diff[i - 1] + (a[i] != a[i - 1] ? 1 : 0);
		M = fi.ReadNext();
		while(M--)
		{
			type = fi.ReadNext();
			l = fi.ReadNext() - 1;
			r = fi.ReadNext() - 1;
			if(type == 1)
				printf("%d\n", diff[r] - diff[l] + 1);
			else
			{
				move(a, l, r);
				/*for(int i = 0; i < N; i++)
					printf("%d, ", a[i]);
				printf("\n");*/
				diff[0] = 0;
				for(int i = 1; i < N; i++)
					diff[i] = diff[i - 1] + (a[i] != a[i - 1] ? 1 : 0);
			}
		}
	}
	return 0;
} 