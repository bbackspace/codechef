#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cctype>
#include<algorithm>
#include<vector>
#include<map>
#include<stdint.h>
#include<unistd.h>
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

int GCD[101][101];
int a[100];
int chosen[100];
int T, n;
FastInput fi;

void buildGCD()
{
	for(int i = 0; i <= 100; ++i)
		GCD[0][i] = GCD[i][0] = i;
	for(int i = 1; i <= 100; ++i)
		for(int j = 1; j <= i; ++j)
			GCD[j][i] = GCD[i][j] = GCD[j][i-j];
}

int chooseopt()
{
	for(int i = 0; i < n; ++i)
	{
		if(chosen[i])
			continue;
		int j;
		for(j = 0; j < n; ++j)
		{
			if(chosen[j] || i == j)
				continue;
			printf("GCD[%d][%d]=%d\n", a[i], a[j], GCD[a[i]][a[j]]);
			if(GCD[a[i]][a[j]] != 1)
				break;
		}
		if(j == n)
			return i;
	}
	return -1;
}
int optprob()
{
	memset(chosen, 0, 100 * sizeof(int));
	
}
/*
double rndprob(int j, int p)
{
	int i,k;
	int t;
	if (GCD[a[j]][p] == 1)
	{
		return (j % 2 ? 1.0 : 0.0);
	}
	
	//int hash[101];
	//memset(hash, 0, 101 * sizeof(int));
	for(i=j;i<strlen(a);++i)
	{
		t = a[i];
		//if(hash[t]>0)
			//continue;
		//hash[t]++;
		a[i] = a[j];
		a[j] = t;
		perm(a,j+1);
		t = a[j];
		a[j] = a[i];
		a[i] = t;
	}
}
*/
int main()
{
	buildGCD();
	T = fi.ReadNext();
	memset(chosen, 0, 100 * sizeof(int));
	
	while(T--)
	{
		n = fi.ReadNext();
		for(int i = 0; i < n; ++i)
			a[i] = fi.ReadNext();
		//printf("%d\n", chooseopt());
		printf("   ");
		for(int i = 0; i < n; ++i)
			printf("%2d ", a[i]);
		for(int i = 0; i < n; ++i)
		{
			printf("\n%2d ", a[i]);
			for(int j = 0; j < n; ++j)
			{
				printf("%2d ", GCD[a[i]][a[j]]);
			}
		}
		printf("\n\n");
		//printf("%d %0.4lf\n", optprob(), rndprob(0, 0));
	}
	return 0;
}