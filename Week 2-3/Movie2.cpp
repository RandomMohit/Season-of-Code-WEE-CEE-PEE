#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

void solve() {
    int n,k;
    cin >> n >> k;

    vector<pll> movies(n);
    for (auto &x : movies) cin >> x.first >> x.second;

    sort(all(movies),[](pll &a, pll &b){
        if(a.second==b.second) return a.first<b.first;
        else return a.second<b.second;
    });

    multiset<ll> persons;
    int size=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {  
        auto iter = persons.upper_bound(movies[i].first);
        if(iter!=persons.begin())
        {
            iter--;
            persons.erase(iter);
            persons.insert(movies[i].second);
            ans++;
        }
        else
        {
            if(size<k)
            {
                size++;
                persons.insert(movies[i].second);
                ans++;
            }
        }
    }
    cout<<ans<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}