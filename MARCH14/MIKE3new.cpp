#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<stdint.h>
#include<unistd.h>

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
int a[20][20001] = {0};
int x[20];
int N, M;
int max;
int c;
class BitVector
{
private:
	bool *vec;
	size_t *from;
	size_t *to;
	size_t top;
	bool init_val;
	size_t len;

	void setVal(size_t i, bool value)
	{
		if (from[i] < top && to[from[i]] == i)
			vec[i] = value;
		else
		{
			from[i] = top;
			to[top] = i;
			vec[i] = value;
			top++;
		}
	}

public:
	BitVector(size_t len_)
	{
		vec = new bool[len_];
		from = new size_t[len_];
		to = new size_t[len_];
		resetAll();
		len = len_;
	}

	void set(size_t i)
	{
		setVal(i, true);
	}

	void reset(size_t i)
	{
		setVal(i, false);
	}

	bool test(size_t i)
	{
		if (from[i] < top && to[from[i]] == i)
			return vec[i];
		else
			return init_val;
	}

	void setAll()
	{
		top = 0;
		init_val = true;
	}

	void resetAll()
	{
		top = 0;
		init_val = false;
	}

	~BitVector()
	{
		delete[] vec;
		delete[] from;
		delete[] to;
	}
};

int isDisjoint()
{
	static int hash[20001];
	memset(hash, 0, 20001 * sizeof(int));
	/*for(int j = 1; j <= N; ++j)
	{
		int flag = 0;
		for(int i = 0; i < M; ++i)
		{
			if(x[i] == 0)
				continue;
			if(j <= a[i][0])
			{
				if(hash[a[i][j]]++ > 0)
					return 0;
				flag = 1;
			}
		}
		if(!flag)
			break;
	}
	*/
	for(int i = 0; i < M; ++i)
	{
		if(x[i] == 0)
			continue;
		for(int j = 1; j <= a[i][0]; ++j)
		{
			if(hash[a[i][j]]++ > 0)
				return 0;
		}
	}
	return 1;
}
class Pair
{
public:
	int x;
	int y;
};
class IgnorePairs
{
public:
	Pair a[200];
	int N;
	IgnorePairs()
	{
		N = 0;
	}
	void add(int x, int y)
	{
		Pair p = {x, y};
		a[N++] = p;
	}
} ip;
int numg;
int selectoffers(int num, int start, int pairs)
{
	if(!pairs && numg - num >= 2)
	{
		for(int i = 0; i < ip.N; ++i)
		{
			if(x[ip.a[i].x] && x[ip.a[i].y])
				return 0;
		}
	}
	if(num == 0)
	{
		/*printf("[");
		for(int i = 0; i < M; ++i)
			printf("%d ", x[i]);
		printf("]\n");*/
		int dis = isDisjoint();
		if(pairs && !dis)
		{
			int a1 = -1, a2;
			for(int i = 0; i < M; ++i)
				if(x[i])
					if(a1 == -1)
						a1 = i;
					else
					{
						a2 = i;
						break;
					}
			ip.add(a1, a2);
		}
		return dis;
	}
	for(int i = start; i < M; ++i)
	{
		x[i] = 1;
		if(selectoffers(num - 1, i + 1, pairs))
			return 1;
		x[i] = 0;
	}
	return 0;
}
FastInput fi;
int main()
{
	clock_t starttime, endtime;
	starttime = clock();
	//scanf("%d %d", &N, &M);
	N = fi.ReadNext();
	M = fi.ReadNext();
	for(int i = 0; i < M; ++i)
	{
		//scanf("%d", &a[i][0]);
		a[i][0] = fi.ReadNext();
		for(int j = 0; j < a[i][0]; ++j)
		{
			//scanf("%d", &a[i][j + 1]);
			a[i][j + 1] = fi.ReadNext();
		}
	}
	int i;
	for(i = 2; i <= M; ++i)
	{
		numg = i;
		int possible = (i == 2 ? selectoffers(i, 0, 1) : selectoffers(i, 0, 0));
		if(!possible)
			break;
	}
	printf("%d\n", i - 1);
	endtime = clock();
	printf("Time : %6.3f", (double)endtime - starttime);
	return 0;
}