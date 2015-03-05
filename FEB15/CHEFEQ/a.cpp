#include<bits/stdc++.h>
using namespace std;
int a[100001];
int h[100001];
int T, N;
int main()
{
	cin >> T;
	while(T--)
	{
		memset(h, 0, sizeof(h));
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> a[i];
		for(int i = 0; i < N; i++)
			h[a[i]]++;
		int ans = 0;
		for(int i = 1; i <= 100000; i++)
			ans = max(ans, h[i]);
		printf("%d\n", N - ans);
	}
	return 0;
} 