#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cassert>
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
#define MOD 1000000007
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
ll A[10000000];
ll B[5000000], N2;
int ST[23][5000000];
ll N, K, Q;
inline ll fastmod(ll a, ll m)
{
	if(a < m)
		return a;
	else if(a < (m << 1)) //2
		return a - m;
	else if(a < (m << 1) + m) //3
		return a - (m << 1);
	else if(a < (m << 2)) //4
		return a - m - (m << 1);
	else if(a < m + (m << 2)) //5
		return a - (m << 2);
	else
		return a % m;
}
inline ll fastermod(ll a, ll m)
{
	if(a < m)
		return a;
	else if(a < (m << 1)) //2
		return a - m;
	else if(a < (m << 1) + m) //3
		return a - (m << 1);
	else if(a < (m << 2)) //4
		return a - m - (m << 1);
	else if(a < m + (m << 2)) //5
		return a - (m << 2);
	else if(a < (m << 1) + (m << 2)) //6
		return a - m - (m << 2);
	else if(a < (m << 3) - m) //7
		return a - (m << 1) - (m << 2);
	else if(a < (m << 3)) //8
		return a + m - (m << 3);
	else
		return a % m;
}

void initST()
{
	static int p, q;
	for(int i = 0; i < N2; i++)
		ST[0][i] = i;
	for (int k = 1; (1 << k) <= N2; k++)
	{
		for (int i = 0; i - 1 + (1 << k) < N2; i++)
		{
			p = ST[k - 1][i];
			q = ST[k - 1][i + (1 << (k - 1))];
			if (B[p] < B[q])
				ST[k][i] = p;
			else
				ST[k][i] = q;
		}
	}
}
inline ll queryST(ll Lt, ll Rt)
{
	int st = 31 - __builtin_clz(Rt - Lt);
	return min(B[ST[st][Lt]], B[ST[st][Rt - (1 << st)]]);
}
FastInput fi;
int main()
{
	ll a, b, c, d, e, f, r, s, t, m;
	ll L1, La, Lc, Lm, D1, Da, Dc, Dm, L, R;
	ll sum, prod, qual;
	ll temp;

	N = fi.ReadNext(); K = fi.ReadNext(); Q = fi.ReadNext();
	//assert(K < 3 * N / 8);
	a = fi.ReadNext(); b = fi.ReadNext(); c = fi.ReadNext();
	d = fi.ReadNext(); e = fi.ReadNext(); f = fi.ReadNext();
	r = fi.ReadNext(); s = fi.ReadNext(); t = fi.ReadNext();
	m = fi.ReadNext(); A[0] = fi.ReadNext();
	
	L1 = fi.ReadNext(); La = fi.ReadNext(); Lc = fi.ReadNext(); Lm = fi.ReadNext();
	D1 = fi.ReadNext(); Da = fi.ReadNext(); Dc = fi.ReadNext(); Dm = fi.ReadNext();
	
	ll tx = fastmod(t, s);
	for(int x = 1; x < N; x++)
	{
		tx = fastmod(tx * t, s);
		temp = A[x - 1];
		if(tx <= r)
			A[x] = fastermod(a * temp * temp + b * temp + c, m);
		else
			A[x] = fastermod(d * temp * temp + e * temp + f, m);
	}
	N2 = N/2;
	for(int i = 0; i < N2; i++)
		B[i] = min(A[i << 1], A[1 + (i << 1)]);
	initST();
	sum = 0;
	prod = 1;
	for(int i = 0; i < Q; i++)
	{
		L1 = fastermod(La * L1 + Lc, Lm);
		D1 = fastermod(Da * D1 + Dc, Dm);
		R = min(L1 + K + D1, N);
		qual = queryST((1 + L1) >> 1, R >> 1);
		if(L1 % 2)
			qual = min(qual, A[L1]);
		if(R % 2)
			qual = min(qual, A[R - 1]);
		sum += qual;
		prod = fastermod(prod * qual, MOD);
	}
	printf("%lld %lld\n", sum, prod);
	return 0;
}