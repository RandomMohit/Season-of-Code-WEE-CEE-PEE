#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    getline(cin,s);

    int n=s.length();

    vector<int> a(n,0);

    int count=0;

    REP(i,0,n-1)
    {
        if (s[i]==s[i+1]) count++;

        a[i+1]=count;
    }

    int m;

    cin>>m;

    REP(i,0,m)
    {
        int l,r;

        cin>>l>>r;

        cout<<a[r-1]-a[l-1]<<"\n";
    }
    
}
