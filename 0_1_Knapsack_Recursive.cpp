#include <bits/stdc++.h>
using namespace std;
int knapsack(int wt[], int val[], int w, int n)
{
    if (n == 0 or w == 0)
        return 0;
    if (wt[n - 1] > w)
        return knapsack(wt, val, w, n - 1);
    if (wt[n - 1] <= w)
        return max(knapsack(wt, val, w, n - 1), val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1));
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

    int ans = knapsack(wt, val, w, n);

    cout << "Answer is " << ans << endl;
}