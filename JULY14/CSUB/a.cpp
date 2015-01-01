#include<cstdio>
long long T, N, ans;
char s[100000];
int main()
{
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &N);
		scanf("%s", s);
		ans = 0;
		for(int i = 0; i < N; ++i)
			if(s[i] == '1')
				ans++;
		printf("%lld\n", (ans * (ans + 1)) / 2);
	}
	return 0;
}