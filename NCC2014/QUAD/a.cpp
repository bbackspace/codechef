#include<cstdio>
int N;
char hex[100010];
char N1[200010];
char N2[200010];
char sum[200010];
int main()
{
	scanf("%d", &N);
	scanf("%s", hex);
	for(int i = 0; i < N; ++i)
	{
		if(hex[i] >= '0' && hex[i] <= '9')
		{
			hex[i] -='0';
		}
		else
		{
			hex[i] -= 'A' - 10;
		}
		N1[2 * i] = ((hex[i] & 0x08) ? 1 : 0);
		N1[2 * i + 1] = ((hex[i] & 0x04) ? 1 : 0);
		N2[2 * i] = ((hex[i] & 0x02) ? 1 : 0);
		N2[2 * i + 1] = ((hex[i] & 0x01) ? 1 : 0);
	}
	int carry = 0;
	for(int i = 2 * N - 1; i >= 0; --i)
	{
		sum[i] = N1[i] + N2[i] + carry + '0';
		if(sum[i] >= '2')
		{
			carry = 1;
			sum[i] -= 2;
		}
		else
			carry = 0;
		//N1[i] += '0';
		//N2[i] += '0';
	}
	sum[2*N] = '\0';
	//N1[2*N] = N2[2*N] = '\0';
	printf("%s\n", sum);
	return 0;
}