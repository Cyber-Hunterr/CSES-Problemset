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

const ll mod = 1e9 + 7;
const int N = 1e6 + 1;

void precompute(){
    
}
void solve(){
    int n;
    cin>>n;
    int a = 1<<n;
    for (int i = 0; i < a; i++)
    {
        int num = i;
        string s(n,'0');
        int temp = 0;
        for (int bit = 0; bit < 18; bit++)
        {
            int r = (num>>bit)&1;
            int l = (num>>(bit+1))&1;
            int t = r^l;
            temp|=t<<bit;
            // cout<<"Bit :"<<bit<<" t :"<<t<<endl;
            if(bit<n) s[bit] = '0'+t;
            // cout<<"s[bit] :"<<s[bit]<<endl;
        }
        reverse(all(s));
        cout<<s<<endl;

    }
    
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
    // cin>>testcases;
    precompute();
    while (testcases--)
    {
        solve();
    }
    return 0;
}