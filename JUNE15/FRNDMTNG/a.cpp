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
int T;
double T1, T2, t1, t2;
double ans;
int main()
{
	si(T);
	while(T--)
	{
		scanf("%lf %lf %lf %lf", &T1, &T2, &t1, &t2);
		if(T1 > T2 + t2)
		{
			swap(T1,T2);
			swap(t1,t2);
		}
		//Case I: (T1,T2) is outside y <= x + t1
		if(T2 > T1 + t1)
		{
			ans = T1*T1/2.0 + t1*T1;
			if(t2 < T1)
				ans -= 0.5 * (T1 - t2) * (T1 - t2);
		}
		else //Case II: (T1,T2) is inside y <= x + t1
		{
			ans = T1 * T2;
			if(t1 < T2)
				ans -= 0.5 * (T2 - t1) * (T2 - t1);
			if(t2 < T1)
				ans -= 0.5 * (T1 - t2) * (T1 - t2);
		}
		printf("%lf\n", ans / (T1 * T2));
	}
	return 0;
}