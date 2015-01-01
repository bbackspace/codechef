#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
ll a[100000];
ll diff[100000];
int N, K;
struct ap
{
	ll a0;
	ll d;
	ap(ll _a0, ll _d) : a0(_a0), d(_d) { }
	bool operator <(const ap& rhs) const
	{
		return a0 < rhs.a0 || (a0 == rhs.a0 && d < rhs.d);
	}
};
map<ap, int> mcnt;
inline void fast()
{
	mcnt.clear();
	for(int i = 1; i < N; i++)
		mcnt[ap(a[i - 1] - (i - 1) * diff[i], diff[i])]++;
	map<ap, int>::iterator it = mcnt.begin();
	ap max = it -> first;
	for(it++; it != mcnt.end(); it++)
	{
		if(mcnt[max] < it->second)
			max = it->first;
	}
	for(it = mcnt.begin(); it != mcnt.end(); it++)
	{
		int changed = 0;
		int i;
		for(i = 0; i < N; i++)
		{
			if(it->first.a0 + i * it->first.d != a[i])
			{
				changed++;
				if(changed > K)
					break;
			}
		}
		if(changed <= K)
		{
			ll ai = it->first.a0;
			for(int i = 0; i < N; i++)
			{
				printf("%lld ", ai);
				ai += it->first.d;
			}
			break;
		}
	}
}

int main()
{
	si(N);
	si(K);
	for(int i = 0; i < N; ++i)
		sll(a[i]);
	for(int i = 1; i < N; i++)
		diff[i] = a[i] - a[i - 1];
	fast();
	return 0;
}