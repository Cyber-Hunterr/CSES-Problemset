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
    ll n,f;
    cin>>n;
    if (n==1)
    {
        cout<<1<<endl;
    }
    else if (n<=3)
    {
        cout<<"NO SOLUTION"<<endl;
    }
    else if (n==4)
    {
        cout<<2<<" "<<4<<" "<<1<<" "<<3<<endl;
    }
    else
    {
        if(n%2==0) f=n/2;
        else f = n/2+1;
        for (ll i = n/2; i > 0; i--)
        {
            cout<<2*i<<" ";
        }
        for (ll i = f; i > 0; i--)
        {
            cout<<2*i-1<<" ";
        }
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