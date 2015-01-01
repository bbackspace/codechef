#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<climits>
#include<cstring>
class Set
{
public:
	int N;
	int ele[40];
	Set()
	{
		N = 0;
		memset(ele, 0, 21 * sizeof(int));
	}
	void add(int e)
	{
		if(ele[e] == 0)
		{
			ele[e] = 1;
			N++;
		}
	}
	void remove(int e)
	{
		if(ele[e] == 0)
			return;
		ele[e] = 0;
		N--;
	}
	int search(int e)
	{
		if(ele[e])
			return e;
		return -1;
	}
	int last()
	{
		for(int i = 19; i >= 0; --i)
			if(ele[i] > 0)
				return  i;
		return -1;
	}
	void print()
	{
		printf("[");
		for(int i = 0; i < 20; ++i)
			if(ele[i])
				printf("%d ", i);
		printf("]\n");
	}
};
int a[20][20001] = {0};
int N, M;
int isDisjoint(Set &ignore)
{
	static int hash[20001];
	memset(hash, 0, 20001 * sizeof(int));
	for(int j = 1; j <= N; ++j)
	{
		int flag = 0;
		for(int i = 0; i < M; ++i)
		{
			if(ignore.ele[i])
				continue;
			if(j <= a[i][0])
			{
				if(hash[a[i][j]]++ > 0)
					return 0;
				flag = 1;
			}
		}
		if(!flag)
			break;
	}
	return 1;
}
int combauction(Set &ignore, int last)
{
	static int max = INT_MIN;
	if (isDisjoint(ignore))
	{
		//printf("BaseC");ignore.print();
		return M - ignore.N;
	}
	for(int i = last + 1; i < M; ++i)
	{
		if(ignore.ele[i])
			continue;
		if(M - ignore.N - 1 <= max)
			continue;
		ignore.add(i);
		
		//clock_t starttime, endtime;
		//starttime = clock();
		//printf("Start");ignore.print();
		int s = combauction(ignore, i);
		//printf("End  ");ignore.print();
		//endtime = clock();
		//printf("Time for combauction: %6.3f", (double)endtime - starttime); ignore.print();
		
		if(s > max)
			max = s;
		ignore.remove(i);
	}
	return max;
}

int main()
{
	clock_t starttime, endtime;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		scanf("%d", &a[i][0]);
		for(int j = 0; j < a[i][0]; ++j)
		{
			scanf("%d", &a[i][j + 1]);
		}
	}
	starttime = clock();
	Set ignore;
	printf("%d\n", combauction(ignore, -1));
	endtime = clock();
	printf("Time : %6.3f", (double)endtime - starttime);
	return 0;
}