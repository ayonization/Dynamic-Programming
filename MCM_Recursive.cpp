#include<bits/stdc++.h>
using namespace std;
int mcm(int a[],int i,int j)
{
    if(i>=j) return 0;

    int ans=INT_MAX;
    for (int k = i; k <=j-1; k++)
    {
        int temp= mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
        ans=min(ans,temp);
    }

    return ans;
    
}
int main()
{
    int n;
    cout<<"Enter size of array "<<endl;
    cin>>n;

    int a[n];
    cout<<"Enter the array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int ans= mcm(a,1,n-1);

    cout<<"Answer is "<<ans<<endl;
    
}
