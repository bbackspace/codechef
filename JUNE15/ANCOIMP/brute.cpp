#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cassert>
#include<algorithm>
#include<vector>
#include<deque>
#include<map>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
int a[1010][1010];
int color[1010], oldcolor[1010];
int ans[1010];
deque<int> q;
int T, N, k;
int comp[1010][1010];
pair<int, pair<int, int> > diff[1010];

int opp(int col)
{
	if(col == 1)
		return 2;
	return 1;
}
bool bfs(int src)
{
	q.clear();
	color[src] = 1;
	q.push_back(src);
	while(!q.empty())
	{
		int u = q.front();
		q.pop_front();
		for(int v = 0; v < N; v++)
		{
			if(a[u][v])
			{
				if(color[v] && color[u] == color[v])
					return false;
				if(!color[v])
				{
					color[v] = opp(color[u]);
					q.push_back(v);
				}
			}
		}
	}
	return true;
}
int covered()
{
	for(int i = 0; i < N; i++)
		if(!color[i])
			return i;
	return -1;
}
bool solexists()
{
	for(int i = 0; i < N; i++)
		if(a[i][i])
			return false;
	memset(color, 0, sizeof(color));
	memset(oldcolor, 0, sizeof(oldcolor));
	memset(comp, 0, sizeof(comp));
	k = 0;
	while(1)
	{
		int x = covered();
		if(x == -1)
			break;
		if(!bfs(x))
			return false;
		for(int i = 0; i < N; i++)
			if(oldcolor[i] == 0)
			{
				comp[k][i] = color[i] > 0;
				oldcolor[i] = color[i];
			}
		k++;
	}
	return true;
}
int xorbit(int m, int i, int j)
{
	int x = m & (1 << i);
	int y = m & (1 << j);
	if(x && y)
		return 0;
	if(!x && !y)
		return 0;
	return 1;
}
int valid(int m)
{
	for(int i = 0; i < N; i++)
		for(int j = i; j < N; j++)
			if(xorbit(m, i, j) == 0 && a[i][j])
				return 0;
	return 1;
}
int countzeros(int m)
{
	int z = 0;
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
			if(a[i][j] == 0 && xorbit(m, i, j))
				z++;
	return z;
}
void printtest(int t1, int t2)
{
	printf("%d\n", N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("Your ans:");
	if(t1 == -1)
		printf("-1");
	else
	{
		for(int i = 0; i < N; i++)
			printf("%d ", ((1 << i) & t1) > 0);
		printf(" z = %d\n", countzeros(t1));
	}
	printf("\nCorrect ans:");
	if(t2 == -1)
		printf("-1");
	else
	{
		for(int i = 0; i < N; i++)
			printf("%d ", ((1 << i) & t2) > 0);
		printf(" z = %d\n", countzeros(t2));
	}
}
int main()
{
	si(T);
	while(T--)
	{
		si(N);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				si(a[i][j]);
		int mx = -1, z = -1;
		for(int bit = 0; bit < (1<<(N)); bit++)
		{
			if(!valid(bit))
				continue;
			int zer = countzeros(bit);
			/*for(int i = 0; i < N; i++)
				printf("%d ", ((1 << i) & bit) > 0);
			printf("= %d\n", zer);*/
			if(zer > z)
			{
				mx = bit;
				z = zer;
			}
		}
		if(solexists())
		{
			memset(ans, 0, sizeof(ans));
			for(int i = 0; i < k; i++)
			{
				int fr[2] = {0, 0};
				for(int j = 0; j < N; j++)
					if(comp[i][j])
						fr[color[j] - 1]++;
				diff[i].first = abs(fr[0] - fr[1]);
				diff[i].second = make_pair(fr[0] - fr[1], i);
			}
			/*printf("comp\n");
			for(int i = 0; i < k; i++)
			{
				for(int j = 0; j < N; j++)
					printf("%d ", comp[i][j]);
				printf("\n");
			}
			printf("diff\n");
			for(int i = 0; i < k; i++)
			{
				printf("%d %d %d", diff[i].first, diff[i].second.first, diff[i].second.second);
				printf("\n");
			}*/
			sort(diff, diff + k);
			int f = 0;
			for(int i = k - 1; i >= 0; i--)
			{
				if(f >= 0 != diff[i].second.first >= 0)
				{
					for(int j = 0; j < N; j++)
						if(comp[diff[i].second.second][j])
							ans[j] = color[j];
					f += diff[i].second.first;
				}
				else
				{
					for(int j = 0; j < N; j++)
						if(comp[diff[i].second.second][j])
							ans[j] = opp(color[j]);
					f -= diff[i].second.first;
				}
			}
			int mask = 0;
			for(int i = 0; i < N; i++)
				if(ans[i] - 1)
					mask |= (1<<i);
			if(countzeros(mask) < z)
				printtest(mask, mx);
		}
		else
			if(mx != -1)
				printtest(-1, mx);
	}
	return 0;
}