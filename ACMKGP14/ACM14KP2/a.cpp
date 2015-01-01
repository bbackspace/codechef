#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<iomanip>
#include<stdint.h>
#include<unistd.h>
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x))
#define sll(x) scanf("%lld", &(x))
#define ss(x) scanf("%s", x)
#define sc(x) scanf("%c", &(x))
#define sline(x) scanf("%[^\n]", x)

ll  _mergesort(int array[], int t[], int left, int right);
ll merge(int array[], int t[], int left, int mid, int right);
  
ll mergeSort(int array[], int n)
{
	int *t = (int *)malloc(sizeof(int)*n);
	return _mergesort(array, t, 0, n - 1);
}
  
ll _mergesort(int array[], int t[], int left, int right)
{
	int mid;
	ll inv = 0;
	if (right > left)
	{
		mid = (right + left)/2;
		inv  = _mergesort(array, t, left, mid);
		inv += _mergesort(array, t, mid+1, right);
		inv += merge(array, t, left, mid+1, right);
	}
	return inv;
}

ll merge(int array[], int t[], int left, int mid, int right)
{
  int i, j, k;
  ll inv = 0;
  
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (array[i] <= array[j])
    {
      t[k++] = array[i++];
    }
    else
    {
      t[k++] = array[j++];
  
      inv += (mid - i);
    }
  }
  
  while (i <= mid - 1)
    t[k++] = array[i++];
  
  while (j <= right)
    t[k++] = array[j++];
  
  for (i=left; i <= right; i++)
    array[i] = t[i];
  
  return inv;
}
  
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
int a[100000];
int T, N;
ll ans, k;
FastInput fi;
bool dupexists(int array[], int n)
{
	int x[100001];
	memset(x, 0, sizeof(x));
	for(int i = 0; i < n; i++)
	{
		if(++x[array[i]] == 2)
			return true;
	}
	return false;
}
int main()
{
	T = fi.ReadNext();
	for(int t = 1; t <= T; t++)
	{
		N = fi.ReadNext();
		k = fi.ReadNext();
		for(int i = 0; i < N; ++i)
			a[i] = fi.ReadNext();
		ans = mergeSort(a, N);
		ans -= k;
		if(ans < 0)
		{
			if(dupexists(a, N))
				ans = 0;
			else
				ans = (-ans) % 2;
		}
		printf("Case %d: %lld\n", t, ans);
	}
	return 0;
} 