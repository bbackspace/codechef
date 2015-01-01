#include<iostream>
#include<cstdio>
using namespace std;

long fx,fy;
int check(long x,long y,long step,int dir)
{
	long i;
	if(dir==0)
	{
		for(i=x-step;i<=x;++i)
		{
			if(fx==i && fy==y)
				return 1;
		}
	}
	else if(dir==1)
	{
		for(i=y-step;i<=y;++i)
		{
			if(fx==x && fy==i)
				return 1;
		}
	} else if(dir==2)
	{
		for(i=x;i<=x+step;++i)
		{
			if(fx==i && fy==y)
				return 1;
		}
	} else if(dir==3)
	{
		for(i=y;i<=y+step;++i)
		{
			if(fx==x && fy==i)
				return 1;
		}
	}
	else
	{
		if(fx==x && fy==y)
			return 1;
	}
	return 0;
}

int main()
{
	long x=0,y=0,step=0;
	int dir=-1,res;
	int T;
	scanf("%d", &T);
	while(T--)
	{
		x = y = step = 0;
		dir = -1;
		scanf("%d %d", &fx, &fy);
		do
		{
			res=check(x,y,step,dir);
			if(res==1)
			{
				printf("YES\n");
				break;
			}
			else if(x>fx && y>fy)
			{
				printf("NO\n");
				break;
			}
			//
			dir++;
			if(dir==4)
				dir=0;
			step++;
			if(dir==0)
				x=x+step;
			else if(dir==1)
				y=y+step;
			else if(dir==2)
				x=x-step;
			else if(dir==3)
			{
				y=y-step;
			}
		}while(1);
	}
}