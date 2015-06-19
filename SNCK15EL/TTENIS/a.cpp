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
char a[1000];
int T, N, ans;
int main()
{
	si(T);
	while(T--)
	{
		ss(a);
		N = strlen(a);
		int c[2] = {0};
		bool win;
		for(int i = 0; i < N; ++i)
		{
			c[a[i] - '0']++;
			if(c[1] == 11)
			{
				win = true;
				break;
			}
			if(c[0] == 11)
			{
				win = false;
				break;
			}
			if(c[0] == 10 && c[1] == 10)
			{
				c[0]--;
				c[1]--;
			}			
		}
		
		if(win)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
	return 0;
}