#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
#include<vector>
#include<stdint.h>
#include<unistd.h>

#define DEBUG
using namespace std;
class FastInput {
	public:
		FastInput() {
			m_dataOffset = 0;
			m_dataSize = 0;
			m_v = 0x80000000;
		}
		uint32_t ReadNext() {
			if (m_dataOffset == m_dataSize) {
				int r = read(0, m_buffer, sizeof(m_buffer));
				if (r <= 0) return m_v;
				m_dataOffset = 0;
				m_dataSize = 0;
				int i = 0;
				if (m_buffer[0] < '0') {
					if (m_v != 0x80000000) {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
					}
					for (; (i < r) && (m_buffer[i] < '0'); ++i);
				}
				for (; i < r;) {
					if (m_buffer[i] >= '0') {
						m_v = m_v * 10 + m_buffer[i] - 48;
						++i;
					} else {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
						for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
					}
				}
			}
			return m_data[m_dataOffset++];
		}
	public:
		uint8_t m_buffer[32768];
		uint32_t m_data[16384];
		size_t m_dataOffset, m_dataSize;
		uint32_t m_v;
};

int T, N;
int a[100001];
vector<vector<int> > s(100001);
map<int,int> un;
int cnt;
FastInput fi;
bool compare(vector<int> x, vector<int> y)
{
	return a[*(x.rbegin())] < a[*(y.rbegin())];
}

void rprint(vector<vector<int> >::reverse_iterator i, int max, int index)
{
	if (i == s.rend())
	{
		return;
	}
	vector<int> element = *i;
	vector<int>::iterator j;
	for(j = element.begin(); j < element.end(); j++)
	{
		if(a[*j] < max && *j < index)
		{
			if(un[a[*j]] != 1)
			{
				cnt++;
				un[a[*j]] = 1;
			}
			rprint(i + 1, a[*j], *j);
		}
	}
}
int main()
{
	T = 10;
	while(T--)
	{
		N = fi.ReadNext();
		for(int i = 0; i < N; ++i)
		{
			a[i] = fi.ReadNext();
		}
		s.clear();
		vector<int> x;
		x.push_back(0);
		s.push_back(x);
		for(int i = 1; i < N; ++i)
		{
			vector<int> x;
			x.push_back(i);
			if(a[*((*(s.rbegin())).rbegin())] < a[i])
			{
				s.push_back(x);
			}
			else
			{
				vector<vector<int> >::iterator pos;
				pos = lower_bound(s.begin(), s.end(), x, compare);
				(*pos).push_back(i);
			}
		}
#ifdef DEBUG
		vector<vector<int> >::iterator p;
		printf("[ ");
		for(p = s.begin(); p != s.end(); p++)
		{
			vector<int> element = *p;
			vector<int>::iterator j;
			printf("( ");
			for(j = element.begin(); j != element.end(); j++)
			{
				printf("%d ", *j);
			}
			printf(") ");
		}
		printf("]\n");
#endif
		cnt = 0;
		un.clear();
		rprint(s.rbegin(), INT_MAX, INT_MAX);
		map<int, int>::iterator pos;
		printf("%d\n", cnt);
		for(pos = un.begin(); pos != un.end(); pos++)
		{
			if(pos != un.begin())
				printf(" ");
			printf("%d", pos->first);
		}
		printf("\n");
	}
	return 0;
}