#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
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
FastInput fi;
unsigned T, N;
unsigned pairs[1562501];
void build()
{
	unsigned k, root, i, j;
	pairs[1] = 1;
	pairs[2] = 1;
	pairs[3] = 3;
	for(i = 3; i < 1562500; ++i)
	{
		//pairs[i + 1] = pairs[i] + extra in i;
		k = 0;
		root = sqrt((double)i);
		for(j = 1; j <= root; ++j)
			if(i % j == 0)
				k += 2;
		if(root * root == i)
			k--;
		pairs[i + 1] = pairs[i] + k;
	}
}
int getM(int N){
    int p,a,ans=0,j;
    p=0;
    for(j=1;j<=sqrt(N);j++,p++)
    {
        if(j*j==N)
            continue;

        a=N/j;
        if(j*a==N)
            a--;
            a-=p;
        ans+=2*a-1;
    }
    return ans;
}
long long nmat(int N)
{
	long long sum = 0;
	int mid = (N + 1) >> 1; //middle (or second median) of the sequence from 1 to N - 1
	for(int i = 1; i < mid; ++i)
		sum += (long long) getM(i * (N - i));
	sum*=2;
	if (N % 2)
		return sum;
	sum += (long long)getM(mid * mid);
	return sum;
}
int main()
{
	//build();
	T = fi.ReadNext();
	while(T--)
	{
		N = fi.ReadNext();
		printf("%lld\n", nmat(N));
	}
	return 0;
}
