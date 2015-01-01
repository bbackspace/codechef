#include<bits/stdc++.h>
#define eps 1e-7
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()
typedef complex<double> point;
double cross(const point &a, const point &b)
{
	return imag(conj(a)*b);
}
int linlin(point a, point b, point c, point d, point & p)
{
	if(abs(cross(b - a, d - c)) > eps)
	{
		p = (cross(c - a, d - c)/cross(b - a, d - c))*(b - a) + a;
		return 1;
	}
	if(abs(cross(b - a, b - c)) > eps)
		return 0;
	return -1;
}

int T, N, ans, p, q, r, s;
int main()
{
	si(T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case %d: ", t);
		si(N);
		si(p);
		si(q);
		si(r);
		si(s);
		int dx = abs(p - r);
		int dy = abs(q - s);
		if(dx == 0)
			ans = dy + 1;
		else if(dy == 0)
			ans = dx + 1;
		else if(dx == dy)
			ans = 3 * dx + 1;
		else
		{
			if(dx < dy)
				swap(dx, dy);
			ans = 1;
			point b1(0.0, 0.0);
			point b2((double)dx, (double)dy);
			for(int i = 0; i < dx; i++)
			{
				point a1(i + 0.5, 0.0);
				point a2(i + 0.5, 10000.0);
				point p;
				if(linlin(a1, a2, b1, b2, p) == 1)
				{
					if(abs(abs(imag(p) - floor(imag(p))) - 0.5) < eps)
						ans += 3;
					else
						ans++;
				}
			}
			for(int i = 0; i < dy; i++)
			{
				point a1(0.0, i + 0.5);
				point a2(10000.0, i + 0.5);
				point p;
				if(linlin(a1, a2, b1, b2, p) == 1)
				{
					if(abs(abs(real(p) - floor(real(p))) - 0.5) > eps)
						ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}