#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()

int T;
int x, y, e, ylen;
char ys[11];

int main()
{
	si(T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case %d: ", t);
		si(x);
		si(y);
		sprintf(ys, "%d", y);
		ylen = strlen(ys);
		long double logx = log10((long double)x);
		for(e = 1; ;e++)
		{
			long double p = pow(10.0L, logx*e - floor(logx*e) + (ylen - 1));
			//printf("%lf\n", p);
			if(((int)p) == y)
				break;
		}
		printf("%d\n", e);
	}
	return 0;
}