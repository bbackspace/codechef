#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<iomanip>
#include<stdint.h>
#include<unistd.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
char S[1010], T[1010];

vector<char> m[256];
bool visited[256];
char str[5];
int P, N, M;
bool ans;
bool search(char s, char d)
{
	if(visited[s])
		return false;
	visited[s] = true;
	for(int i = 0; i < m[s].size(); i++)
	{
		if(m[s][i] == d)
			return true;
	}
	for(int i = 0; i < m[s].size(); i++)
	{
		if(search(m[s][i], d))
			return true;
	}
	return false;
}
int main()
{
	si(P); getchar();
	while(P--)
	{
		ans = true;
		sline(S); getchar();
		sline(T); getchar();
		si(M); getchar();
		for(int i = 0; i < 256; i++)
			m[i].clear();
		for(int i = 0; i < M; ++i)
		{
			sline(str); getchar();
			if(str[0] != str[3])
				m[str[0]].push_back(str[3]);
		}
		int l1 = strlen(S);
		int l2 = strlen(T);
		if(l1 != l2)
			ans = false;
		else
		{
			for(int i = 0; i < l1; i++)
			{
				if(S[i] == T[i])
					continue;
				for(int j = 0; j < 256; j++)
					visited[j] = false;
				if(!search(S[i], T[i]))
				{
					ans = false;
					break;
				}
				else
					m[S[i]].push_back(T[i]);
			}
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
} 