#include<cstdio>
#include<cstdlib>
#include<cctype>
int T;
char S[1001];
int main()
{
	scanf("%d ", &T);
	while(T--)
	{
		scanf("%[^\n] ", S);
		for(int i = 0; S[i]; ++i)
		{
			if(S[i] >= 'i' && S[i] <= 'r')
				S[i] -= 'i' - '0'; //0-9
			else if(S[i] >= 'a' && S[i] <= 'h')
				S[i] += 's' - 'a'; //s-z
			else if(S[i] >= 's' && S[i] <= 'z')
				S[i] -= 'y' - 'g'; //a-h
			else if(S[i] >= '0' && S[i] <= '9')
				S[i] += 'i' - '0';
		}
		printf("%s\n", S);
	}
	return 0;
}