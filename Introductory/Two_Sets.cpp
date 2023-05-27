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

const ll mod = 1e9+7;
const int N = 100001;

void precompute(){
    
}
void solve(){
    int n;
    cin>>n;
    ll sum = 1LL*n*(n+1);
    if(sum%4 != 0){
        cout<<"NO\n";
        return;
    }
    else{
        cout<<"YES\n";
        vi a,b;
        if(n&1){
            for(int i = 1;i<=(n/2);i++){
                if(i%2 == 0){
                    b.push_back(i);
                    b.push_back(n-i);
                }
                else{
                    a.push_back(i);
                    a.push_back(n-i);
                }
            }
            b.push_back(n);
        }
        else{
            for (int i = 1; i <= n/2; i++)
            {
                if(i%2 == 0){
                    a.push_back(i);
                    a.push_back(n+1-i);
                }
                else{
                    b.push_back(i);
                    b.push_back(n+1-i);
                }
            }
        }
        cout<<a.size()<<endl;
        for (auto &i : a)
        {
            cout<<i<<" ";
        }cout<<"\n";
        cout<<b.size()<<endl;
        for (auto &i : b)
        {
            cout<<i<<" ";
        }cout<<"\n"; 
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