#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<ll> vi;

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;

    cin>>n>>q;
    
    vi a(n),b(n+1,0);

    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for (int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;

        b[l-1]++;
        b[r]--;
    }

    for (int i=1;i<n;i++)
    {
        b[i]+=b[i-1];
    }

    b.pop_back();

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll sum=0;

    for (int i=0;i<n;i++)
    {
        sum+=a[i]*b[i];
    }

    cout<<sum<<"\n";
}