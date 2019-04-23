#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<vector>
using namespace std;

vector <int> b;

void Merge (vector <int> a, int low, int mid, int high)
{
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while (i<=mid && j<=high)
    {
        if (a[i]<=a[j])
        {
            b[k++]=a[i++];

        }
        else
        {
            b[k++]=a[j++];

        }
    }
    while (i<=mid)
    {
        b[k++]=a[i++];
    }
    while (j<=high)
    {
        b[k++]=a[j++];
    }
    for (k=low;k<=high; k++)
    {
        a[k]=b[k];
    }

}

void MergeSort(vector <int> a, int low, int high)
{
    int mid;
    if (low>=high)
    {
        return;
    }
    mid= (low+high)/2;
    MergeSort(a,low,mid);
    MergeSort(a,mid+1,high);
    Merge (a, low, mid, high);
}

int main()
{
    vector <int> a;
    int n, k;
    clock_t st, et;
    double ts;
    printf("\n\tHow many numbers to be sorted?:");
    scanf("%d", &n);
    printf("\n\t The Random Numbers are:\n");
    for (k=1; k<=n; k++)
    {
        a[k]=rand();
        printf("%d\t", a[k]);
    }
    st= clock();
    MergeSort(a,1,n);
    et= clock();
    ts= (double)(et-st)/CLOCKS_PER_SEC;
    printf("\n\tThe Sorted Numbers are:\n");
    for (k=1; k<=n; k++)
    {
        printf("%d\t", a[k]);
    }

    printf("\nTime Taken for this Program: %lf",ts);

    return 0;
}
