#include <iostream>
using namespace std;

int main()
{
    int n;
    long long int t;

    cin>>n>>t;

    int a[n];

    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int end=0,ans=0,sum=0;

    for (int start=0;start<n;start++)
    {
        while(end<n and sum+a[end]<=t)
        {
            sum+=a[end];
            end++;
        }
        ans=max(ans,end-start);
        sum-=a[start];
    }
    
    
    cout<<ans<<endl;

}