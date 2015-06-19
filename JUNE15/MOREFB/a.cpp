#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cassert>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#define MOD 99991
#define PHI 55048
#define ROOT5 10104
#define ROOT5INV 22019
#define PHI2 44944
#define MAXN 131072
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
inline ll fmod(ll a) { if(a < 0) return a + MOD; if(a < MOD) return a; return a % MOD; }
inline ll powmod(ll a, ll b)
{
	ll prod = 1, s = a;
	while(b)
	{
		if(b & 1)
			prod = fmod(prod * s);
		b>>=1;
		s = fmod(s * s);
	}
	return prod;
}

//FFT code from damians's solution to COUNTARI http://www.codechef.com/viewsolution/1513287
struct base
{
	long double real;
	long double imag;
	base(long double _r, long double _i)
	{
		real=_r;
		imag=_i;
	}
	base() {}
};
 
inline base multiply(const base &left, const base &right)
{
	base res;
	res.real = left.real * right.real - left.imag * right.imag;
	res.imag = left.real * right.imag + left.imag * right.real;
	return res;
}

void FFT(base a[], int n, bool invert)
{
	for(int i = 1, j = 0; i < n; i++)
	{
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i], a[j]);
	}
	for(int len=2; len<=n; len<<=1)
	{
		long double ang = 2 * M_PI / len * (invert ? -1 : 1);
		long double cs = cos(ang);
		long double sn = sin(ang);
		for (int i = 0; i < n; i += len)
		{
			int hlen = len >> 1;
			long double wreal = 1;
			long double wimag = 0;
			base u;
			base* pa1 = a + i;
			base* pa2 = a + i + hlen;
			for (int j=0; j<hlen; ++j) 
			{
				base &a1 = *pa1++;
				base &a2 = *pa2++;
				u = a1;
				long double vreal = a2.real * wreal - a2.imag * wimag;
				long double vimag = a2.real * wimag + a2.imag * wreal;
				a1.real += vreal;
				a1.imag += vimag;
				a2.real = u.real - vreal;
				a2.imag = u.imag - vimag;
				long double wreal2 = wreal;
				wreal = wreal * cs - wimag * sn;
				wimag = wreal2 * sn + wimag * cs;
			}
		}
	}
	if (invert)
		for (int i= n; i >= 0; --i)
			a[i].real /= n;
}
void poly_multiply(vector<int> &v1, vector<int> &v2)
{
	/*
	static int t[131072];
	for (int i = 0; i < f.size() * 2; i++)
		t[i] = 0;
	for (int i = 0; i < f.size(); i++)
		for (int j = 0; j < g.size(); j++)
			t[i + j] = fmod(t[i + j] + fmod((ll)f[i] * g[j]));
	f.resize(2 * f.size());
	for(int i = 0; i < f.size(); i++)
		f[i] = t[i];
	return;
	*/
	static base a[MAXN],b[MAXN],c[MAXN];
	int n2 = max(v1.size(), v2.size()) * 2;
	for(int i = 0; i < n2; i++)
	{
		a[i] = base(0,0);
		b[i] = base(0,0);
	}
	for(int i = 0; i < v1.size(); i++)
		a[i] = base(v1[i], 0);
	for(int i = 0; i < v2.size(); i++)
		b[i] = base(v2[i],0);
	FFT(a, n2, 0);
	FFT(b, n2, 0);
	for(int i = 0; i < n2; i++)
		c[i] = multiply(a[i],b[i]);
	FFT(c, n2, 1);
	v1.resize(n2);
	for(int i = 0; i < n2; i++)
		v1[i] = fmod(floorl(c[i].real + 0.5L));
}
ll a[50000];
int T, N, K;
vector<int> pol[50000];
void mult(int s, int e)
{
	if(s >= e)
		return;
	int mid = (s + e) / 2;
	mult(s, mid);
	mult(mid + 1, e);
	poly_multiply(pol[s], pol[mid + 1]);
	/*printf("pol[%d]: ", s);
	for(int i = 0; i < pol[s].size(); i++)
		printf("%d ", pol[s][i]);
	printf("\n");*/
	vector<int>().swap(pol[mid + 1]); //deallocate other array
}
int main()
{
	si(N);
	si(K);
	for(int i = 0; i < N; i++)
		sll(a[i]);
	for(int i = 0; i < N; i++)
	{
		pol[i].push_back(1);
		pol[i].push_back(powmod(PHI, a[i]));
	}
	mult(0, N - 1);
	int phin = pol[0][K];
	for(int i = 0; i < N; i++)
	{
		pol[i].clear();
		pol[i].push_back(1);
		pol[i].push_back(powmod(PHI2, a[i]));
	}
	mult(0, N - 1);
	int phi2n = pol[0][K];
	printf("%lld\n", fmod(fmod(phin - phi2n) * ROOT5INV));
	return 0;
}