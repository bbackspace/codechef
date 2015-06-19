typedef long long ll;

inline ll fastmod(ll a, ll m) {	if(a < m) return a;	return a % m; }
inline ll powmod(ll a, ll b, ll m)
{
	if(b == 0) return 1 % m;
	ll prod = 1, s = a;
	while(b)
	{
		if(b & 1)
			prod = fastmod(prod * s, m);
		b>>=1;
		s = fastmod(s * s, m);
	}
	return prod;
}
