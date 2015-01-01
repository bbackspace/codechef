#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
#include<stdint.h>
#include<unistd.h>
int T, P, i;
unsigned fib[44] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170};
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &P);
		bool start = false;
		for(i = 43; i--; )
		{
			if (P >= fib[i]) {
				printf("1");
				P -= fib[i];
				start = true;
			}
			else if(start)
				printf("0");
		}
		printf("\n");
	}
	return 0;
}