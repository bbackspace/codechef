#pragma warning(disable:4996)
#include<stdio.h>
int main()
{
	int t,testdetails[10][2],a[10][100],flageven=0,i,j;
	scanf("%d",&t);
	for(i=0;i<t;++i)
	{
		scanf("%d %d",&testdetails[i][0],&testdetails[i][1]);
		for(j=0;j<testdetails[i][0];++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//End of input..
	//Logic processing...
	for(i=0;i<t;++i)
	{
		for(j=0;j<testdetails[i][0];++j)
		{
			if(a[i][j] % 2 == 0)
				flageven++;
		}
		if(flageven == testdetails[i][0])
			printf("NO\n");
		else if(flageven>=testdetails[i][1])
			printf("YES\n");
		else
			printf("NO\n");
		flageven=0;
	}
}