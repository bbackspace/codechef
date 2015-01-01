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
typedef long long ll;
using namespace std;
#define si(x) scanf("%d", &(x)); getchar()
#define sll(x) scanf("%lld", &(x)); getchar()
#define ss(x) scanf("%s", x); getchar()
#define sc(x) scanf("%c", &(x)); getchar()
#define sd(x) scanf("%lf", &(x)); getchar()
#define sline(x) scanf("%[^\n]", x); getchar()
class Mat
{
    public:
        int m, n;
        double *data;
 
        Mat(int m, int n);
        Mat(const Mat &matrix);
 
        const Mat &operator=( const Mat &A );
        const Mat operator*( const Mat &A );
        const Mat operator^( int P );
		static Mat unity(int m, int n)
		{
			Mat uni(m, n);
			for(int i = 0; i < m; i++)
				for(int j = 0; j < n; j++)
					uni.data[i * n + j] = ((i==j)?1.0:0.0);
			return uni;
		}
		void disp()
		{
			printf("Mat:\n");
			for(int i = 0; i < m; i++)
			{
				for(int j = 0; j < n; j++)
					printf("%0.2lf ", data[i * n + j]);
				printf("\n");
			}
		}
        ~Mat();
};

Mat::Mat(int m, int n)
{
    this->m = m;
    this->n = n;
    data = new double[m * n];
}

Mat::Mat(const Mat &A)
{
    this->m = A.m;
    this->n = A.n;
    data = new double[m * n];
    for(int i = 0; i < m * n; i++)
        data[i] = A.data[i];
}

Mat::~Mat()
{
    delete[] data;
}

const Mat &Mat::operator=(const Mat &A)
{
    if(&A != this)
    {
        delete[] data;
        m = A.m;
        n = A.n;
        data = new double[m*n];
        for(int i = 0; i < m * n; i++)
            data[i] = A.data[i];
    }
    return *this;
}

const Mat Mat::operator*(const Mat &A)
{
    Mat C(m, A.n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < A.n; j++)
        {
            C.data[i * C.n + j] = 0;
            for(int k = 0; k < n; ++k)
                C.data[i * C.n + j] += data[i * n + k] * A.data[k * A.n + j];
        }
    return C;
}

Mat pow(Mat a, long long b)
{
	if(b == 0)
		return Mat::unity(a.m, a.n);
	Mat prod(a.m, a.n);
	prod = Mat::unity(a.m, a.n);
	Mat s = a;
	while(b)
	{
		if(b & 1)
			prod = prod * s;
		b>>=1;
		s = s * s;
	}
	return prod;
}

Mat m(26, 26);
int T, N, K;
char S[4], s[100000][4];
double term, ans;
int h[18000];
void hashc()
{
	memset(h, 0, sizeof(h));
}
bool hash(char s[], int len)
{
	int k = 0;
	for(int i = 0; i < len; i++)
		k = k * 26 + s[i] - 'a';
	h[k]++;
	return h[k] == 1;
}
int main()
{
	si(T);
	while(T--)
	{
		si(N);
		si(K);
		ss(S);
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
				sd(m.data[i * 26 + j]);
		for(int i = 0; i < N; i++)
			ss(s[i]);
		m = pow(m, K);
		ans = 0.0;
		//m.disp();
		hashc();
		for(int i = 0; i < N; i++)
			if(strlen(S) == strlen(s[i]) && hash(s[i], strlen(S)))
			{
				term = 1.0;
				for(int k = 0; s[i][k]; k++)
					term *= m.data[(S[k] - 'a') * 26 + (s[i][k] - 'a')];
				ans += term;
			}
		printf("%lf\n", ans);
	}
	return 0;
}