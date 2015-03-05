#include<bits/stdc++.h>
using namespace std;
char str[10001];
int T;
int main()
{
	cin >> T;
	while(T--)
	{
		cin>>str;
		int x = 0, i;
		for(i = 0; str[i]; i++)
		{
			if(i % 2 && str[i] == '+')
				x++;
			else if(i % 2 == 0 && str[i] == '-')
				x++;
		}
		cout << min(i - x, x) << endl;
	}
	return 0;
} 