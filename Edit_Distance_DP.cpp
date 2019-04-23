#include<bits/stdc++.h>
using namespace std;

int temp[1000][1000];
int min(int a,int b,int c)
{
    return min(min(a,b),c);
}

int dynamicedit(string str1,string str2,int len1,int len2)
{
    int temp[len1+1][len2+1];

    for(int i=0;i<str1.length();i++)
    {
        temp[0][i]=i;
    }
    for(int i=0;i<str2.length();i++)
    {
        temp[i][0]=i;
    }

    for(int i=1;i<=str1.length();i++)
    {
        for(int j=1;j<=str2.length();j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                temp[i][j]=temp[i-1][j-1];
            }
            else{
                temp[i][j]=1+min(temp[i-1][j-1],temp[i-1][j],temp[i][j-1]);
            }
        }
    }

    return temp[str1.length()][str2.length()];
}


int main()
{
    string str1;
    string str2;
    cin>>str1>>str2;
    int l1=str1.length();
    int l2=str2.length();
    cout<<dynamicedit(str1,str2,l1,l2);

    return 0;
}
