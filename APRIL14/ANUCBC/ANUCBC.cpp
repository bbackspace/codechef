#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<algorithm>
#include<stdint.h>
#include<unistd.h>
#define MOD 1000000009

const int maxio=1048576;
char buf[maxio], *s = buf + maxio;

inline char getc1(void)
{
   if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; }
   return *(s++);
}
inline int input()
{
   char t = getc1();
   int n=1,res=0;
   while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-')
   {
      n=-1; t=getc1();
   }
   while(isdigit(t))
   {
     res = 10*res + (t&15);
     t=getc1();
   }
   return res*n;
}

using namespace std;
map<int, long long> cache;
// Function bigmod from tester's solution:
// http://discuss.codechef.com/questions/20312/chmod-editorial
inline long long bigmod(long long a, long long b, long long m)
{
	if(b == 0) return 1 % m;
	long long x = a, ans = 1;
	while(b)
	{
		if(b & 1)
			ans = (ans * x) % m;
		b >>= 1;
		x = (x * x) % m;
	}
	return ans;
}

int T, N, Q, M;
int a[100000];
long long n[100];
long long temp[100];
bool lastn; //true if n stores the latest values; false if temp stores them
inline int mod(int a, int k)
{
	if (a >= 0)
		return a % k;
	return k - ((-a) % k);
}
inline void calc()
{
	int k = M;
	if(cache.count(k) > 0)
	{
		n[0] = cache[k];
		return;
	}
	memset(n, 0, k * sizeof(long long));
	n[0] = 1;
	n[mod(a[0], k)]++;
	lastn = true;
	for(int i = 1; i < N; ++i)
	{
		if(!lastn)
		{
			printf("k = %d[ ", k);
			for(int i = 0; i < k; ++i)
				printf("%d ", temp[i]);
			printf("]\n");
		}
		else
		{
			printf("k = %d[ ", k);
			for(int i = 0; i < k; ++i)
				printf("%d ", n[i]);
			printf("]\n");
		}
		int m = mod(a[i], k);
		if(lastn)
		{
			for(int r = 0; r < k; ++r)
			{
				temp[m] = n[m] + n[r];
				if(temp[m] >= MOD)
					temp[m] -= MOD;
				m++;
				if(m == k)
					m = 0;
			}
			lastn = false;
		}
		else
		{
			for(int r = 0; r < k; ++r)
			{
				n[m] = temp[m] + temp[r];
				if(n[m] >= MOD)
					n[m] -= MOD;
				m++;
				if(m == k)
					m = 0;
			}
			lastn = true;
		}
	}
	if(!lastn)
	{
		n[0] = temp[0];
		printf("k = %d[ ", k);
		for(int i = 0; i < k; ++i)
			printf("%d ", temp[i]);
		printf("]\n");
	}
	else
	{
		printf("k = %d[ ", k);
		for(int i = 0; i < k; ++i)
			printf("%d ", n[i]);
		printf("]\n");
	}
	cache[k] = n[0];
}
/*map<long long, long long> rcache;
long long calc(long long i, long long r)
{
	if (i == 0)
		return (r == 0);
	long long key = (i << 32LL) + r;
	if(rcache.count(key) > 0)
		return rcache[key];
	long long res;
	res = calc(i - 1, r) + calc(i - 1, mod(r + a[i - 1], M));
	if (res >= MOD)
		res -= MOD;
	rcache[key] = res;
	return res;
}*/
int main()
{
	//scanf("%d", &T);
	T = input();
	while(T--)
	{
		//scanf("%d", &N);
		//scanf("%d", &Q);
		N = input();
		Q = input();
		for(int i = 0; i < N; ++i)
			//scanf("%d", &a[i]);
			a[i] = input();
		cache.clear();
		for(int i = 0; i < Q; ++i)
		{
			//rcache.clear();
			//scanf("%d", &M);
			M = input();
			if (M == 1)
				printf("%lld\n", bigmod(2, N, MOD) % MOD);
			else
			{
				calc();
				printf("%lld\n", n[0]);
				//printf("%lld\n", calc(N, 0));
			}
		}
	}
	return 0;
}
