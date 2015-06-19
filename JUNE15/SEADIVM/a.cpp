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
#include<set>
#include<deque>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
int c[100], d[100], r[100];
int a[100][100];
int x[100][100];
int h[1001];
int T, N, M;
vector<pair<int, int> > hash[1001];
set<pair<pair<int, int>, pair<int, int> > > ans[10000];
int cum[2][100][101];
inline int count_row(int eq, int row, int c1, int c2) //row and col 0 based
{
	return cum[eq][row][c2 + 1] - cum[eq][row][c1];
}
inline int full_row(int eq, int row, int c1, int c2) //row and col 0 based
{
	return (cum[eq][row][c2 + 1] - cum[eq][row][c1]) == c2 - c1 + 1;
}
/*void join(pair<pair<int, int>, pair<int, int> > p, set<pair<pair<int, int>, pair<int, int> > > &ans, int eq)
{
	if(p.first.first - 1 > 0 && full_row(eq, p.first.first - 2, p.first.second - 1, p.second.second - 1))
	{
		set<pair<pair<int, int>, pair<int, int> > >::iterator it;
		for(int i = p.first.first - 1; i >= 0; i--)
		{
			if(i > 0 && !full_row(eq, i - 1, p.first.second - 1, p.second.second - 1))
				break;
			if((it = ans.find(make_pair(make_pair(i, p.first.second), make_pair(p.second.first - 1, p.second.second)))) != ans.end())
			{
				ans.erase(it);
				ans.insert(make_pair(make_pair(i, p.first.second), p.second));
				return;
			}
		}
	}
	ans.insert(p);
}*/
inline bool lies_in(pair<pair<int, int>, pair<int, int> > sub, int r1, int c1, int r2, int c2)
{
	int x1 = sub.first.first - 1;
	int y1 = sub.first.second - 1;
	int x2 = sub.second.first - 1;
	int y2 = sub.second.second - 1;
	return (x1 >= r1 && y1 == c1 && x2 <= r2 && y2 == c2);
}
bool re = false;
void join(pair<pair<int, int>, pair<int, int> > p, set<pair<pair<int, int>, pair<int, int> > > &ans, int eq)
{
	int row1 = p.first.first - 2;
	if(row1 >= 0 && full_row(eq, row1, p.first.second - 1, p.second.second - 1))
	{
		for(;row1 >= 0 && full_row(eq, row1, p.first.second - 1, p.second.second - 1); row1--);
		row1++; //row1 is now the row where our bounding box starts
		set<pair<pair<int, int>, pair<int, int> > >::iterator it;
		int mxrow = p.first.first - 1;
		for(it = ans.begin(); it != ans.end(); )
		{
			int mid = (re ? (row1 * 11 + (p.first.first - 1) * 4) / 15 : row1);
			if(lies_in(*it, mid, p.first.second - 1, p.second.first - 2, p.second.second - 1))
			{
				mxrow = min(mxrow, (*it).first.first - 1);
				ans.erase(it++);
			}
			else
				++it;
		}
		ans.insert(make_pair(make_pair(mxrow + 1, p.first.second), p.second));
	}
	else
		ans.insert(p);
}
int area(set<pair<pair<int, int>, pair<int, int> > > &ans)
{
	int ar = 0;
	for(set<pair<pair<int, int>, pair<int, int> > >::iterator it = ans.begin(); it != ans.end(); ++it)
		ar += ((*it).second.second - (*it).first.second + 1) * ((*it).second.first - (*it).first.first + 1);
	return ar;
}
void disp(set<pair<pair<int, int>, pair<int, int> > > &ans)
{
	printf("%d\n", ans.size());
	for(set<pair<pair<int, int>, pair<int, int> > >::iterator it = ans.begin(); it != ans.end(); ++it)
	{
		printf("%d %d %d %d\n", (*it).first.first, (*it).first.second, (*it).second.first, (*it).second.second);
	}
}
int cntneighbours(int m, int n)
{
	int r = 0;
	if(m - 1 >= 0)
		r += x[m - 1][n];
	if(n - 1 >= 0)
		r += x[m][n - 1];
	if(m + 1 < N)
		r += x[m + 1][n];
	if(n + 1 < M)
		r += x[m][n + 1];
	return r;
}
vector<int> p1, q1;
void solve(int c1[], int c2[], int eq, set<pair<pair<int, int>, pair<int, int> > > &ans)
{
	memset(x, 0, sizeof(x));
	for(int i = 1; i <= 1000; ++i)
		h[i] = hash[i].size();
	ans.clear();
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(h[a[c1[i]][c2[j]]] > 0)
			{
				x[c1[i]][c2[j]] = 1;
				h[a[c1[i]][c2[j]]] -= 2;
			}
	for(int i = 1; i <= 1000; i++)
	{
		p1.clear();
		q1.clear();
		for(int j = 0; j < hash[i].size(); j++)
		{
			int m = hash[i][j].first, n = hash[i][j].second;
			int nb = cntneighbours(m, n);
			if(x[m][n] == 0 && nb > 0)
				p1.push_back(j);
			else if(x[m][n] && nb == 0)
				q1.push_back(j);
		}
		for(int j = 0; j < min(p1.size(), q1.size()); j++)
			swap(x[hash[i][p1[j]].first][hash[i][p1[j]].second], x[hash[i][q1[j]].first][hash[i][q1[j]].second]);
	}
	for(int i = 1; i <= 1000; i++)
	{
		p1.clear();
		q1.clear();
		for(int j = 0; j < hash[i].size(); j++)
		{
			int m = hash[i][j].first, n = hash[i][j].second;
			int nb = cntneighbours(m, n);
			if(x[m][n] == 0 && nb > 0)
				p1.push_back(j);
			else if(x[m][n] && nb == 0)
				q1.push_back(j);
		}
		for(int j = 0; j < min(p1.size(), q1.size()); j++)
			swap(x[hash[i][p1[j]].first][hash[i][p1[j]].second], x[hash[i][q1[j]].first][hash[i][q1[j]].second]);
	}
	for(int i = 0; i < N; i++)
	{
		cum[0][i][0] = cum[1][i][0] = 0;
		for(int j = 1; j <= M; j++)
		{
			cum[0][i][j] = cum[0][i][j - 1] + (1 - x[i][j - 1]);
			cum[1][i][j] = cum[1][i][j - 1] + x[i][j - 1];
		}
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(x[i][j] == eq)
			{
				pair<int, int> st = make_pair(i + 1, j + 1), en;
				while(j < M && x[i][j] == eq)
					j++;
				en = make_pair(i + 1, j);
				join(make_pair(st, en), ans, eq);
			}
}
deque<pair<int, int> > q;
int visited[100][100];
void solvebfff(pair<int, int> src, int eq, set<pair<pair<int, int>, pair<int, int> > > &ans) //breadth-first flood fill
{
	memset(x, 0, sizeof(x));
	for(int i = 1; i <= 1000; ++i)
		h[i] = hash[i].size();
	/*for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			printf("%2d", h[a[i][j]]/2);
		printf("\n");
	}*/
	ans.clear();
	q.clear();
	memset(visited, 0, sizeof(visited));
	q.push_back(src);
	visited[src.first][src.second] = 1;
	while(!q.empty())
	{
		int i = q.front().first, j = q.front().second;
		q.pop_front();
		if(h[a[i][j]] > 0)
		{
			x[i][j] = 1;
			h[a[i][j]] -= 2;
		}
		//printf("(%d, %d)\n", i, j);
		set<pair<int, int> >::iterator it;
		for(int n = -1; n <= 1; n++)
			for(int m = -1; m <= 1; m++)
			{
				if(i + n < 0 || i + n >= N || j + m < 0 || j + m >= N)
					continue;
				if(!visited[i + n][j + m])
				{
					q.push_back(make_pair(i + n, j + m));
					visited[i + n][j + m] = 1;
				}
			}
	}
	/*for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			printf("%d", x[i][j]);
		printf("\n");
	}*/
	for(int i = 1; i <= 1000; i++)
	{
		p1.clear();
		q1.clear();
		for(int j = 0; j < hash[i].size(); j++)
		{
			int m = hash[i][j].first, n = hash[i][j].second;
			int nb = cntneighbours(m, n);
			if(x[m][n] == 0 && nb > 0)
				p1.push_back(j);
			else if(x[m][n] && nb == 0)
				q1.push_back(j);
		}
		for(int j = 0; j < min(p1.size(), q1.size()); j++)
			swap(x[hash[i][p1[j]].first][hash[i][p1[j]].second], x[hash[i][q1[j]].first][hash[i][q1[j]].second]);
	}
	for(int i = 1; i <= 1000; i++)
	{
		p1.clear();
		q1.clear();
		for(int j = 0; j < hash[i].size(); j++)
		{
			int m = hash[i][j].first, n = hash[i][j].second;
			int nb = cntneighbours(m, n);
			if(x[m][n] == 0 && nb > 0)
				p1.push_back(j);
			else if(x[m][n] && nb == 0)
				q1.push_back(j);
		}
		for(int j = 0; j < min(p1.size(), q1.size()); j++)
			swap(x[hash[i][p1[j]].first][hash[i][p1[j]].second], x[hash[i][q1[j]].first][hash[i][q1[j]].second]);
	}
	for(int i = 0; i < N; i++)
	{
		cum[0][i][0] = cum[1][i][0] = 0;
		for(int j = 1; j <= M; j++)
		{
			cum[0][i][j] = cum[0][i][j - 1] + (1 - x[i][j - 1]);
			cum[1][i][j] = cum[1][i][j - 1] + x[i][j - 1];
		}
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(x[i][j] == eq)
			{
				pair<int, int> st = make_pair(i + 1, j + 1), en;
				while(j < M && x[i][j] == eq)
					j++;
				en = make_pair(i + 1, j);
				join(make_pair(st, en), ans, eq);
			}
}
void solvearoundmax(int &idx, int c[])
{
	memset(x, 0, sizeof(x));
	for(int i = 1; i <= 1000; ++i)
		h[i] = hash[i].size();
	int hm = max_element(h, h + 1000) - h;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(hm == a[c[i]][c[j]])
			{
				if(idx > 30)
					return;
				solvebfff(make_pair(i, j), 1, ans[idx++]);
			}
}
int main()
{
	si(T);
	while(T--)
	{
		si(N);
		si(M);
		for(int i = 0; i < N; i++)
		{
			if(i % 2 == 0)
				c[i] = N/2 + i/2;
			else
				c[i] = N/2 - (i + 1)/2;
			d[i] = i;
			r[i] = N - i - 1;
		}
		for(int i = 1; i <= 1000; i++)
			hash[i].clear();
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; j++)
			{
				si(a[i][j]);
				hash[a[i][j]].push_back(make_pair(i, j));
			}
		int m = -1, mins = INT_MAX;
		for(int iter = 0; iter <= 1; iter++)
		{
			re = (iter == 1);
			solve(d, d, 0, ans[0]);
			solve(d, d, 1, ans[1]);
			solve(d, c, 0, ans[2]);
			solve(d, c, 1, ans[3]);
			solve(c, d, 0, ans[4]);
			solve(c, d, 1, ans[5]);
			solve(c, c, 0, ans[6]);
			solve(c, c, 1, ans[7]);
			solve(r, r, 0, ans[8]);
			solve(r, r, 1, ans[9]);
			solve(r, c, 0, ans[10]);
			solve(r, c, 1, ans[11]);
			solve(c, r, 0, ans[12]);
			solve(c, r, 1, ans[13]);
			solvebfff(make_pair(N / 2     , M / 2     ), 1, ans[14]);
			int idx = 15;
			solvearoundmax(idx, c);
			for(int i = 4; i <= 28; i += 4)
			{
				solvebfff(make_pair(N / 2 - i, M / 2    ), 1, ans[idx++]);
				solvebfff(make_pair(N / 2    , M / 2 - i), 1, ans[idx++]);
				solvebfff(make_pair(N / 2 - i, M / 2 - i), 1, ans[idx++]);
				solvebfff(make_pair(N / 2 - i, M / 2 + i), 1, ans[idx++]);
				solvebfff(make_pair(N / 2 + i, M / 2 - i), 1, ans[idx++]);
				solvebfff(make_pair(N / 2 + i, M / 2    ), 1, ans[idx++]);
				solvebfff(make_pair(N / 2    , M / 2 + i), 1, ans[idx++]);
				solvebfff(make_pair(N / 2 + i, M / 2 + i), 1, ans[idx++]);
			}
			/*
			ans[0].clear();
			for(int i = 0; i < N; i++)
			{
				cum[0][i][0] = cum[1][i][0] = 0;
				for(int j = 1; j <= M; j++)
				{
					cum[0][i][j] = cum[0][i][j - 1] + (1 - a[i][j - 1]);
					cum[1][i][j] = cum[1][i][j - 1] + a[i][j - 1];
				}
			}
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)
					if(a[i][j] == 1)
					{
						pair<int, int> st = make_pair(i + 1, j + 1), en;
						while(j < M && a[i][j] == 1)
							j++;
						en = make_pair(i + 1, j);
						join(make_pair(st, en), ans[0], 1);
					}
			*/
			for(int i = 0; i < idx; i++)
				if(mins > ans[i].size() && area(ans[i]) <= N * M)
				{
					m = i;
					mins = ans[m].size();
				}
			if(m != -1)
				break;
		}
		disp(ans[m]);
	}
	return 0;
}