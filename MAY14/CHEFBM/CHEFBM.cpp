#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

map<int, int> a[100000];
int n, m, p, i, j, cost;

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	for(int k = 0; k < p; ++k)
	{
		scanf("%d %d", &i, &j);
		i--;
		if(a[i].count(j) == 0)
			a[i][j] = 1;
		else
			a[i][j] = a[i][j] + 1;
	}
	for(i = 0; i < n; ++i)
	{
		map<int, int>::iterator it;
		if(a[i].count(m) > 0)
			cost = a[i][m] + m;
		else
			cost = m;
		if(a[i].count(1) > 0)
			cost -= a[i][1] + 1;
		else
			cost--;
		
		for(it = a[i].begin(); it != a[i].end(); it++)
		{
			j = it->first;
			if(j == m)
				break;
			int suc = 0;
			if(a[i].count(j + 1) > 0)
				suc = a[i][j + 1];
			if(it -> second > suc + 1)
			{
				cost = -1;
				break;
			}
		}
		printf("%d\n", cost);
	}
	return 0;
}