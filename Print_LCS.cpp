#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
string lcs(string s1,string s2,int n,int m)
{
    string ans;

    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=m; j++)
        {
            if(i==0 or j==0) dp[i][j]=0;
            if(i>0 and j>0)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }

        }
        
    }
    

    int i=n;
    int j=m;

    while(i>0 and j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ans.push_back(s1[i-1]);
            i-=1;
            j-=1;
        }

        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i-=1;
            }
            else j-=1;
        }


    }
        reverse(ans.begin(),ans.end());
    

        return ans;


}


int main()
{   
    string s1,s2;
    cout<<"Enter first string"<<endl; 
    cin>>s1;
    
    cout<<"Enter second string"<<endl; 
    cin>>s2;

    int n=s1.length();
    int m=s2.length();

    string ans= lcs(s1,s2,n,m);

    cout<<"The longest common subsequnce is"<<endl;
    cout<<ans <<endl;
   
   
   


}



