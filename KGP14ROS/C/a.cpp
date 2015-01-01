#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()

int T, N, P, ans;
vector<int> g[10000];
int color[10000]; //0 -> not visited, 1 -> color1, 2 -> color2
deque<int> q;
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
		for(int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			if(color[v] && color[u] == color[v])
				return false;
			if(!color[v])
			{
				color[v] = opp(color[u]);
				q.push_back(v);
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

int main()
{
	si(T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case %d: ", t);
		si(N);
		for(int i = 0; i < 1000; i++)
			g[i].clear();
		for(int i = 0; i < N; i++)
		{
			si(P);
			int v;
			for(int j = 0; j < P; j++)
			{
				si(v);
				g[i].push_back(v - 1);
			}
		}
		memset(color, 0, sizeof(color));
		ans = 1;
		while(1)
		{
			int x = covered();
			if(x == -1)
				break;
			if(!bfs(x))
			{
				ans = 0;
				break;
			}
		}
		int x = 0, y = 0;
		if(ans)
		{
			for(int i = 0; i < N; i++)
				if(color[i] == 1)
					x++;
				else
					y++;
			if(x > y)
				swap(x, y);
		}
		printf("%d %d %d", ans, x, y);
		//if(t < T)
			printf("\n");
	}
	return 0;
}