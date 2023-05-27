#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define popb pop_back

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

void solve(){
    ull n;
    cin>>n;
    cout<<n<<" ";
    while (n != 1)
    {
        if(n%2 == 0) n/=2;
        else n = n*3 + 1;
        cout<<n<<" ";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int testcases=1;
    //cin>>testcases;
    while (testcases--)
    {
        solve();
    }
    return 0;
}