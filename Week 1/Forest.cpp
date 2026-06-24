#include <iostream>
using namespace std;

int main()
{
    int n,q;

    cin>>n>>q;

    int a[n+1][n+1];

    char c;

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            a[i][j]=0;
        }
    }

    for (int i=1;i<n+1;i++)
    {
        for (int j=1;j<n+1;j++)
        {
            cin>>c;

            if (c=='.') a[i][j]=0;
            else a[i][j]=1;
        }
    }

    for (int i=1;i<n+1;i++)
    {
        for (int j=2;j<n+1;j++)
        {
            a[i][j]+=a[i][j-1];
        }
    }

    for (int j=1;j<n+1;j++)
    {   

        for (int i=2;i<n+1;i++)
        {
            a[i][j]+=a[i-1][j];
        }
    }

    for (int i=0;i<q;i++)
    {
        int x1,x2,y1,y2;
        cin>>y1>>x1>>y2>>x2;

        cout<<a[y2][x2]-a[y1-1][x2]-a[y2][x1-1]+a[y1-1][x1-1]<<"\n";
    }
}