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
long long X[1000000];
long long D[1000000];
long long T, H, N, M, IND, A, B, ans;
FastInput fi;
#define sl(x) scanf("%lld", &(x))
int main()
{
	T = fi.ReadNext();
	//sl(T);
	while(T--)
	{
		H = fi.ReadNext();
		N = fi.ReadNext();
		M = fi.ReadNext();
		A = fi.ReadNext();
		B = fi.ReadNext();
		IND = fi.ReadNext();
		/*
		sl(H);
		sl(N);
		sl(M);
		sl(A);
		sl(B);
		sl(IND);*/
		for(int i = 0; i < M; ++i)
			D[i] = fi.ReadNext();
			//sl(D[i]);
		long long oldIND = IND;
		X[0] = 0;
		if(N >= 524288)
		{
			for(int i = 1; i < N; i++)
			{
				X[0] += D[IND];
				IND = A * IND + B;
				if(IND >= M)
					IND = IND % M;
			}
			ans = X[0] * H;
		}
		else
		{
			int k = 0;
			do
			{
				X[k + 1] = X[k] + D[IND];
				IND = A * IND + B;
				if(IND >= M)
					IND = IND % M;
				k++;
			}while(k < N && IND != oldIND);
			ans = X[k] * (N / k);
			ans += X[(N % k) - 1];
			ans *= H;
		}
		printf("%lld", ans / 2);
		if(ans % 2 == 0)
			printf(".0");
		else
			printf(".5");
		if(T)
			printf("\n");
	}
	return 0;
}