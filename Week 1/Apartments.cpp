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

int main()
{
    int n,m;
    long long int k;

    cin>>n>>m>>k;

    long long int a[n],b[m];

    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for (int i=0;i<m;i++)
    {
        cin>>b[i];
    }

    merge_sort(a,n);
    merge_sort(b,m);

    int i=0,j=0,count=0;

    while(i<n and j<m)
    {
        if ((a[i]-b[j]<=k) and (b[j]-a[i])<=k)
        {
            i++;
            j++;
            count++;
        }
        else 
        {
            if (a[i]>b[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }

    cout<<count<<endl;


}