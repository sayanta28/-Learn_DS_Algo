Welcome to the Algorithm wiki!
#include<iostream>
using namespace std;

int board[9][9]={0};

void printsolve(int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int row,int col,int N)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])   ///to cheak same row value
            return false;
    }

    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    for(i=row,j=col;i<N && j>=0;i++,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }

    return true;
}

bool solveNQ(int col,int N)
{
    if(col>=N)
    {
        return true;
    }

    for(int i=0;i<N;i++)
    {
        if(isSafe(i,col,N))
        {
            board[i][col]=1;

            if(solveNQ(col+1,N))
                return true;

            board[i][col]=0;
        }
    }

    return false;
}

int main()
{
    int n;
    cin>>n;
    bool value=solveNQ(0,n);

    if(value==false)
        cout<<"Solution does not exists"<<endl;

    else
        printsolve(n);

    return 0;

}
