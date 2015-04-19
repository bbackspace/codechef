#include<vector>
typedef long long ll;

#define PMAX 1000000
vector<ll> primes;
void sieve()
{
	bool isCom[PMAX + 10];
	memset(isCom, 0, sizeof(isCom));
	for(ll i = 2; i * i <= (ll)PMAX; i++)
	{
		if(!isCom[i])
		{	
			primes.push_back(i);
			for(ll k = i * i; k <= (ll) PMAX; k += i)
				isCom[k] = true;
		}
	}
}
vector<ll> factors;
void factorize(ll N) //spits out unique factors of N into the vector factors[]
{
	factors.clear();
	for(int j = 0; j < primes.size() && primes[j] * primes[j] <= N; j++)
	{
		if(N <= 1)
			return;
		if(N % primes[j] == 0)
			factors.push_back(primes[j]);
		while(N % primes[j] == 0)
			N /= primes[j];
	}
	factors.push_back(N);
}
