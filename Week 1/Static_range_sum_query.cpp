#include <iostream>
using namespace std;
 
int main()
{
    int n,q;
    cin>>n>>q;
 
    long long int a[n],sum[n];
 
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
 
    sum[0]=a[0];
 
    for (int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
 
    for (int i=0;i<q;i++)
    {
        int l,u;
        cin>>l>>u;
        
        long long int answer=sum[u-1]-sum[l-1]+a[l-1];
        cout<<answer<<"\n";
 
        
    }
