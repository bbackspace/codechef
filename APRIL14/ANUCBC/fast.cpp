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
   if(s >= buf + maxio) { fread_unlocked(buf,sizeof(char),maxio,stdin); s = buf; }
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
long long x[100];
int sumx;
inline int mod(int a, int k)
{
	if (a >= 0)
		return a % k;
	return k - ((-a) % k);
}
long long choose(long long n, long long k)
{
	long long prod = 1;
	for(long long i = 1; i <= k; ++i)
		prod = (prod * (n - (k - i))) / i;
	return prod;
}
long long makesum(int i, int s)
{
	if(i == 0)
	{
		
	}
	long long sum = 0;
	for(int j = i; j >= 0; --j)
	{
		if(x[j] == 0)
			continue;
		sum += x[j] * makesum(j - 1, s - j);
	}
	return sum;
}
long long calc()
{
	long long res = 0;
	memset(x, 0, M * sizeof(long long));
	for(int i = 0; i < N; ++ i)
		x[mod(a[i], k)]++;
	sumx = 0;
	for(int i = 0; i < M; ++i)
		sumx += x[i] * i;
	for(int s = M; s <= sumx; s += M)
	{
		res = (res + makesum(M - 1, s)) % MOD;
	}
	return res;
}
int main()
{
	T = input();
	while(T--)
	{
		N = input();
		Q = input();
		for(int i = 0; i < N; ++i)
			a[i] = input();
		for(int i = 0; i < Q; ++i)
		{
			M = input();
			printf("%lld\n", calc());
		}
	}
	return 0;
}
