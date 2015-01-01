#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
long long P, Q, res;
int main()
{
	while(1)
	{
		scanf("%d %d", &P, &Q);
		if(P == 0 && Q == 0)
			break;
		if (P < Q)
		{
			long long temp = P;
			P = Q;
			Q = temp;
		}
		res = Q * P * (P + Q - 2);
		long long diags = Q * (Q - 1) * (2 * Q - 1 + 3 * (P - Q))/3;
		res += 2 * diags;
		printf("%lld\n", res);
	}
	return 0;
}