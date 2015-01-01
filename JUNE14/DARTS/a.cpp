#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
#include<stdint.h>
#include<unistd.h>
using namespace std;
 
double a, b;
int c, d;
long long score;
int main()
{
	printf("0\n");
	srand(time(NULL));
	score = 0;
	for(int i = 0; i < 45; i++)
	{
		double r = (double)(rand() % 1000) * 0.0018 - 0.9;
		double theta = (double)(rand() % 1000) * M_PI / 5000;
		double x = sin(theta) * r;
		double y = cos(theta) * r;
		printf("%lf %lf\n", x, y);
		fflush(stdout);
		scanf("%lf %lf %d %d", &a, &b, &c, &d);
		score += c * d;
	}
	return 0;
}