#include <bits/stdc++.h>
using namespace std;
bool dp[1000][1000];
bool SubsetSum(int a[], int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;

            if (i > 0 and j > 0)
            {
                if (a[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - a[i - 1]];
            }
        }
    }

    return dp[n][sum];
}
int main()
{
    int n;
    cout << "Enter the size of the array " << endl;
    cin >> n;

    int a[n];
    cout << "Enter the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum;
    cout << "Enter required sum" << endl;
    cin >> sum;

    bool ans = SubsetSum(a, sum, n);

    if (ans)
        cout << "YES Such a subset sum exists" << endl;
    else
        cout << "NO This subset sum does not exist" << endl;
}