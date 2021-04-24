#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int lcs(string s1,string s2,int n,int m)
{   
    int ans=-1;

    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=m; j++)
        {
            if(i==0 or j==0) dp[i][j]=0;
            else
            {
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]= 0;
            }

            ans=max(ans,dp[i][j]);
        }
        
    }
    return ans;
    
}

int main()
{   
    memset(dp,-1,sizeof(dp));
    string s1,s2;
    cout<<"Enter first string"<<endl;
    cin>>s1;
    cout<<"Enter second string"<<endl;
    cin>>s2;
    int n=s1.length();
    int m=s2.length();
    int ans=lcs(s1,s2,n,m);
    cout<<"Length of longest common substring is "<<ans<<endl;

    
}