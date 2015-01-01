#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)

ll M, N, q;
int main()
{
	sll(N);
	sll(M);
	while(M--)
	{
		sll(q);
		if (q < N + 2 || q > 3 * N)
			printf("0\n");
		else
			printf("%lld\n", N - abs(2 * N + 1 - q));
	}
	return 0;
}