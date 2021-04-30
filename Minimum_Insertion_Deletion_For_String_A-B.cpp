#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int lcs(string a,string b,int n,int m)
{
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=m;j++)
        {
            if(i==0 or j==0) dp[i][j]=0;
            if(i>0 and j>0)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
    }

    return n+m-2*dp[n][m];
    
}
int main()
{   
    memset(dp,-1,sizeof(dp));
    string a,b;
    cout<<"Enter first string"<<endl;
    cin>>a;

    cout<<"Enter second string"<<endl;
    cin>>b;

    int ans= lcs(a,b,a.length(),b.length());

    cout<<"Minimum number of insertions and deletions to convert string a to string b is "<<ans<<endl;
}