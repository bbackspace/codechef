#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<climits>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N;
struct node
{
	int favno;
	bool isleaf;
	int parent;
	vector<int> child;
	node()
	{
		isleaf = true;
		parent = 0;
	}
} a[100001];
void sum(node &t)
{
	vector<int>::iterator i;
	for(i = t.child.begin(); i != t.child.end(); i++)
	{
		if(a[*i].favno == 0)
			sum(a[*i]);
		t.favno += a[*i].favno;
	}
}
int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &a[i].favno);
	for(int i = 0; i < N - 1; ++i)
	{
		int init,term;
		scanf("%d %d", &init, &term);
		a[init].child.push_back(term);
		a[init].isleaf = false;
		a[term].parent = init;
	}
	sum(a[1]);
	int t = 1;
	int min = INT_MAX;
	int minindex = 0;
	while(!a[t].isleaf)
	{
		vector<int>::iterator i;
		for(i = a[t].child.begin(); i != a[t].child.end(); i++)
		{
			if(min > a[*i].favno)
			{
				min = a[*i].favno;
				minindex = *i;
			}
		}
		t = minindex;
	}
	int rootfavno = a[1].favno;
	while(t != 1)
	{
		int parent = a[t].parent;
		a[parent].favno = a[t].favno * a[parent].child.size();
		t = parent;
	}
	printf("%d\n", rootfavno - a[1].favno);
	return 0;
}