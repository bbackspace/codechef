#include<cstdio>
#include<cmath>

int N;
int isprime(unsigned int n)
{
	if(n == 2)
		return 1;
	if(n % 2 == 0)
		return 0;
	unsigned s = sqrt(n);
	for(unsigned int i = 3;i <= s;i += 2)
		if(n % i == 0)
			return 0;
	return 1;
}
bool ispalin(int n)
{
	int p = n;
	int q = 0;
	while(p > 0)
	{
		q = q * 10 + p % 10;
		p /= 10;
	}
	if(q == n)
		return true;
	else
		return false;
}
int main()
{
	scanf("%d", &N);
	for(int i = N; ; i++)
		if(ispalin(i) && isprime(i))
		{
			printf("%d\n", i);
			break;
		}
	return 0;
}