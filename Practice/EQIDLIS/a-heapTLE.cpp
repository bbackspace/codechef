#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<stdint.h>
#include<unistd.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)
//#define DEBUG
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
int a[3000];
int T, N, ans;
vector<int> min_heap;
vector<int> max_heap;
bool cmp(const int &a, const int &b)
{
	return a > b;
}
FastInput fi;
int main()
{
	min_heap.reserve(3000);
	max_heap.reserve(3000);
	T = fi.ReadNext();
	while(T--)
	{
		min_heap.clear();
		max_heap.clear();
		N = fi.ReadNext();
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			a[i] = fi.ReadNext();
			sum += a[i];
		}
		sort(a, a + N);
		for(int i = 0; i < N / 2; i++)
			min_heap.push_back(a[i]);
		//make_heap(min_heap.begin(), min_heap.end(), cmp);
		for(int i = N / 2; i < N; i++)
			max_heap.push_back(a[i]);
		reverse(max_heap.begin(), max_heap.end());
		//make_heap(max_heap.begin(), max_heap.end());
#ifdef DEBUG
		printf("a[]:");
		for(int i = 0; i < N; i++)
			printf("%d ", a[i]);
		printf("\nmin_heap[]:");
		for(int i = 0; i < min_heap.size(); i++)
			printf("%d ", min_heap[i]);
		printf("\nmax_heap[]:");
		for(int i = 0; i < max_heap.size(); i++)
			printf("%d ", max_heap[i]);
		printf("\n");
#endif
		if(sum % N)
			printf("-1\n");
		else
		{
			ans = 0;
			while(min_heap[0] != max_heap[0])
			{
				pop_heap(min_heap.begin(), min_heap.end(), cmp);
				pop_heap(max_heap.begin(), max_heap.end());
				ans++;
				int r = (max_heap.back() - min_heap.back() + 1)/2;
				min_heap.back() += r;
				max_heap.back() -= r;
				if(min_heap.back() > max_heap.back())
					swap(min_heap.back(), max_heap.back());
				push_heap(min_heap.begin(), min_heap.end(), cmp);
				push_heap(max_heap.begin(), max_heap.end());
#ifdef DEBUG
				printf("\nmin_heap[]:");
				for(int i = 0; i < min_heap.size(); i++)
					printf("%d ", min_heap[i]);
				printf("\nmax_heap[]:");
				for(int i = 0; i < max_heap.size(); i++)
					printf("%d ", max_heap[i]);
				printf("\n");
#endif
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}