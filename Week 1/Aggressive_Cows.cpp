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

bool valid(long long int* a,int l,long long int x,int c)
{
    int count=1;
    int pos=0;

    for (int i=1;i<l;i++)
    {
        if ((a[i]-a[pos])>=x)
        {
            pos=i;
            count++;
        }
    }

    if (count>=c) return true;
    
    return false;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,c;
        cin>>n>>c;

        long long int a[n];

        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        merge_sort(a,n);

        long long int low=0,high=a[n-1]-a[0],ans=0;

        while(low<=high)
        {
            long long int mid=low+(high-low)/2;

            if (valid(a,n,mid,c))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;

        }

        cout<<ans<<endl;

    }
}