#include<cstdio>
#include<cstdlib>
#include<climits>
int N, K;
long long A[100000];
int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%lld", &A[i]);
	if(K == 0)
	{
		for(int i = 0; i < N; ++i)
		{
			printf("%lld ", A[i]);
		}	
	}
	else if(K % 2) //odd
	{
		long long max = A[0];
		for(int i = 1; i < N; ++i)
			if(max < A[i])
				max = A[i];
		for(int i = 0; i < N; ++i)
		{
			printf("%lld ", max - A[i]);
		}
	}
	else
	{
		long long min = A[0];
		for(int i = 1; i < N; ++i)
			if(min > A[i])
				min = A[i];
		for(int i = 0; i < N; ++i)
		{
			printf("%lld ", A[i] - min);
		}
	}
	printf("\n");
	return 0;
}