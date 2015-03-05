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
int a[1000][1000], mH, mW;
int H, W, K; //1 <= H, W <= 1000, 1 <= K <= 1000000
int p, q, L;
int ans[1000][1000];
void copypiece(int r, int c, int pno)
{
	for(int i = 0; i < mH; i++)
		for(int j = 0; j < mW; j++)
			if(a[i][j] == pno)
				ans[r + i][c + j] = pno;
}
bool bounds(int r, int c, int posy, int posx)
{
	return (r + posy < H) && (c + posx < W);
}
FastInput fi;
int main()
{
	H = fi.ReadNext();
	W = fi.ReadNext();
	K = fi.ReadNext();
	int lastpx = 0, lastpy = 0, maxline = 0;
	for(int i = 1; i <= K; i++)
	{
		L = fi.ReadNext();
		mH = mW = 0;
		for(int j = 0; j < L; j++)
		{
			p = fi.ReadNext();
			q = fi.ReadNext();
			a[p - 1][q - 1] = i;
			mH = max(mH, p);
			mW = max(mW, q);
		}
		int x = lastpx, y = lastpy;
		if(mH + lastpy > H)
			continue;
		maxline = max(maxline, mH);
		if(lastpx + mW > W)
		{
			lastpx = 0;
			lastpy += maxline;
			maxline = mH;
			continue;
		}
		else
			lastpx += mW;
		copypiece(y, x, i);
		//printf("%d=lastpx:%d, lastpy:%d, maxline:%d, mH:%d, mW:%d\n", i, lastpx, lastpy, maxline, mH, mW);
		//fflush(stdout);
	}
	
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}