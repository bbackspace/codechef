#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<iomanip>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()
ll twotofloorlog2(ll x)
{
	while(x & (x - 1))
		x = x & (x - 1);
	return x;
}
bool getcolor(ll x) //true = red
{
	bool col = true;
	while(x > 0)
	{
		x >>= 1;
		col = !col;
	}
	return col;
}
int firstBit(ll x)
{
	int i = 0;
	while(x)
	{
		x >>= 1;
		i++;
	}
	return i - 1;
}
int Q;
char str[3];
int x, y, r, b;
bool inv = false;
int main()
{
	si(Q);
	while(Q--)
	{
		ss(str);
		if(str[1] == 'i')
			inv = !inv;
		else
		{
			si(x);
			si(y);
			if (x > y)
				swap(x, y);
			int dist = firstBit(y) - firstBit(x);
			bool col = getcolor(y);
			if(col) //red
			{
				r = (dist + 1) / 2;
				b = dist / 2;
			}
			else
			{
				r = dist / 2;
				b = (dist + 1) / 2;
			}
			y >>= dist;
			col = (col != (dist & 1)); //XOR
			while(x != y)
			{
				if(col)
					r += 2;
				else
					b += 2;
				col = !col;
				x >>= 1;
				y >>= 1;
			}
			if(col)
				r++;
			else
				b++;
			if((str[1] == 'r' && !inv) || (str[1] == 'b' && inv))
				printf("%d\n", r);
			else
				printf("%d\n", b);
		}
		
	}
	return 0;
} 