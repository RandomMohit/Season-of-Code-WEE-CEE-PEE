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
void multiply(vector<vll> &a,vector<vll> &b)
{
    int length=a.size();

    vector<vll> temp(length,vll(length,0));

    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            for(int k=0;k<length;k++)
            {
                temp[i][j]=(temp[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }

    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            a[i][j]=temp[i][j];
        }
    }
}
void power(vector<vll> &graph,ll exp)
{      
    int length=graph.size();
    vector<vll> temp(length,vll(length,0));
    
    for(int i=0;i<length;i++)
    {
        temp[i][i]=1;
    }
    
    while(exp>0)
    {
        if(exp%2==1)
        {
            multiply(temp,graph);
        }
        multiply(graph,graph);
        exp/=2;
    }
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            graph[i][j]=temp[i][j];
        }
    }
}
void solve() {
    int n;
    ll K;
    cin >> n >> K;

    vector<vll> graph(n,vll(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }   
    }
    
    power(graph,K);
    
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans+=graph[i][j];
            ans%=MOD;
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