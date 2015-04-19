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
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)

int a[7];
int T, N;
double ans;
int num;
int h[7];
inline bool check()
{
	for(int i = 0; i < N - 1; i++)
		if(a[i] == a[i + 1])
			return false;
	return true;
}
void recur(int lev)
{
	if(lev == N)
	{
		//if(!check())
			//return;
		memset(h, 0, sizeof(h));
		for(int i = 0; i < N; i++)
			h[a[i]]++;
		int mx = 0;
		for(int i = 0; i < N; i++)
			mx = max(h[i], mx);
		int t = 0;
		for(int i = 0; i < N; i++)
			if(h[i] == mx)
				t++;
		ans += t;
		num++;
		return;
	}
	for(int i = 0; i < N; i++)
	{
		if(lev > 0 && a[lev - 1] == i)
			continue;
		a[lev] = i;
		recur(lev + 1);
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		ans = 0.0;
		num = 0;
		/*for(int i = 0; i < N; i++)
			a[i] = -1;*/
		recur(0);
		printf("%lf\n", ans / num);
	}
	return 0;
}