#include<stdio.h>
int freq[26];
char a[1001];
int T, i, flag;
int main()
{
	scanf("%d ", &T);
	while(T--)
	{
		scanf("%s ", a);
		for(i = 0; i < 26; i++)
			freq[i] = 0;
		for(i = 0; i < strlen(a) / 2; i++)
			freq[a[i] - 'a']++;
		for(i = (strlen(a) + 1) / 2; a[i]; i++)
			freq[a[i] - 'a']--;
		flag = 0;
		for(i = 0; i < 26; i++)
			if(freq[i] != 0)
			{
				flag = 1;
				break;
			}
		if(!flag)
			write(1, "YES\n", 4);
		else
			write(1, "NO\n", 3);
	}
	return 0;
}