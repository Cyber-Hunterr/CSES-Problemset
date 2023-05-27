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

bool reserved[8][8];
bool board[8][8] = {0};

void precompute(){
    
}
bool isSafe(int x, int y){
    if(x>=0 && x<8 && y>=0 && y<8){
        if(reserved[x][y]) return false;
        for (int i = 1; i <= y; i++)
        {
            bool ul = false,dl = false,l = false;
            if(x-i >=0) ul = board[x-i][y-i];
            if(x+i < 8) dl = board[x+i][y-i];
            l = board[x][y-i];

            if(l||dl||ul) return false;
        }
        return true;
    }
    else{
        return false;
    }
}
void rec(int col,int &ans){
    if(col == 8){
        ans++;
    }
    for (int i = 0; i < 8; i++)
    {
        if(isSafe(i,col)){
            board[i][col] = 1;
            rec(col+1,ans);
            board[i][col] = 0;
        }
    }
    
}
void solve(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char ch;
            cin>>ch;
            if(ch == '.') reserved[i][j] = 0;
            else reserved[i][j] = 1;
        }
    }
    int ans = 0;
    rec(0,ans);
    cout<<ans<<endl;
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