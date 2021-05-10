#include<bits/stdc++.h>
using namespace std;

int egg_drop(int e,int f)
{
    if(e==1) return f;

    if(f==0 or f== 1) return f;

    int mn = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(egg_drop(e-1,k-1),egg_drop(e,f-k));
        mn = min (mn,temp);    
    }

    return mn;
    
}
int main()
{
    int e,f;

    cout<<"Enter number of eggs"<<endl;
    cin>>e;

    cout<<"Enter number of floors"<<endl;
    cin>>f;

    int ans = egg_drop(e,f);

    cout<<"The minimum number of attempts to find critical floor in worst case is "<<ans<<endl;

}