#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

/**************************** --- Add Global Variables & Functions --- ****************************/
string yes = "YES\n",no = "NO\n";
int n,k;
multiset<int> low,up;
ll slow,sup;
/**************************** ---------------------------------------- ****************************/

void precompute(){
    
}
void ins(int val){
    int a = *low.rbegin();
    if(a<val){
        up.insert(val);
        sup+=val;
        if(up.size()>k/2){
            int rem = *up.begin();
            low.insert(rem);;
            slow+=rem;
            up.erase(up.find(rem));
            sup-=rem;
        }
    }
    else{
        low.insert(val);
        slow+=val;
        if(low.size()>(k+1)/2){
            int rem  = *low.rbegin();
            up.insert(rem);
            sup+=rem;
            low.erase(low.find(rem));
            slow-=rem;
        }
    }
}
void del(int val){
    if(up.find(val) != up.end()) up.erase(up.find(val)) , sup-=val;
    else low.erase(low.find(val)),slow-=val;
    
    if(low.empty()){
        int rem = *up.begin();
        low.insert(rem);
        slow+=rem;
        up.erase(up.find(rem));
        sup-=rem;
    }
}
ll med(){
    if(k%2 == 0) return 0;
    return *low.rbegin();
}
void solve(){
    cin>>n>>k;
    // v.resize(n);
    vector<int> v(n);
    cin>>v;
    if(k == 1){
        for(int i = 0;i < n;i++){
            cout<<0<<" ";
        }
        cout<<endl;
        return;
    }
    slow = sup = 0;
    low.insert(v[0]);
    slow+=v[0];
    for(int i = 1;i < k;i++){
        ins(v[i]);
    }
    cout<<sup-slow + med()<<" ";
    for(int i = k;i < n;i++){
        del(v[i-k]);
        ins(v[i]);
        cout<<sup-slow + med()<<" ";
    }
    cout<<endl;
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