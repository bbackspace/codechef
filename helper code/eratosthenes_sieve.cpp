#include<vector>
typedef long long ll;

#define PMAX 1000000
vector<ll> primes;
void sieve()
{
	bool isCom[PMAX + 10];
	memset(isCom, 0, sizeof(isCom));
	for(ll i = 2; i <= (ll)PMAX; i++)
	{
		if(!isCom[i])
		{	
			primes.push_back(i);
			for(ll k = i * i; k <= (ll) PMAX; k += i)
				isCom[k] = true;
		}
	}
}