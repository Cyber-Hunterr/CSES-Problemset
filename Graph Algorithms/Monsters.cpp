#include <bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*  
    *s.find_by_order(k)     // kth element;
    s.order_of_key(k)       // number of elements less than k (first elements in case of map)
*/
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sortall(x) sort(all(x))
#define sz(x) (int)(x.size())
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
const ld eps = 1e-9;
const ll inf = 1e18;
const int MAXN = 1e6 + 1;

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
char mov[] = {'R','D','L','U'};

/**************************** --- Add Global Variables & Functions --- ****************************/
string yes = "YES\n",no = "NO\n";
int n,m;
string ans,path;
/**************************** ---------------------------------------- ****************************/

void precompute(){
    
}
bool dfs(int x,int y,int d, vector<vector<char>> &grid, vvi &trap){
    // cout<<x<<" "<<y<<endl;
    if(x == 0 || x== n-1 || y == 0 || y==m-1){
        ans = path;
        return true;
    }
    trap[x][y] = d;
    for(int i = 0;i < 4;i++){
        int X = x+dx[i];
        int Y = y+dy[i];
        
        if(X<0 || X>=n || Y<0 || Y>=m || grid[X][Y] == '#') continue;
        if(trap[X][Y]>d){
            path.push_back(mov[i]);
            if(dfs(X,Y,d+1,grid,trap)) return true;
            path.pop_back();
        }
    }
    return false;
}
void solve(){
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    pii s;
    queue<pair<pii,int>> q;
    vvi trap(n,vi(m,1e9));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                s = {i,j};
            }
            else if(grid[i][j] == 'M'){
                q.push({{i,j},0});
                trap[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        auto [pp,d] = q.front();
        q.pop();
        auto [x,y] = pp;
        
        for(int i = 0;i < 4;i++){
            int X = x+dx[i];
            int Y = y+dy[i];
            
            if(X<0 || X>=n || Y<0 || Y>=m || grid[X][Y] == '#') continue;
            if(trap[X][Y]>d+1){
                trap[X][Y] = d+1;
                q.push({{X,Y},d+1});
            }
        }
    }
    if(dfs(s.ff,s.ss,1,grid,trap)){
        cout<<yes<<ans.length()<<endl<<ans<<endl;
    }
    else cout<<no;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef JAI_SHREE_KRISHNA
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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