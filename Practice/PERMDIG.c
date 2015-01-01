#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum {FALSE, TRUE} bool;
typedef struct
{
	int base;
	int dig[40];
} Num;

bool isPerm(Num a, Num b)
{
	int hash[9] = {0};
	int i;
	for(i = 0; i < 40; ++i)
	{
		hash[a.dig[i]]++;
		hash[b.dig[i]]--;
	}
	for(i = 0; i < 9; ++i)
		if(hash[i] != 0)
			return FALSE;
	return TRUE;
}

void set(Num *a, char *str, int base)
{
	a->base = base;
	int i, l=strlen(str);
	for(i = 0; i < l; ++i)
		a->dig[i] = str[l - i - 1];
	for(; i < 40; ++i)
		a->dig[i] = 0;
}

long long getVal(Num a)
{
	long long val = 0LL;
	int i;
	for(i = 0; i < 40; ++i)
		val = val * a.base + a.dig[i];
}

