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
    int n;

    cin>>n;

    long long int x,p[n];
    
    cin>>x;

    for (int i=0;i<n;i++)
    {
        cin>>p[i];
    }

    merge_sort(p,n);

    int a=0,b=n-1,count=0;

    while(a<b)
    {
        if (p[a]+p[b]<=x)
        {
            a++;
            b--;
            count++;
        }
        else
        {
            b--;
            count++;
        }
    }

    if (a==b)
    {
        count++;
    }

    cout<<count<<endl;


}