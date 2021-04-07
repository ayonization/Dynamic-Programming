#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

void knapsack(int wt[],int val[],int w, int n)
{
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if(i==0 or j ==0)
            dp[i][j]=0;
            else
            {
                if(wt[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]= max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
                }
            }
        }
        
    }
    
}
int main ()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;

    int wt[n];
    cout << "Enter the weight array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    int val[n];
    cout << "Enter the value array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int w;
    cout<<"Enter max weight"<<endl;
    cin>>w;

    knapsack(wt,val,w,n);

    cout<<"Answer is "<<dp[n][w];


}