#include<bits/stdc++.h>
using namespace std;


vector <int> find_max_crossing_subarray(vector <int> ar, int low ,int mid ,int high)
{
    vector <int> value;
    int leftsum = -99999;

    int sum = 0;
    int maxright;
    int maxleft;

    for(int i=mid ; i>=low ; i--)
    {
        sum=sum+ar[i];

        if(sum>leftsum)
        {
            leftsum=sum;
            maxleft=i;
        }
    }

    int rightsum = -99999;

    sum=0;

    for(int j=mid+1; j<=high ; j++)
    {
        sum=sum+ar[j];
        if(sum>rightsum)
        {
            rightsum=sum;
            maxright=j;
        }
    }

    value.push_back(maxleft);
    value.push_back(maxright);
    sum=(leftsum+rightsum);
    value.push_back(sum);
    return (value);
}


vector <int> find_maximum_subarray(vector<int> arrr, int low ,int high)
{

    if(high==low)
    {
        vector <int> base;
        base.push_back(low);
        base.push_back(high);
        base.push_back(arrr[low]);

        return (base);
    }
    int mid;
    mid=(low+high)/2;

    vector <int> left;
    vector <int> right;
    vector<int> cross;

    left=find_maximum_subarray(arrr,low,mid);

    right=find_maximum_subarray(arrr,mid+1,high);

    cross=find_max_crossing_subarray(arrr,low,mid,high);

    if(left[(left.size()-1)]>=right[(right.size()-1)] && left[(left.size()-1)]>=cross[cross.size()-1] ) return(left);

    else if(right[(right.size()-1)]>=left[(left.size()-1)]  &&  right[(right.size()-1)]>=cross[(left.size()-1)])  return(right);

    else return (cross);

}


int main()
{
    vector <int> a;
    int n,in;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>in;
        a.push_back(in);
       // cout<<a[i]<<" ";
    }
    cout<<endl;

    vector <int> maxsum;

    maxsum=find_maximum_subarray(a,0,a.size()-1);

    cout<<"Lower Index="<<maxsum[0]+1<<endl<<"Higher Index="<<maxsum[1]+1<<endl<<"Maximum Subarray Sum="<<maxsum[2]<<endl;

    return 0;
}

