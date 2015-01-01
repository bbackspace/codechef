#include <bits/stdc++.h>
using namespace std;
 
#define All(a) a.begin(), a.end()
#define For(i,a,b) for (int i = (a); i < (b); ++i)
#define Fore(i,c) for (int i = 0; i < int((c).size()); ++i)
#define Mem(a,v) memset((a), (v), sizeof(a))
#define Sz(a) int(a.size())
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
 
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const int INF = (1 << 30);
const int MOD = 1000000007;
const int MAXN = 1005;
const int MAXT = 10005;
 
int dp[MAXN*MAXT];
char bt[MAXN][MAXT];
vector<PII> a;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,T;
    cin >> N >> T;
    a.resize(N);
    For(i,0,N) cin >> a[i].ft;
    For(i,0,N) cin >> a[i].sd;
    sort(All(a));
    For(i,0,N) {
        for (int j = T; j >= a[i].sd; --j) {
            if (dp[j-a[i].sd] + a[i].ft > dp[j]) {
                dp[j] = dp[j-a[i].sd] + a[i].ft;
                bt[i][j] = 1;
            }
        }
    }
    int x = 0;
    int j = T;
    VI res;
    for (int i = N-1; i >= 0; --i) {
        if (bt[i][j]) {
            res.pb(i);
            j -= a[i].sd;
        }
    }
    Fore(i,res) {
        //cout << res[i] << " ";
        x = max(x,a[res[i]].ft);
    }
    cout << dp[T] + x << "\n";
    return 0;
} 