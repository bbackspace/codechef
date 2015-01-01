#include<cstdio>
#include<ctime>
#include<cstdlib>
int a[20000];
int main()
{
	srand(time(NULL));
	printf("20000 20\n");
	for(int i = 0; i < 20; ++i)
	{
/*		int c = 0;
		for(int j = 0; j < 20000; ++j)
			a[j] = 0;
		for(int j = 0; j < 20000; ++j)
			a[rand() % 20000] = 1;
		for(int j = 0; j < 20000; ++j)
			if(a[j])
				c++;
		printf("%d ", c);
		for(int j = 0; j < 20000; ++j)
			if(a[j])
				printf("%d ", j + 1);*/
		printf("1000 ");
		for(int j = 1; j <= 1000; ++j)
			printf("%d ", j + i * 1000);
		printf("\n");
	}
}