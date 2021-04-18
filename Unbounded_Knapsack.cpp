#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
void knapsack( int wt[],int val[],int n,int w)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if(i==0 or j==0) dp[i][j]=0;
            else
            {
                if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
        }
        
    }
    
}
int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    int wt[n];
    cout<<"Enter the weight array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i];
    }

    int val[n];
    cout<<"Enter the value array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>val[i];
    }

    int w;
    cout<<"Enter capacity of knapsack"<<endl;
    cin>>w;

    knapsack(wt,val,n,w);

    cout<<"The maximum profit for this unbounded knapsack is "<<dp[n][w];
    
    
}