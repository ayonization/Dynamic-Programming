#include<bits/stdc++.h>
using namespace std;
bool dp[1000][1000];
void knapsack(int a[],int n,int sum)
{
    for(int i=0;i<=n;i++)
    {
        for (int j = 0; j <=sum; j++)
        {
            if(i==0) dp[i][j]=false;
            if(j==0) dp[i][j]=true;
            if(i>0 and j>0)
            {
                if(a[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j] or dp[i-1][j-a[i-1]];
            }
        }
        
    }
}
int main()
{
    int n;
    cout<<"Enter size of array "<<endl;
    cin>>n;
    
    int a[n];
    cout<<"Enter the array "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
    }

    int mid=sum/2;


    int ans=sum;

    knapsack(a,n,sum);
    bool check=true;

    for (int i = mid; i >= 0; i--)
    {
        if(dp[n][i] and check)
        {
            ans=sum-2*i;
            check=false;
        }
    }
    
    cout<<"Minimum difference is "<<ans<<endl;

    
}