#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

void knapsack(int a[],int n,int sum)
{
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=n; j++)
        {
            if(i==0) dp[i][j]=0;
            if(j==0) dp[i][j]=1;
            if(i>0 and j>0)
            {
                if(a[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]= dp[i-1][j]+dp[i-1][j-a[i-1]];
            }
        }
        
    }
    
}

int main()
{
    int n;
    cout<<"Enter the size of array "<<endl;
    cin>>n;
    
    int a[n];
    cout<<"Enter the array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int diff;
    cout<<"Enter required difference ";
    cin>>diff;

    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
    }

    int num=(sum-diff)/2;

    knapsack(a,n,diff);

    cout<<"Count of subsets with given difference is "<<dp[n][num];
    
    
}