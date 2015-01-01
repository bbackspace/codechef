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
int a[1000][1000];
int T, N, Q, V, M, A, B;
FastInput fi;
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < N; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
long long dijkstra(int src)
{
     int dist[1000];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
 
     bool sptSet[1000]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
 
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < N; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
 
     // Find shortest path for all vertices
     for (int count = 0; count < N-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
 
       // Mark the picked vertex as processed
       sptSet[u] = true;
 
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < N; v++)
 
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && a[u][v] && dist[u] != INT_MAX && dist[u]+a[u][v] < dist[v])
            dist[v] = dist[u] + a[u][v];
     }
 
     long long s = 0;
     for(int i = 0; i < N; i++)
		s += (dist[i] < INT_MAX ? dist[i] : 0);
	return s;
}
int main()
{
	scanf("%d ", &T);
	while(T--)
	{
		scanf("%d ", &N);
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				scanf("%c", &a[i][j]);
				a[i][j] -= '0';
			}
			getchar();
		}
		scanf("%d ", &Q);
		while(Q--)
		{
			scanf("%d %d ", &V, &M);
			for(int i = 0; i < M; ++i)
			{
				scanf("%d %d ", &A, &B);
				a[A - 1][B -1] = ! a[A - 1][B -1];
			}
			printf("%lld\n", dijkstra(V - 1));
		}
	}
	return 0;
}