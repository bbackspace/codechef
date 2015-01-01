#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stdint.h>
#include<unistd.h>
#define EPS 0.0000001
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

bool gluInvertMatrix(const double m[16], double invOut[16])
{
    double inv[16], det;
    int i;

    inv[0] = m[5]  * m[10] * m[15] - 
             m[5]  * m[11] * m[14] - 
             m[9]  * m[6]  * m[15] + 
             m[9]  * m[7]  * m[14] +
             m[13] * m[6]  * m[11] - 
             m[13] * m[7]  * m[10];

    inv[4] = -m[4]  * m[10] * m[15] + 
              m[4]  * m[11] * m[14] + 
              m[8]  * m[6]  * m[15] - 
              m[8]  * m[7]  * m[14] - 
              m[12] * m[6]  * m[11] + 
              m[12] * m[7]  * m[10];

    inv[8] = m[4]  * m[9] * m[15] - 
             m[4]  * m[11] * m[13] - 
             m[8]  * m[5] * m[15] + 
             m[8]  * m[7] * m[13] + 
             m[12] * m[5] * m[11] - 
             m[12] * m[7] * m[9];

    inv[12] = -m[4]  * m[9] * m[14] + 
               m[4]  * m[10] * m[13] +
               m[8]  * m[5] * m[14] - 
               m[8]  * m[6] * m[13] - 
               m[12] * m[5] * m[10] + 
               m[12] * m[6] * m[9];

    inv[1] = -m[1]  * m[10] * m[15] + 
              m[1]  * m[11] * m[14] + 
              m[9]  * m[2] * m[15] - 
              m[9]  * m[3] * m[14] - 
              m[13] * m[2] * m[11] + 
              m[13] * m[3] * m[10];

    inv[5] = m[0]  * m[10] * m[15] - 
             m[0]  * m[11] * m[14] - 
             m[8]  * m[2] * m[15] + 
             m[8]  * m[3] * m[14] + 
             m[12] * m[2] * m[11] - 
             m[12] * m[3] * m[10];

    inv[9] = -m[0]  * m[9] * m[15] + 
              m[0]  * m[11] * m[13] + 
              m[8]  * m[1] * m[15] - 
              m[8]  * m[3] * m[13] - 
              m[12] * m[1] * m[11] + 
              m[12] * m[3] * m[9];

    inv[13] = m[0]  * m[9] * m[14] - 
              m[0]  * m[10] * m[13] - 
              m[8]  * m[1] * m[14] + 
              m[8]  * m[2] * m[13] + 
              m[12] * m[1] * m[10] - 
              m[12] * m[2] * m[9];

    inv[2] = m[1]  * m[6] * m[15] - 
             m[1]  * m[7] * m[14] - 
             m[5]  * m[2] * m[15] + 
             m[5]  * m[3] * m[14] + 
             m[13] * m[2] * m[7] - 
             m[13] * m[3] * m[6];

    inv[6] = -m[0]  * m[6] * m[15] + 
              m[0]  * m[7] * m[14] + 
              m[4]  * m[2] * m[15] - 
              m[4]  * m[3] * m[14] - 
              m[12] * m[2] * m[7] + 
              m[12] * m[3] * m[6];

    inv[10] = m[0]  * m[5] * m[15] - 
              m[0]  * m[7] * m[13] - 
              m[4]  * m[1] * m[15] + 
              m[4]  * m[3] * m[13] + 
              m[12] * m[1] * m[7] - 
              m[12] * m[3] * m[5];

    inv[14] = -m[0]  * m[5] * m[14] + 
               m[0]  * m[6] * m[13] + 
               m[4]  * m[1] * m[14] - 
               m[4]  * m[2] * m[13] - 
               m[12] * m[1] * m[6] + 
               m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] + 
              m[1] * m[7] * m[10] + 
              m[5] * m[2] * m[11] - 
              m[5] * m[3] * m[10] - 
              m[9] * m[2] * m[7] + 
              m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] - 
             m[0] * m[7] * m[10] - 
             m[4] * m[2] * m[11] + 
             m[4] * m[3] * m[10] + 
             m[8] * m[2] * m[7] - 
             m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] + 
               m[0] * m[7] * m[9] + 
               m[4] * m[1] * m[11] - 
               m[4] * m[3] * m[9] - 
               m[8] * m[1] * m[7] + 
               m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] - 
              m[0] * m[6] * m[9] - 
              m[4] * m[1] * m[10] + 
              m[4] * m[2] * m[9] + 
              m[8] * m[1] * m[6] - 
              m[8] * m[2] * m[5];

    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    if (det == 0)
        return false;

    det = 1.0 / det;

    for (i = 0; i < 16; i++)
        invOut[i] = inv[i] * det;

    return true;
}
int N;
double ct[4], cv[4];
double A, B, C, D;
double mat[16], inv[16];
double T, v;
void print(double mat[16])
{
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			printf("%0.2lf ", mat[4 * i + j]);
		}
		printf("\n");
	}
	printf("\n");
}
double distance(double A, double B, double C, double D, double &v)
{
	double distance = 0.0, lastv = D;
	double lastx = 0.0, x;
	bool flag = 0;
	//d = T * (D + T *(C/2.0 + T *(B/3.0 + A * T/4.0)));
	for(double t = 0.0; t <= T; t+=0.002)
	{
		v = D + t *(C + t *(B + A * t));
		if(v * lastv < EPS)
		{
			x = t * (D + t *(C/2.0 + t *(B/3.0 + A * t/4.0)));
			distance += fabs(x - lastx);
			lastx = x;
			flag = 1;
		}
		else
			flag = 0;
		lastv = v;
	}
	if(!flag)
	{
		x = T * (D + T *(C/2.0 + T *(B/3.0 + A * T/4.0)));
		distance += fabs(x - lastx);
	}
	return distance;
	double f,g,h, t;
	f = ((3*C/A)-((B*B)/(A*A)))/3;
	g = ((2*(B*B*B)/(A*A*A))-(9*B*C/(A*A))+(27*D/A))/27;   
	h = ((g*g)/4)+((f*f*f)/27);
      
    if(f==0 && g==0 && h==0){
		t = pow((D/A),0.33333333333333333333333333333333);
		distance = t * (D + t *(C/2.0 + t *(B/3.0 + A * t/4.0)));
	}
	else if(h<=0){
		i = pow((((g*g)/4)-h),0.5);
		j = pow(i,0.33333333333333333333333333333333);
		k = acos((g/(2*i))*-1);
		l = j * -1;
		m = cos(k/3);
		n = sqrt(3) * sin(k/3);
		p = (b/(3*a))*-1;
		x1 = (2*j)*m-(b/(3*a));
		x2 = l * (m+n) + p;
		x3 = l * (m-n) + p;
	}
}
int main()
{
	scanf("%d", &N);
	while(N--)
	{
		scanf("%lf", &T);
		for(int i = 0; i < 4; ++i)
		{
			scanf("%lf", &ct[i]);
			scanf("%lf", &cv[i]);
		}
		for(int i = 0; i < 4; ++i)
		{
			mat[4 * i + 3] = 1.0;
			for(int j = 2; j >= 0; --j)
			{
				mat[4 * i + j] = mat[4 * i + j + 1] * ct[i];
			}
		}
		//print(mat);
		gluInvertMatrix(mat, inv);
		//print(inv);
		A = inv[0] * cv[0] + inv[1] * cv[1] + inv[2] * cv[2] + inv[3] * cv[3];
		B = inv[4] * cv[0] + inv[5] * cv[1] + inv[6] * cv[2] + inv[7] * cv[3];
		C = inv[8] * cv[0] + inv[9] * cv[1] + inv[10] * cv[2] + inv[11] * cv[3];
		D = inv[12] * cv[0] + inv[13] * cv[1] + inv[14] * cv[2] + inv[15] * cv[3];
		//printf("%lf %lf %lf %lf\n", A, B, C, D);
		printf("%lf\n", distance(A, B, C, D, v));
	}
	return 0;
}