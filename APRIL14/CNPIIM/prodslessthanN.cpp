#include<stdio.h>
#include<stdlib.h>
#include<cmath>
unsigned calcnfactors(unsigned n)
{
	if(n == 1)
		return 1;
	unsigned nfact = 2;
	for(unsigned j = 2; j <= n/2; ++j)
		if(n % j == 0)
			nfact+=2;
	return nfact;
}
unsigned pairslessthan(unsigned n)
{
	n--;
	unsigned sum = 0, k;
	for(unsigned i = 1; i <= n; ++i)
	{
		k = n / i;
		if (k > 1)
			sum += k;
		else
			return sum + n - i + 1;
	}
	//return sum;
}
unsigned pairs[1562501];

void build()
{
	unsigned k, root;
	pairs[1] = 1;
	pairs[2] = 1;
	pairs[3] = 3;
	for(unsigned i = 3; i < 1562500; ++i)
	{
		//pairs[i + 1] = pairs[i] + extra in i;
		k = 0;
		root = sqrt((double)i);
		for(unsigned j = 1; j <= root; ++j)
			if(i % j == 0)
				k+=2;
		if(root * root == i)
			k--;
		//else if (i % root == 0)
			//k += 2;
		pairs[i + 1] = pairs[i] + k;
	}
}
int main()
{
	build();
	unsigned sum = 0, N;
	//scanf("%d", &N);
	N = 1562500;
	for(unsigned i = 1; i < N; ++i)
	{
		if(pairslessthan(i) != pairs[i])
			printf("%u, correct: %u incorrect:%u\n", i, pairslessthan(i), pairs[i]);
		if (i % 1000 == 0)
			printf("%d\n", i);
	}
	
}
