#include<stdio.h>
#include<stdlib.h>
int T, A, B, C, a, b, c;
bool nosol;
void get()
{
	nosol = false;
	a = 0;
	b = 0;
	c = 0;
	if (A == 0 || C == 0)
	{
		if(A != 0 || B != 0 || C != 0)
			nosol = true;
		return;
	}
	//Case: a = 0
	if (B == 0)
	{
		a = 0;
		int bplusc = A;
		int b2plusc2 = C;
		for(b = 1; b < bplusc && b * b < b2plusc2; ++b)
		{
			c = bplusc - b;
			if (b * b + c * c == b2plusc2)
				return;
		}
	}
	else
	{
		for(a = 1; a < A && a <= B && a * a < C; ++a)
		{
			if (B % a)
				continue;
			int bplusc = A - a;
			int bc = B / a;
			int b2plusc2 = C - a * a;
			for(b = 1; b < bplusc && b < bc && b * b < b2plusc2; ++b)
			{
				if(bc % b)
					continue;
				c = bplusc - b;
				if (b * c == bc && b * b + c * c == b2plusc2)
					return;
			}
		}
	}
	nosol = true;
}
bool invalid()
{
	if(A != a + b + c)
		return true;
	if(B != a * b * c)
		return true;
	if(C != a * a + b * b + c * c)
		return true;
	return false;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &A, &B, &C);
		get();
		if(nosol && invalid())
			printf("No solution.\n");
		else
			printf("%d %d %d\n", a, b, c);
	}
	return 0;
}