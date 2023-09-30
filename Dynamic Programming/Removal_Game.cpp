#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define PI 3.141592653589793238462
#ifdef JAI_SHREE_KRISHNA
#define dbg(x) cerr << #x << " : "; _print_(x);cerr << "\n";
#else
#define dbg(x)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vii;
typedef vector<pll> vll;

void _print_(ll t) {cerr << t;}
void _print_(int t) {cerr << t;}
void _print_(string t) {cerr << t;}
void _print_(char t) {cerr << t;}
void _print_(ld t) {cerr << t;}
void _print_(double t) {cerr << t;}
template <class T, class V> void _print_(pair <T, V> p) {cerr << "{"; _print_(p.ff); cerr << ","; _print_(p.ss); cerr << "}";}
template <class T> void _print_(vector <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(set <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(multiset <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print_(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print_(i); cerr << " ";} cerr << "]";}


// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

const ll mod = 1000000007;
const ll eps = 1e-9;
const ll inf = 1e18;
const int MAXN = 1e6 + 1;

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

/**************************** --- Add Global Variables & Functions --- ****************************/
string yes = "YES\n",no = "NO\n";
ll dp[5001][5001];
/**************************** ---------------------------------------- ****************************/

void precompute(){
    
}
int solve(int s,int e,vi &v){
    if(s>e) return 0;
    if(s==e) return v[s];
    
    int op1 = v[s] - solve(s+1,e,v);
    int op2 = v[e] - solve(s,e-1,v);
    
    return max(op1,op2);
}
void solve(){
    int n;
    cin>>n;
    vi v(n);
    ll sum = 0;
    for(int i = 0;i < n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    
    // dp[i][j] = what is maxm score difference possible if we consider only this segment of array
    // op1 = v[i] - dp[i+1][j]
    // op2 = v[j] - dp[i][j-1]
    // dp[i][j] = max(op1,op2)
    
    for(int s = n-1;s>=0;s--){
        for(int e = 0;e < n;e++){
            if(s>e) continue;
            if(s==e){
                dp[s][e] = v[s];
                continue;
            }
            dp[s][e] = max(v[s]-dp[s+1][e],v[e]-dp[s][e-1]);
        }
    }
    //score of 1st player - score of 2nd player (A-B = diff)
    ll diff = dp[0][n-1];
    //total score of both player is sum (A+B = sum)
    
    ll ans = (sum+diff)/2;
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef JAI_SHREE_KRISHNA
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    #ifdef ERROR
    freopen("error.txt","w",stderr);
    #endif
    ll testcases=1;
    //cin>>testcases;
    precompute();
    while (testcases--)
    {
        solve();
    }
    return 0;
}