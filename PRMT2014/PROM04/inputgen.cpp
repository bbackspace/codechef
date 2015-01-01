#include<cstdio>
int main()
{
	for(int i = 0; i < 10; ++i)
	{
		printf("100000\n");
		for(int j = 100000; j >= 1; --j)
			printf("%d ", j);
		printf("\n");
	}
}