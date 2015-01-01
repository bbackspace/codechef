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
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)

int a[100000];
int T, N, M, d, offset = 0;
int main()
{
	si(N);
	si(M);
	for(int i = 0; i < N; ++i)
		si(a[i]);
	char c;
	while(M--)
	{
		getchar();
		sc(c);
		getchar();
		si(d);
		if(c == 'C')
			offset = (offset + d) % N;
		else if(c == 'A')
			offset = (offset + N - d) % N;
		else if(c == 'R')
			printf("%d\n", a[(d - 1 + offset) % N]);
	}
	return 0;
}