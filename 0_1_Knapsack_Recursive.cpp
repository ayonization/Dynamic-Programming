#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int n, int w)
{
    if (n == 0 or w == 0)
        return 0;
    if (wt[n - 1] > w)
        return knapsack(wt,val,n-1,w);
    else 
        return max(knapsack(wt,val,n-1,w),val[n-1]+knapsack(wt,val,n-1,w-wt[n-1]));
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

    int ans = knapsack(wt,val,n,w);
    
    cout << "Answer is " << ans << endl;
}