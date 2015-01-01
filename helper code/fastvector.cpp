#include<cstdio>
#include<cstdlib>

template <class T>
class FastVector
{
private:
	T *vec;
	size_t *from;
	size_t *to;
	size_t top;
	T init_val;
	size_t len;
public:
	T& at(size_t i)
	{
		if (from[i] < top && to[from[i]] == i)
			return vec[i];
		else
		{
			from[i] = top;
			to[top] = i;
			top++;
			vec[i] = init_val;
			return vec[i];
		}
	}
	
	FastVector(size_t len_, T init_val_)
	{
		vec = new T[len_];
		from = new size_t[len_];
		to = new size_t[len_];
		setAll(init_val_);
		len = len_;
	}

	void setAll(T init_val_)
	{
		top = 0;
		init_val = init_val_;
	}

	~FastVector()
	{
		delete[] vec;
		delete[] from;
		delete[] to;
	}
};

int main()
{
	FastVector<double> v(100000000,0);
	v.setAll(0.0);
	v.at(0) = 0.0;
	v.at(1) = 1.0;
	for(int i = 2; i < 100000000; ++i)
	{
		v.at(i) = v.at(i - 2) + v.at(i - 1);
		if(i % 1000000 == 0)
			printf("%d: %0.0lf\n", i, v.at(i));
	}
	return 0;
}