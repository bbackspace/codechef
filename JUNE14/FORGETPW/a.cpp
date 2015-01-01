#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int T, N;
char rules[128];
char encstr[1000002], *enc;
char pass[1000002], *passend;
char *num;
int main()
{
	scanf("%d ", &T);
	while(T--)
	{
		scanf("%d ", &N);
		for(int i = 0; i < 128; i++)
			rules[i] = 0;
		char c;
		for(int i = 0; i < N; i++)
		{
			scanf("%c ", &c);
			scanf("%c ", &rules[c]);
		}
		scanf("%s ", encstr);
		passend = pass;
		for(enc = encstr; *enc; enc++)
			*passend++ = (rules[*enc] ? rules[*enc] : *enc);
		*passend = '\0';
		num = pass;
		while(*num == '0')
			num++;
		if(strchr(num, '.'))
		{
			passend--;
			while(passend > num && *passend == '0')
				passend--;
			if(passend > num && *passend == '.')
				passend--;
			*(passend + 1) = '\0';
		}
		if(*num == '\0' || strcmp(num, ".") == 0)
			printf("0\n");
		else
			printf("%s\n", num);
	}
	return 0;
}