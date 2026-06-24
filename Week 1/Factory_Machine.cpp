#include <iostream>
using namespace std;

long long int min_arr(long long int* a,int l)
{
    long long int min=a[0];

    for(int i=1;i<l;i++)
    {
        if (a[i]<min) min=a[i];
    }
    return min;
}

long long int weight(long long int* k, long long int a,int l)
{   
    long long int ans=0;

    for (int i=0;i<l;i++)
    {
        ans+=a/k[i];
    }
    
    return ans;
}

int main()
{
    int n;
    cin>>n;

    long long int t,k[n];
    cin>>t;

    for (int i=0;i<n;i++)
    {
        cin>>k[i];
    }

    long long int high=t*min_arr(k,n),low=0;

    while(low<high)
    {
        long long int mid=low+(high-low)/2;

        if (weight(k,mid,n)>=t) high=mid;
        else low=mid+1;    
    }

    cout<<low<<endl;
}