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
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(x) printf("%s\n", x)
#define pc(x) printf("%c\n", x)
#define parr(x, n) printf("[ "); for(int i = 0; i < (n); i++) printf("%d ", x[i]); printf("]\n");
char P[1000001], a, b;
int Q, N, L, R;
ll ans;
ll nc[1000001], ch[1000001], ce[1000001], cf[1000001];
ll nh[1000001], hc[1000001], he[1000001], hf[1000001];
ll ne[1000001], ec[1000001], eh[1000001], ef[1000001];
ll nf[1000001], fc[1000001], fh[1000001], fe[1000001];
int main()
{
	ss(P);
	N = strlen(P);
	//ps(P);
	//pi(N);
	nc[0] = nh[0] = ne[0] = nf[0] = 0;
	for(int i = 0; i < N; i++)
	{
		nc[i + 1] = nc[i] + ((P[i] == 'c') ? 1 : 0);
		nh[i + 1] = nh[i] + ((P[i] == 'h') ? 1 : 0);
		ne[i + 1] = ne[i] + ((P[i] == 'e') ? 1 : 0);
		nf[i + 1] = nf[i] + ((P[i] == 'f') ? 1 : 0);
	}
	//parr(nc, N + 1);
	//parr(nf, N + 1);
	for(int i = 0; i < N; i++)
	{
		//ends with c: hc, ec, fc
		hc[i + 1] = hc[i] + ((P[i] == 'c') ? nh[i + 1] : 0);
		ec[i + 1] = ec[i] + ((P[i] == 'c') ? ne[i + 1] : 0);
		fc[i + 1] = fc[i] + ((P[i] == 'c') ? nf[i + 1] : 0);
		//ends with h: ch, eh, fh
		ch[i + 1] = ch[i] + ((P[i] == 'h') ? nc[i + 1] : 0);
		eh[i + 1] = eh[i] + ((P[i] == 'h') ? ne[i + 1] : 0);
		fh[i + 1] = fh[i] + ((P[i] == 'h') ? nf[i + 1] : 0);
		//ends with e: ce, he, fe
		ce[i + 1] = ce[i] + ((P[i] == 'e') ? nc[i + 1] : 0);
		he[i + 1] = he[i] + ((P[i] == 'e') ? nh[i + 1] : 0);
		fe[i + 1] = fe[i] + ((P[i] == 'e') ? nf[i + 1] : 0);
		//ends with f: cf, hf, ef
		cf[i + 1] = cf[i] + ((P[i] == 'f') ? nc[i + 1] : 0);
		hf[i + 1] = hf[i] + ((P[i] == 'f') ? nh[i + 1] : 0);
		ef[i + 1] = ef[i] + ((P[i] == 'f') ? ne[i + 1] : 0);
	}
	//parr(cf, N + 1);
	si(Q);
	while(Q--)
	{
		sc(a);
		sc(b);
		si(L);
		si(R);
		switch(a)
		{
			case 'c':
				switch(b)
				{
					case 'h': ans = ch[R] - ch[L - 1] - nc[L - 1] * (nh[R] - nh[L - 1]); break;
					case 'e': ans = ce[R] - ce[L - 1] - nc[L - 1] * (ne[R] - ne[L - 1]); break;
					case 'f': ans = cf[R] - cf[L - 1] - nc[L - 1] * (nf[R] - nf[L - 1]); break;
				}
				break;
			case 'h':
				switch(b)
				{
					case 'c': ans = hc[R] - hc[L - 1] - nh[L - 1] * (nc[R] - nc[L - 1]); break;
					case 'e': ans = he[R] - he[L - 1] - nh[L - 1] * (ne[R] - ne[L - 1]); break;
					case 'f': ans = hf[R] - hf[L - 1] - nh[L - 1] * (nf[R] - nf[L - 1]); break;
				}
				break;
			case 'e':
				switch(b)
				{
					case 'c': ans = ec[R] - ec[L - 1] - ne[L - 1] * (nc[R] - nc[L - 1]); break;
					case 'h': ans = eh[R] - eh[L - 1] - ne[L - 1] * (nh[R] - nh[L - 1]); break;
					case 'f': ans = ef[R] - ef[L - 1] - ne[L - 1] * (nf[R] - nf[L - 1]); break;
				}
				break;
			case 'f':
				switch(b)
				{
					case 'c': ans = fc[R] - fc[L - 1] - nf[L - 1] * (nc[R] - nc[L - 1]); break;
					case 'h': ans = fh[R] - fh[L - 1] - nf[L - 1] * (nh[R] - nh[L - 1]); break;
					case 'e': ans = fe[R] - fe[L - 1] - nf[L - 1] * (ne[R] - ne[L - 1]); break;
				}
				break;
		}
		pll(ans);
	}
	return 0;
}