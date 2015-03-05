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
ll a[100001];
ll T, N, K, X, ans;
FastInput fi;
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		K = fi.ReadNext();
		for(int i = 0; i < K; ++i)
			a[i] = fi.ReadNext();
		sort(a, a + K);
		ll sumk = 0;
		X = LLONG_MAX;
		for(int i = 0; i < K; i++)
		{
			sumk += a[i];
			ll iX = 1 + a[i] * (a[i] + 1) / 2 - sumk;
			if(binary_search(a, a + K, iX))
			{
				X = min(X, iX);
			}
		}
		X = min(X, (N * (N + 1) / 2) + 1 - sumk);
		//printf("%lld - ", X);
		if(X % 2)
			printf("Chef\n");
		else
			printf("Mom\n");
	}
	return 0;
}