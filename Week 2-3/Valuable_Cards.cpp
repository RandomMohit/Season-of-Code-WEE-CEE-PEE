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
    ll n, x;
    cin >> n >> x;

    vll divisors(x+1,0);
    set<ll> divisors_set;

    for(ll i=1;i*i<=x;i++)
    {   
        if(x%i==0)
        {
            divisors[i]=1;
            divisors[x/i]=1;
            divisors_set.insert(i);
            divisors_set.insert(x/i);
        }
    }
    int ans=1;
    vll a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    unordered_map<ll,ll> used_divisors;
    
    used_divisors[1]=1;
    for(int i=0;i<n;i++)
    {   
        if(x%a[i]==0)
        {
            if(used_divisors[x/a[i]]==1)
            {   
                ans++;
                used_divisors.clear();
                used_divisors[1]=1;
                used_divisors[a[i]]=1;
            }
            else
            {   
                vll keys;
                for(auto &div :used_divisors) if(div.second==1) keys.pb(div.first);
                for(auto &div :keys)
                {
                    if(div*a[i]<=x and divisors[div*a[i]]==1)
                    {
                        used_divisors[div*a[i]]=1;
                    }
                }
            }
        }

    }



    cout<<ans<<endl;
}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}