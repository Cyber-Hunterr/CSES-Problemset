#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define PI 3.141592653589793238462
#ifndef ONLINE_JUDGE
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

const ll mod = 1e11 + 7;
const int N = 1e6 + 1;

void precompute(){
    
}
ll binpow(ll a, ll b, ll p = mod){
    ll res = 1;
    while (b > 0){
    if(b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b = b >> 1;
    }
    return res;
}
void solve(){
    ll n;
    cin>>n;
    ll exp = 1;
    ll end = 9;
    while(n>end){
        n-=end;
        exp++;
        end = 9*binpow(10,exp-1)*exp;
    }
    n--;
    ll num = n/exp;
    ll digit = n%exp;
    ll ans = binpow(10,exp-1)+num;

    string s = to_string(ans);
    cout<<s[digit]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    ll testcases=1;
    cin>>testcases;
    precompute();
    while (testcases--)
    {
        solve();
    }
    return 0;
}