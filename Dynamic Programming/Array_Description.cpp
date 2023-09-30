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
/**************************** ---------------------------------------- ****************************/

void precompute(){
    
}
int dp[100001][101];
int solve(vi &v, int i , int element){
    if(v[i]!=0 && v[i]!=element){
        return 0;
    }
    if(i==0) return 1;
    return solve(v,i-1,element-1)+solve(v,i-1,element)+solve(v,i-1,element+1);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vi v(n);
    cin>>v;
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i = 1;i <= m;i++){
        ans+=solve(v,n-1,i);
    }
    cout<<ans<<endl;
}
/*void solve(){
    int n,m;
    cin>>n>>m;
    vi v(n+1);
    for(int i = 1;i <=n;i++){
        cin>>v[i];
    }
    
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j <= m;j++){
            if(v[i] == 0 || v[i] == j){
                if(i==1) dp[i][j] = 1;
                else dp[i][j] = ((dp[i-1][j-1]+dp[i-1][j])%mod+dp[i-1][j+1])%mod;
            }
            else dp[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i = 1;i<=m;i++){
        ans+=dp[n][i];
        ans%=mod;
    }
    cout<<ans<<endl;
}*/

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