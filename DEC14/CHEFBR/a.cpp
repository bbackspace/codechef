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
#define MOD 1000000007

int a[100];
ll T, N, ans;
int DP(int i, int j)
{
	printf("(%d, %d)\n", i, j);
	if(i > j + 1)
		return 0;
	if(i == j || i == j + 1)
	{
		//printf("1\n");
		return 1;
	}
	if(a[i] < 0 && a[i] == -a[j])
		return 2 * DP(i + 1, j - 1);// + DP(i + 1, j) + DP(i, j - 1);
	else
		return DP(i + 1, j) + DP(i, j - 1) - DP(i + 1, j - 1);
}
map<int, int> m;
vector<int> n;
void remove()
{
	m.clear();
	n.clear();
	for(int i = 0; i < N; i++)
	{
		if(a[i] > 0 && m[abs(a[i])] < 1)
			continue;
		n.push_back(a[i]);
		m[abs(a[i])]++;
	}
	N = n.size();
}
bool isvalid(ll bitmask)
{
	static vector<int> stk;
	stk.clear();
	for(int i = 0; i < N; i++)
	{
		if(bitmask & (1LL << i))
		{
			if(n[i] < 0)
			{
				stk.push_back(n[i]);
			}
			else
			{
				if(stk.empty())
					return false;
				if(stk.back() != -n[i])
					return false;
				stk.pop_back();
			}
		}
	}
	if(!stk.empty())
		return false;
	return true;
}
int main()
{
	si(N);
	for(int i = 0; i < N; i++)
		si(a[i]);
	remove();
	ans = 0;
	for(ll i = 0; i < (1 << N); i++)
	{
		if(isvalid(i))
			ans++;
	}
	printf("%d\n", ans);
	//printf("%d\n", DP(0, N - 1));
	return 0;
}