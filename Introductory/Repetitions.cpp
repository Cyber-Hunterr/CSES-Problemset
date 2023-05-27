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
    string s;
    cin>>s;
    ll n = s.size();
    ll a=0,t=0,c=0,g=0;
    ll maxa=0,maxt=0,maxc=0,maxg=0;
    for (ll i = 0; i < n; i++)
    {
        if(s[i] == 'A'){
            a++;
            t=0;
            c=0;
            g=0;
        }
        if(s[i] == 'T'){
            t++;
            a=0;
            c=0;
            g=0;
        }
        if(s[i] == 'C'){
            c++;
            t=0;
            a=0;
            g=0;
        }
        if(s[i] == 'G'){
            g++;
            t=0;
            c=0;
            a=0;
        }
        maxa = max(a,maxa);
        maxt = max(t,maxt);
        maxc = max(c,maxc);
        maxg = max(g,maxg);
        // cout<<maxa<<" "<<maxt<<" "<<maxc<<" "<<maxg<<" "<<endl;
    }
    cout<<max(maxa,max(maxt,max(maxc,maxg)))<<endl;
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