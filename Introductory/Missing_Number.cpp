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
    ll n,a;
    cin>>n;
    ll arr[n];
    // vl v;
    for (ll i = 1; i < n; i++)
    {
        cin>>a;
        arr[a]=a;
    }
    for (ll i = 1; i <= n; i++)
    {
        if(arr[i] != i) cout<<i<<endl;
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