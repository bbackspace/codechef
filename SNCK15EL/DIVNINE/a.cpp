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
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
char a[100001];
int T, N, Q, k, ans;
int s = 0;
int main()
{
	si(T);
	while(T--)
	{
		s = 0;
		ss(a);
		N = strlen(a);
		for(int i = 0; i < N; ++i)
			s += (a[i] - '0');
		int k = s % 9;
		if(N != 1 && s < 5)
			printf("%d\n", 9 - k);
		else
			printf("%d\n", min(k, 9 - k));
	}
	return 0;
}