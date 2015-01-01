#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int isprime(unsigned int n)
{
	for(unsigned int i=2;i<=n/2;++i)
		if(n%i==0) return 0;
	return 1;
}
int main()
{
	unsigned long *Primes=NULL;
	Primes=(unsigned long*)malloc(10000000*sizeof(long));
	memset(Primes,-1, 10000000*sizeof(long));
	unsigned long n,i,s,k=0;
	int flag;
//	FILE *fp=fopen("primes.txt","w");
	for(n=2;n <= 120;++n)
	{
		flag=1;
		s=sqrt(n);
		for(i=0;Primes[i]<=s;++i)
			if(n%Primes[i]==0)
			{
				flag=0;
				break;
			}
		if(flag)
		{
			Primes[k++]=n;
			if (n == 100000000)
			{
//				fprintf(fp,"%lu\n",n);
				printf("\r%lu - %lu",n,k);
				break;
			}
		}
	}
	for(int i = 0; i < k; ++i)
	{
		printf("%u ", Primes[i]);
	}
	free(Primes);
//	fclose(fp);
	return 0;
}
/*
int main()
{
	unsigned char *PD=NULL;
	PD=(unsigned char*)malloc(10000000);
	memset(PD,-1,10000000);
	unsigned long n,i,s,k=0,t,prevn=0;
	int flag;
	for(n=2;;++n)
	{
		flag=1;
		s=sqrt(n);
		t=PD[0];
		for(i=0;t<=s;++i,t+=PD[i])
			if(n%t==0)
			{
				flag=0;
				break;
			}
		if(flag)
		{
			if(n-prevn>255)
				printf("%lu\n",n-prevn);
			PD[k++]=n-prevn;
			//if (k%132==0)
			printf("%lu\r",n);
			prevn=n;
		}
	}
	free(PD);
	return 0;
}*/