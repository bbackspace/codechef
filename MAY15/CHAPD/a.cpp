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
int a[100000];
ll T, A, B, ans;
int main()
{
	sll(T);
	while(T--)
	{
		sll(A);
		sll(B);
		ll gcd = __gcd(A, B); //15
		ll res = B / gcd; //5
		while(__gcd(gcd, res) != 1) 
			res /= __gcd(gcd, res);
		if(res == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}