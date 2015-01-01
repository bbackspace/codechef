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

ll a[21];
ll T, N, K, sum, portion, curr;
int countSubsets(int n, ll sum)
{
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(a[n - 1] > sum)
		return countSubsets(n - 1, sum);
	return countSubsets(n - 1, sum) + countSubsets(n - 1, sum - a[n - 1]);
}
bool rec(int n)
{
	if(n == 0)
		return true;
	if(a[n - 1] == portion)
		return rec(n - 1);
	if(portion == 0)
		return true;
	return (K <= countSubsets(n, portion));
}
bool solve()
{
	sum = 0;
	for(int i = 0; i < N; i++)
		sum += a[i];
	if(sum % K)
		return false;
	portion = sum / K;
	printf(">p=%d, %d\n", portion, countSubsets(N, portion));
	sort(a, a + N);
	if(a[N - 1] > portion)
		return false;
	return rec(N);
}
int main()
{
	sll(T);
	while(T--)
	{
		sll(N);
		sll(K);
		for(int i = 0; i < N; ++i)
			sll(a[i]);
		if(solve())
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}