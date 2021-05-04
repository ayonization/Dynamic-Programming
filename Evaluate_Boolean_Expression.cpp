#include<bits/stdc++.h>
using namespace std;

int evaluate(string s,int i,int j,bool isTrue)
{
    if(i>j) return false;
    if(i==j)
    {
        if(isTrue) return s[i]=='T';
        else return s[i]=='F';
    }

    int ans=0;

    for (int k = i+1; k <j ; k+=2)
    {
        int lt = evaluate(s,i,k-1,true);
        int lf = evaluate(s,i,k-1,false);
        int rt = evaluate(s,k+1,j,true);
        int rf = evaluate(s,k+1,j,false);


        if(s[k]=='^')
        {

            if(isTrue) ans+= lt*rf+rt*lf;
             else ans+= lt*rt+rf*lf;    
        }
        if(s[k]=='&')
        {
            if(isTrue) ans+=lt*rt;
            else ans+= lt*rf+lf*rt+lf*rf ;
        }
        if(s[k]=='|')
        {
            if(isTrue) ans+=lt*rt+lt*rf+rt*lf;
            else ans+= lf*rf ;
        }
    }
    return ans;
}

int main()
{
    string s;
    cout<<"Enter boolean expression"<<endl;
    cin>>s;

    int ans=evaluate(s,0,s.length()-1,true);

    cout<<"Number of ways to evaluate the given expression to true is "<<ans<<endl;

}