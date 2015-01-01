#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<iomanip>
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
enum color
{
	WHITE,
	RED,
	BLACK
};
enum color a[100][100];
int M, N, K, x, y;
FastInput fi;
struct solline
{
	int r;
	int c;
	int t;
};
vector<solline> sol;
void mark(int i, int j, int dir)
{
	if(dir == 0)
	{
		int k = j;
		while(k >= 0 && a[i][k] == WHITE)
			k--;
		for(k++; k < M && a[i][k] == WHITE; k++)
			a[i][k] = RED;
	}
	else
	{
		int k = i;
		while(k >= 0 && a[k][j] == WHITE)
			k--;
		for(k++; k < N && a[k][j] == WHITE; k++)
			a[k][j] = RED;
	}
	solline oper = {i, j, dir};
	sol.push_back(oper);
}
void solve(int roff, int coff, int r, int c)
{
	if(r == 0 || c == 0)
		return;
	for(int i = 0; i < c; i++)
	{
		if(a[roff][coff + i] == WHITE)
			mark(roff, coff + i, 0);
		if(a[roff + r - 1][coff + i] == WHITE)
			mark(roff + r - 1, coff + i, 0);
	}
	for(int i = 1; i < r; i++)
	{
		if(a[roff + i][coff] == WHITE)
			mark(roff + i, coff, 1);
		if(a[roff + i][coff + c - 1] == WHITE)
			mark(roff + i, coff + c - 1, 1);
	}
	solve(roff + 1, coff + 1, r - 1, c - 1);
}
int main()
{
	N = fi.ReadNext();
	M = fi.ReadNext();
	K = fi.ReadNext();
	for(int i = 0; i < K; i++)
	{
		x = fi.ReadNext();
		y = fi.ReadNext();
		a[x - 1][y - 1] = BLACK;
	}
	sol.clear();
	//solve(0, 0, N, M);
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(a[j][i] == WHITE)
				mark(j, i, 1);
		}
	}
	printf("%d\n", sol.size());
	for(int i = 0; i < sol.size(); i++)
	{
		printf("%d %d %d\n", sol[i].r + 1, sol[i].c + 1, sol[i].t);
	}
	/*for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			printf("%d", a[i][j]);
		printf("\n");
	}*/
	return 0;
}