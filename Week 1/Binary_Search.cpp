#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin>>t;

    while(t--)
    {
        int n,x,index=0;

        cin>>n>>x;

        vi p(n);

        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            if (p[i]==x)
            {
                index=i;
            }
        }

        int l=0,r=n;

        while(l+1<r)
        {
            int m=(l+r)/2;
            if(p[m]<=x) l=m;
            else r=m;
        }

        cout<<1<<"\n"<<index+1<<" "<<l+1<<"\n";

        
    }
}