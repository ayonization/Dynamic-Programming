#include <bits/stdc++.h>
using namespace std;

int dp[100000][100000];
void knapsack(int wt[], int val[], int w, int n)
{
    if (n == 0 or w == 0)
        dp[n][w]= 0;
    if (wt[n - 1] > w)
        dp[n][w]= dp[n-1][w];
    else 
        dp[n][w] = max(dp[n-1][w],val[n-1]+dp[n-1][w-wt[n-1]]);
}

int main()
{
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;

    int wt[n];
    cout << "Enter weight array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    int val[n];
    cout << "Enter value array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int w;
    cout << "Enter max weight" << endl;
    cin >> w;

    knapsack(wt,val,n,w);
    
    cout << "Answer is " << dp[n][w] << endl;
}