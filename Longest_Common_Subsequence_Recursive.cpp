#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2,int n,int m)
{
    if(n==0 or m==0) 
    return 0;

    else
    {
        if(s1[n-1]==s2[m-1]) return 1+lcs(s1,s2,n-1,m-1);
        else return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }
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
    int ans=lcs(s1,s2,n,m);
    cout<<"Length of longest common subsequence is "<<ans<<endl;
}