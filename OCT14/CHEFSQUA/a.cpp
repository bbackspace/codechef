#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<map>
#include<cmath>

typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)

class MyHash
{
public:
    size_t operator()(pair<int, int> const& s) const 
    {
        size_t h1 = hash<int>()(s.first);
        size_t h2 = hash<int>()(s.second);
        return h1 ^ (h2 << 1);
    }
};
 
pair<int, int> p[2000];
unordered_set<pair<int, int>, MyHash> s;
int T, N, x, y;
bool iscollinear()
{
	/*
		|1 a b|
		|1 m n| = 0
		|1 x y|
		my - nx + bx - ay + an - bm = 0
		(m - a)y + (b - n)x = bm - an
	*/
	ll rhs = (ll)p[0].second * p[1].first - (ll)p[0].first * p[1].second;
	for(int i = 2; i < N; i++)
	{
		if((ll)(p[1].first - p[0].first) * p[i].second + (ll)(p[0].second - p[1].second) * p[i].first != rhs)
			return false;
	}
	return true;
}

int solve()
{
	int ans = 2;
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			int sx = p[i].first - p[j].first;
			int sy = p[i].second - p[j].second;
			ans = min(ans, 2 - (int)s.count(make_pair(p[i].first - sy, p[i].second + sx)) - (int)s.count(make_pair(p[j].first - sy, p[j].second + sx)));
			ans = min(ans, 2 - (int)s.count(make_pair(p[i].first + sy, p[i].second - sx)) - (int)s.count(make_pair(p[j].first + sy, p[j].second - sx)));
			if(ans == 0)
				return ans;
		}
	}
	return ans;
}
int main()
{
	si(N);
	s.reserve(N);
	for(int i = 0; i < N; i++)
	{
		si(x);
		si(y);
		p[i] = make_pair(x, y);
		s.insert(p[i]);
	}
	if(N == 0)
		printf("4\n");
	else if (N == 1)
		printf("3\n");
	else if (N == 2)
		printf("2\n");
	else if (iscollinear())
		printf("2\n");
	else 
		printf("%d\n", solve());
	return 0;
} 