#include<bits/stdc++.h>
#include<unordered_map>
using namespace std; 

unordered_map<string,bool> mp;
bool scramble(string s1,string s2) 
{
    if(s1.length()!=s2.length()) return false;
    if(s1.compare(s2)==0) return true;
    if(s1.length()<=1) return false;

    bool ans = false;
    int n = s1.length();

    string key = s1;
    key.push_back(' ');
    key.append(s2);

    if(mp.find(key)!=mp.end())
    {
        return mp[key];
    }

    for (int i = 1; i <n;i++)
    {
        ans =   ((scramble(s1.substr(0,i),s2.substr(n-i,i)))&&(scramble(s1.substr(i,n-i),s2.substr(0,n-i)))) //swapped case
                                                    ||
                ((scramble(s1.substr(0,i),s2.substr(0,i))) && (scramble(s1.substr(i,n-i),s2.substr(i,n-i)))); // not swapped case

        if(ans) break;
    }

    return mp[key]=ans;
    

}
int main()

{

    string s1,s2;
    cout<<"Enter first string"<<endl;
    cin>>s1;
    cout<<"Enter second string"<<endl;
    cin>>s2;

    bool ans = scramble(s1,s2);
    if(ans) cout << "Strings are Scrambled "<< endl;
    else cout << "NO" << endl;
}

#include<bits/stdc++.h>

