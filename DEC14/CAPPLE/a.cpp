#include<bits/stdc++.h>
using namespace std;
int T, a[100001], N;
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> N;
		memset(a, 0, sizeof(a));
		for(int i = 0; i < N; i++)
		{
			cin >> a[0];
			a[a[0]] = 1;
		}
		a[0] = 0;
		for(int i = 1; i <= 100000; i++)
			a[0] += a[i];
		printf("%d\n", a[0]);
	}
}