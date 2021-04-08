#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int SubsetSum(int a[], int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;

            if (i > 0 and j > 0)
            {
                if (a[i - 1] > sum)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
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

    int ans = SubsetSum(a, sum, n);

    cout<<"No of subsets with reqd sum is "<<ans<<endl;
}