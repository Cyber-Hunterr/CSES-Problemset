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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

/**************************** --- Add Global Variables & Functions --- ****************************/
string s;
int len = 48;
bool vis[9][9] = {0};
int p[48];
/**************************** ---------------------------------------- ****************************/

void precompute(){
    
}
ll traverse(int i,int r,int c){
    if(vis[r][c+1] && vis[r][c-1] && (!vis[r+1][c] && !vis[r-1][c])) return 0;
    if((!vis[r][c+1] && !vis[r][c-1]) && vis[r+1][c] && vis[r-1][c]) return 0;
    
    if(r == 7 && c == 1){
        return i==len?1:0;
    }
    if(i==len) return 0;
    
    ll ans = 0;
    vis[r][c] = 1;
    
    if(p[i]<4){
        int m = p[i];
        int x = r + dx[m];
        int y = c + dy[m];
        if(!vis[x][y]) ans+=traverse(i+1,x,y);
    }
    else{
        for(int m = 0;m < 4;m++){
            int x = r + dx[m];
            int y = c + dy[m];
            if(!vis[x][y]) ans+=traverse(i+1,x,y);
        }
    }
    
    vis[r][c] = 0;
    return ans;
}
void solve(){
    ll n,m,k,q;
    string yes = "YES\n",no = "NO\n";
    cin>>s;
    for(int i = 0;i < len;i++){
        if(s[i] == 'U') p[i] = 0;
        else if(s[i] == 'R') p[i] = 1;
        else if(s[i] == 'D') p[i] = 2;
        else if(s[i] == 'L') p[i] = 3;
        else p[i] = 4;
    }
    for(int i = 0;i < 9;i++){
        vis[i][0] = 1;
        vis[i][8] = 1;
        vis[0][i] = 1;
        vis[8][i] = 1;
    }
    ll ans = traverse(0,1,1);
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