#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
void knapsack(int coin[],int n,int sum)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if(i==0) dp[i][j]=INT_MAX-1;
            if(j==0) dp[i][j]=0;
            if(i>0 and j>0)
            {
                if(coin[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j] = min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
            }
        }
        
    }
    
}
int main()
{
    int n;
    cout<<"Enter size of coin array"<<endl;
    cin>>n;

    int coin[n];
    cout<<"Enter the coin array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>coin[i];
    }

    int sum;
    cout<<"Enter required sum"<<endl;
    cin>>sum;

    knapsack(coin,n,sum);

    cout<<"Required number of minumum coins is "<<dp[n][sum];
    
    

    
}