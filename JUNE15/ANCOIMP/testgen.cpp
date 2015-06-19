#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cassert>
#include<algorithm>
#include<vector>
#include<deque>
#include<map>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
int a[10][10]={0};
int main()
{
	int T=0;
	for(int i = 4; i <= 6; i++)
	{
		for(int m = 0; m < (1<<((i * (i-1))/2)); m++)
		{
			for(int j = 0; j < i; j++)
				for(int k = j + 1; k < i; k++)
					a[j][k] = a[k][j] = (m & (1 << ((k * (k - 1))/2 + j))) > 0;
			printf("%d\n", i);
			for(int j = 0; j < i; j++)
			{
				for(int k = 0; k < i; k++)
					printf("%d ", a[j][k]);
				printf("\n");
			}
			T++;
		}
	}
	printf("%d\n", T);
	return 0;
}