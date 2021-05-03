#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
bool ispallindrome(string s,int start,int end)
{
        bool ans=true;

        int sum=start+end;

        for (int i = start; i <=(start+end)/2 ; i++)
        {
            if(s[i]!=s[sum-i]) ans=false;
        }

        return ans;
        

}   


int partition(string s, int i,int j)
{   
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(ispallindrome(s,i,j)) return dp[i][j]=0;

    int ans=INT_MAX;

    for (int k = i; k <=j-1 ; k++)
    {
        int temp = partition(s,i,k)+partition(s,k+1,j)+1;
        ans=min(ans,temp);
    }

    return dp[i][j]=ans;
    
}
int main()
{   
    memset(dp,-1,sizeof(dp));
    string s;
    cout<<"Enter string"<<endl;
    cin>>s;

    int ansmemo=partition(s,0,s.length()-1);

    cout<<"Minimum number of partitons for pallindromic substrings is "<<ansmemo<<endl;



}