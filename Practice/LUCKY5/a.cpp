#include<cstdio>
#include<cstring>
#include<cctype>
int T, ans;
char c;
int main()
{
	scanf("%d ", &T);
	while(T--)
	{
		ans = 0;
		while((c = getchar()) == 0);
		if(c != '4' && c != '7')
			ans++;
		while((c = getchar()) != '\n')
			if(isdigit(c) && c != '4' && c != '7')
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}