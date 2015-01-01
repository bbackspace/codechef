#include<cstdio>
#include<ctime>
#include<cstdlib>
int a[20000];
int main()
{
	srand(time(NULL));
	printf("100000 100000\n");
	for(int i = 0; i < 100000; ++i)
	{
		printf("%d", rand() % 10);
	}
	for(int i = 0; i < 100000; ++i)
	{
		printf("100000\n");
	}
}