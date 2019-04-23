#include<bits/stdc++.h>

using namespace std;

void PrintLcs(vector<vector<int> > b, string a, int m, int n)
{
    if(m == 0 || n == 0)
    {
        return ;
    }
    if(b[m][n] == 7)
    {
        PrintLcs(b, a, m-1, n-1);
        printf("%c ", a[m]);
    }
    else if(b[m][n] == 8)
    {
        PrintLcs(b, a, m-1, n);
    }
    else
    {
        PrintLcs(b, a, m, n-1);
    }
}

void LCS_Length(string a, string B)
{
    int m = a.size();
    int n = B.size();

    vector<vector<int> > b(m+1, vector<int> (n+1));
    vector<vector<int> > lcs(m+1, vector<int> (n+1));

    int i,j,k;

    for(i=1; i<=m; i++)
    {
        lcs[i][0] = 0;
        lcs[0][i] = 0;
    }

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(a[i] == B[j])
            {
                lcs[i][j] = 1 + lcs[i-1][j-1];
                b[i][j] = 7;
            }
            else if(lcs[i-1][j] >= lcs[i][j-1])
            {
                lcs[i][j] = lcs[i-1][j];
                b[i][j] = 8;
            }
            else
            {
                lcs[i][j] = lcs[i][j-1];
                b[i][j] = 4;
            }
        }
    }
    cout<<endl<<lcs[m-1][n-1]<<endl;
    PrintLcs(b, a, m, n);
}

int main()
{
    string a, b;

    getline(cin, a);
    getline(cin, b);

    LCS_Length(a,b);
}
