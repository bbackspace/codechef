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
int ST[262144]; //2^((int)log_2(N) + 2)
int a[100010];
int T, N, Q, A, B, ans;
FastInput fi;
void initST(int node, int start, int end)
{
	if(start == end)
		ST[node] = start;
	else
	{
		initST(2 * node + 1, start, (start + end) >> 1);
		initST(2 * node + 2, ((start + end) >> 1) + 1, end);
		if(a[ST[2 * node + 1]] <= a[ST[2 * node + 2]])
			ST[node] = ST[2 * node + 1];
		else
			ST[node] = ST[2 * node + 2];
	}
}

int queryST(int node, int start, int end, int A, int B)
{
	if(B < start || A > end)
		return -1;
	if(A <= start && end <= B)
		return ST[node];
	int leftchild = queryST(2 * node + 1, start, (start + end) >> 1, A, B);
	int rightchild = queryST(2 * node + 2, ((start + end) >> 1) + 1, end, A, B);
	if(leftchild == -1)
		return rightchild;
	if(rightchild == -1)
		return leftchild;
	if(a[leftchild] < a[rightchild])
		return leftchild;
	else
		return rightchild;
}
int main()
{
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		for(int i = 0; i < N; ++i)
			a[i] = fi.ReadNext();
		
		printf("%d\n", ans);
	}
	return 0;
}