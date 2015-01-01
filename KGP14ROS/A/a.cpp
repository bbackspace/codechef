#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()

ll a[100], b[100];
ll T, N, ans;

int main()
{
	sll(T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case %d: ", t);
		sll(N);
		for(int i = 0; i < N; ++i)
			sll(a[i]);
		for(int i = 0; i < N; ++i)
			sll(b[i]);
		sort(a, a + N);
		sort(b, b + N);
		ans = 0;
		for(int i = 0; i < N; i++)
			ans += abs(a[i] - b[i]);
		printf("%lld", ans);
		if(t < T)
			printf("\n");
	}
	return 0;
}