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
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int T, A, ans;
char Bstr[251];
int main()
{
	sll(T);
	while(T--)
	{
		si(A);
		ss(Bstr);
		if(A == 0)
			printf("%s\n", Bstr);
		else
		{
			int B = (Bstr[0] - '0') % A;
			for(int i = 1; Bstr[i]; i++)
			{
				B = (B * 10 + (Bstr[i] - '0')) % A;
			}
			ans = gcd(A, B);
			printf("%d\n", ans);
		}
	}
	return 0;
}