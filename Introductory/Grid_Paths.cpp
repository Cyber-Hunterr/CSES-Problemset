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
string s;
int cnt = 0;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool vis[7][7] = {0};

void precompute(){
    
}
bool isSafe(int x, int y){
    if(x>=0 && x<7 && y>=0 && y<7 && vis[x][y] == 0){
        return true;
    }
    return false;
}
void rec(int x, int y, int tx, int ty, int len){
    if(x == tx && y == ty){
        cnt++;
        return;
    }
    if(len>=s.length()) return;
    dbg(x)
    dbg(y)
    vis[x][y] = 1;
    
    int newx,newy;
    if(s[len] == 'U'){
        newx = x+dx[0];
        newy = x+dy[0];
        if(isSafe(newx,newy))
            rec(newx,newy,tx,ty,len+1);
    }
    else if(s[len] == 'R'){
        newx = x+dx[1];
        newy = x+dy[1];
        if(isSafe(newx,newy))
            rec(newx,newy,tx,ty,len+1);
    }
    else if(s[len] == 'D'){
        newx = x+dx[2];
        newy = x+dy[2];
        if(isSafe(newx,newy))
            rec(newx,newy,tx,ty,len+1);
    }
    else if(s[len] == 'L'){
        newx = x+dx[3];
        newy = x+dy[3];
        if(isSafe(newx,newy))
            rec(newx,newy,tx,ty,len+1);
    }
    else{
        for (int i = 0; i < 4; i++){
            newx = x+dx[i];
            newy = x+dy[i];
            if(isSafe(newx,newy))
                rec(newx,newy,tx,ty,len+1);
        }
    }
    vis[x][y] = 0;
}
void solve(){
    cin>>s;
    int len = 0;
    // string path = "";
    rec(0,0,6,0,len);
    cout<<cnt<<endl;
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
    //cin>>testcases;
    precompute();
    while (testcases--)
    {
        solve();
    }
    return 0;
}