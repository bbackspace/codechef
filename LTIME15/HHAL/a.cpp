#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<string>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
bool ispalin(string s, int start, int end)
{
	int l = (signed)s.length();
	int k = 0;
	for(int i = start % l, j = end % l; k <= l/2; i = (i + 1) % l, j = (j - 1 + l) % l, k++)
		if(s[i] != s[j])
			return false;
	return true;
}

string s;
int T, ans;
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> s;
		if(ispalin(s, 0, s.length() - 1))
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}