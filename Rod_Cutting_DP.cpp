#include<bits/stdc++.h>
using namespace std;
int r[1000];
int s[1000];

int max(int a,int b,int i,int j)
{
    if(a<b)
    {
        s[j]=i;
        return b;
    }
    else return a;
}
int bottom_up(int c[],int p)
{
    r[0]=0;
    int q;
    for(int j=1; j<=p; j++)
    {
        q=-9999999;
        for(int i=1; i<=j; i++)
        {
            q=max(q,c[i]+r[j-i],i,j);
            //s[j]=i;
        }
        r[j]=q;
    }
    return r[p];
}

int main()
{
    int a[1000];
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    int p=bottom_up(a,n);
    cout<<"Max profit is:"<<p<<endl;
    cout<<"Cutting Position:";

    while(n>0)
    {
        cout<<s[n]<<" ";
        n=n-s[n];
    }
    return 0;
}
