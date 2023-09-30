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

/**************************** --- Add Global Variables & Functions --- ****************************/
string yes = "YES\n",no = "NO\n";
/**************************** ---------------------------------------- ****************************/
template<class T, class U>
struct Lsegtree{
    ll n; vector<T>st; vector<U>lazy; T identity_element; U identity_update;

    /*
        Definition of identity_element: the element I such that combine(x,I) = x
        for all x
        Definition of identity_update: the element I such that apply(x,I) = x
        for all x        
    */

    Lsegtree(ll n, T identity_element, U identity_update){ this->n = n; this->identity_element = identity_element; this->identity_update = identity_update; st.assign(4*n,identity_element); lazy.assign(4*n, identity_update);}
    
    
    // change the following 2 functions, and you're more or less done.
    T combine(T l, T r){
        // change this function as required.
        T ans = l+r;
        return ans;
    }

    T apply(T curr, U upd, ll tl, ll tr){
        // T ans = curr+upd;
        // increment range by upd:
        T ans = curr + (tr - tl + 1)*upd;

        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr){
        U ans = old_upd;
        ans+=new_upd;
        return ans;
    }  

    void buildUtil(ll v, ll tl, ll tr, vector<T>&a){
        if(tl == tr){
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    void push_down(ll v, ll tl, ll tr){
        //for the below line to work, make sure the "==" operator is defined for U.
        if(lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if(2*v + 1 <= 4*n){
            ll tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r){
        push_down(v,tl,tr);
        if(l > r)return identity_element;
        if(tr < l or tl > r){
            return identity_element;
        }
        if(l <= tl and r >= tr){
            return st[v];
        }
        ll tm = (tl + tr)>>1;
        return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
    }
    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd){
        push_down(v,tl,tr); 
        if(tr < l or tl > r) return;
        if(tl >=l and tr <=r){
            lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
            push_down(v,tl,tr);
        }
        else{
            ll tm = (tl + tr)>>1;
            updateUtil(2*v+1,tl,tm,l,r,upd);
            updateUtil(2*v+2,tm+1,tr,l,r,upd);
            st[v] = combine(st[2*v + 1], st[2*v+2]);
        }
    }

    void build(vector<T>a){
        assert( (ll)a.size() == n);
        buildUtil(0,0,n-1,a);
    }
    T query(ll l, ll r){
        return queryUtil(0,0,n-1,l,r);
    }
    void update(ll l,ll r, U upd){
        updateUtil(0,0,n-1,l,r,upd);
    }
};
void precompute(){
    
}
void solve(){
    int n,q;
    cin>>n>>q;
    vl v(n),pre(n);
    cin>>v;
    Lsegtree s(n,0LL,0LL);
    s.build(pre);
    while(q--){
        int type;
        cin>>type;  
        if(type == 1){
            int a,b,u;
            cin>>a>>b>>u;
            a--;b--;
            s.update(a,b,u);
        }
        else{
            int p;
            cin>>p;
            cout<< v[p-1] + s.query(p-1,p-1)<<endl;
        }
    }
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