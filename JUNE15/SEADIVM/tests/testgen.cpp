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
#include<random>
#include<chrono>
#include<set>
#include<deque>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
vector<int> a;
int h[1001];
int T, N, M;
int main()
{
	printf("1\n100 100\n");
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,1000);
	for(int i = 0; i < 5000; i++)
	{
		int x = distribution(generator);
		a.push_back(x);
		a.push_back(x);
	}
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(a.begin(), a.end(), std::default_random_engine(seed));
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
			printf("%d ", a[i*100 + j]);
		printf("\n");
	}
	return 0;
}