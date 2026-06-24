#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll reverse_pairs(vi v)
{   
    int size=v.size();

    if (size==1) return 0;

    vi v1(size/2),v2(size-size/2);

    for (int i=0;i<size;i++)
    {
        if (i<size/2)
        {
            v1[i]=v[i];
        }
        else
        {
            v2[i-size/2]=v[i];
        }
    }

    ll count=reverse_pairs(v1)+reverse_pairs(v2);

    sort(v1.begin(),v1.end());    
    reverse(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());

    int ptr2=0;

    for(int ptr1=0;ptr1<size/2;ptr1++)
    {
        while (v1[ptr1]<=v2[ptr2]*2) 
        {
            
            if (ptr2>=size-size/2) break;
            
            ptr2++;
        }
        
        count+=size-size/2-ptr2;
    }

    return count;
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;

    cin>>n;

    vi v(n);

    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<(ll)reverse_pairs(v)<<endl;

}