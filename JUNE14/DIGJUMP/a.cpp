#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;

char a[100010];
int DP[100000];
int N, assigned = 0;
int mindig[10];
void replace(int i, int jmp)
{
	if (i >= 0 && i < N && DP[i] > jmp)
	{
		DP[i] = jmp;
		assigned++;
	}
}
void replaceall(int n, int jmp)
{
	if(mindig[n] < INT_MAX)
		return;
	for(int i = 0; i < N; i++)
		if(a[i] == n)
			replace(i, jmp);
	mindig[n] = jmp;
}
int main()
{
	for(int i = 0; i < 100000; i++)
		DP[i] = INT_MAX;
	for(int i = 0; i < 10; i++)
		mindig[i] = INT_MAX;
	scanf("%s", a);
	N = strlen(a);
	if(N == 1)
	{
		printf("0\n");
		return 0;
	}
	for(int i = 0; i < N; i++)
		a[i] -= '0';
	DP[0] = 0;
	assigned = 1;
	for(int jmp = 1; assigned < N; jmp++)
	{
		for(int i = 0; i < N; i++)
		{
			if(DP[i] == jmp - 1)
				replaceall(a[i], jmp);
		}
		for(int i = 0; i < N; i++)
		{
			if(DP[i] == jmp - 1)
			{
				replace(i - 1, jmp);
				replace(i + 1, jmp);
			}
		}
		if(DP[N - 1] < INT_MAX)
			break;
	}
	printf("%d\n", DP[N - 1]);
	return 0;
}