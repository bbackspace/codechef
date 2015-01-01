#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
char str[2014];
int T, ans;
bool ja(int in)
{
	if(str[in] != '?' && str[in] != 'C')
		return false;
	in++;
	if(str[in] != '?' && str[in] != 'H')
		return false;
	in++;
	if(str[in] != '?' && str[in] != 'E')
		return false;
	in++;
	if(str[in] != '?' && str[in] != 'F')
		return false;
	return true;
}
int main()
{
	si(T); getchar();
	while(T--)
	{
		ss(str); getchar();
		int l = strlen(str);
		for(int i = l - 1; i - 3 >= 0; i--)
		{
			if(ja(i - 3))
			{
				str[i - 3] = 'C';
				str[i - 2] = 'H';
				str[i - 1] = 'E';
				str[i] = 'F';
			}
		}
		for(int i = 0; i < l; i++)
		{
			if(str[i] == '?')
				str[i] = 'A';
		}
		printf("%s\n", str);
	}
	return 0;
} 