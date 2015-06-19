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
vector<pair<ll,ll> > poly;
pair<ll,int> area[100000];
int idx[100000];
int T, N, M, ans;
ll a, b;
ll calc()
{
	ll ret = 0;
	int last = poly.size() - 1;
	for(int i = 0; i < poly.size(); i++)
	{
		ret += (poly[last].first + poly[i].first) * (poly[last].second - poly[i].second);
		last = i;
	}
	return ret;
}
int main()
{
	si(T);
	while(T--)
	{
		si(N);
		for(int i = 0; i < N; ++i)
		{
			si(M);
			poly.clear();
			poly.reserve(M);
			for(int j = 0; j < M; j++)
			{
				sll(a);
				sll(b);
				poly.push_back(make_pair(a, b));
			}
			area[i] = make_pair(abs(calc()), i);
		}
		sort(area, area + N);
		for(int i = 0; i < N; i++)
			idx[area[i].second] = i;
		for(int i = 0; i < N; i++)
			printf("%d ", idx[i]);
		printf("\n");
	}
	return 0;
}