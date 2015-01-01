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

int T;
char c;
int main()
{
	si(T);
	getchar();
	while(T--)
	{
		printf("1\n");
		while((c = getchar()) != '\n')
			putchar(c);
		putchar('\n');
	}
	return 0;
}