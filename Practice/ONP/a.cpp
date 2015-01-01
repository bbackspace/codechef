#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

char a[401];
int T;
char ans[401], *p;
vector<char> stack;
int main()
{
	stack.reserve(400);
	scanf("%d ", &T);
	while(T--)
	{
		scanf("%s ", a);
		p = ans;
		*p = '\0';
		stack.clear();
		for(int i = 0; a[i]; i++)
		{
			if(a[i] >= 'a' && a[i] <= 'z')
				*p++ = a[i];
			else if(a[i] != ')')
				stack.push_back(a[i]);
			else
			{
				*p++ = stack.back();
				stack.pop_back();
				stack.pop_back();
			}
		}
		*p = '\0';
		printf("%s\n", ans);
	}
	return 0;
}