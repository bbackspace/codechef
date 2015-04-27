#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
#include<stdint.h>
#include<unistd.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
int table[16384];
int a[14];
int T, N, D, ans;
void grayprecompute()
{
	table[0] = 0;
	table[1] = 1;
	for(int k = 2; k <= 14; k++)
	{
		for(int i = 0; i < (1 << (k - 1)); i++)
			table[(1 << k) - i - 1] = table[i] + (1 << (k - 1));
	}
}
int main()
{
	grayprecompute();
	si(T);
	while(T--)
	{
		si(N);
		si(D);
		int st = 0;
		for(int i = 0; i < N; ++i)
		{
			si(a[i]);
			if(a[i] == -1)
				st |= (1 << i);
		}
		if(D / 4 == 0)
		{
			printf("-2\n");
			continue;
		}
		//printf("%d %d - ", st, table[st]);
		for(int i = N - 2; i >= 0; i--)
			st ^= ((st & (1 << (i + 1))) >> 1);
		//printf("%d %d - ", st, table[st]);
		for(int j = 0; j < N; j++)
				if(table[st] & (1 << j))
					printf("-1 ");
				else
					printf("1 ");
			printf("\n");
		int twoN = (1 << N);
		for(int i = (st + 1) % twoN; i != st; i = (i + 1) % twoN)
		{
			//printf("%d - ", table[i]);
			for(int j = 0; j < N; j++)
				if(table[i] & (1 << j))
					printf("-1 ");
				else
					printf("1 ");
			printf("\n");
		}
	}
	return 0;
}