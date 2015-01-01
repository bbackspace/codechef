#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
int N;
int x1, y1, x2, y2, x3, y3;
int max, min, minindex, maxindex, area;

inline int abs(int a)
{
	return (a >= 0) ? a : -a;
}
inline int getArea()
{
	return abs((x2 * y3 - x3 * y2) - (x1 * y3 - x3 * y1) + (x1 * y2 - x2 * y1));
}
int main()
{
	scanf("%d", &N);
	minindex = 0;
	maxindex = 0;
	min = INT_MAX;
	max = INT_MIN;
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
		area = getArea();
		//printf("%d - %d\n", i, area);
		if(area >= max)
		{
			max = area;
			maxindex = i;
		}
		if(area <= min)
		{
			min = area;
			minindex = i;
		}
	}
	printf("%d %d\n", minindex, maxindex);
	return 0;
}