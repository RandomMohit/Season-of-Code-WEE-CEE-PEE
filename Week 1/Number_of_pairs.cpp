#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;



int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        ll l,r;

        cin>>n>>l>>r;

        vi a(n);
        
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        sort(a.begin(),a.end());

        ll start=0,end=n-1,count1=0,count2=0;
        
        while(start<=end)
        {
            if (a[start]+a[end]>l-1) end--;
            else
            {
                
                count1+=end-start;
                start++;
            }
        }

        start=0,end=n-1;

        while(start<=end)
        {
            if (a[start]+a[end]>r) end--;
            else
            {                   
                count2+=end-start;
                start++;
            }
        }

        cout<<count2-count1<<"\n";
    }
}