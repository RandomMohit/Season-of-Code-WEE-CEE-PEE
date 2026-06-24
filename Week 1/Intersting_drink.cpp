#include <iostream>
using namespace std;

void merge_sort(long long int* a,int l)
{   
    if (l==1)
    {
        return;
    }

    long long int b[l/2],c[l-l/2];

    for (int i=0;i<l;i++)
    {
        if (i<l/2)
        {
            b[i]=a[i];
        }
        else
        {
            c[i-l/2]=a[i];
        }
    }

    merge_sort(b,l/2);
    merge_sort(c,l-l/2);

    int i=0,j=0,m=0;
    while(i<l/2 and j<l-l/2)
    {
        if (b[i]>c[j])
        {
            a[m]=c[j];
            j++;
            m++;
        }
        else
        {
            a[m]=b[i];
            i++;
            m++;
        }
    }

    while(i<l/2)
    {
        a[m]=b[i];
        i++;
        m++;
    }

    while(j<l-l/2)
    {
        a[m]=c[j];
        j++;
        m++;
    }  
}

int bin_search(long long int* a,int l,long long int target)
{
    int low=0,high=l-1,ans=-1;

    while(low<=high)
    {   
        int mid=(low+high)/2;
        if (a[mid]<=target)
        {
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    long long int x[n];

    for (int i=0;i<n;i++)
    {
        cin>>x[i];
    }

    merge_sort(x,n);

    int q;
    cin>>q;

    long long int m;

    for (int i=0;i<q;i++)
    {
        cin>>m;
        int ans=bin_search(x,n,m);
        cout<<ans+1<<endl;
    }
}

