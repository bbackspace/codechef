#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<climits>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
int getDayOfWeek(int month, int day, int year, int CalendarSystem = 1)
{
     if (month < 3)
     {
           month = month + 12;
           year = year - 1;
     }
     return (
             day
             + (2 * month)
             + int(6 * (month + 1) / 10)
             + year
             + int(year / 4)
             - int(year / 100)
             + int(year / 400)
             + CalendarSystem
            ) % 7;
}
using namespace std;
int T, N, d, m, y;
char days[7][20] = {
"Sunday",
"Monday",
"Tuesday",
"Wednesday",
"Thursday",
"Friday",
"Saturday"
};
int h[7];
int t[7];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(h, 0, 7 * sizeof(int));
		memset(t, 0, 7 * sizeof(int));
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
		{
			scanf("%d %d %d", &d, &m, &y);
			h[getDayOfWeek(d, m, y)]++;
		}
		for(int i = 0; i < 4; ++i)
		{
			int min = 0;
			for(int j = 0; j < 7; ++j)
			{
				if(h[min] > h[j] && t[j] != 1)
				{
					min = j;
				}
			}
			t[min] = 1;
		}
		for(int i = 0; i < 7;++i)
		{
			if(t[i])
				printf("%s\n", days[i]);
		}
	}
	return 0;
}