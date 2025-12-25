#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        // code here
        int length = arr.size();
        if (length < k)
        {
            return 0;
        }

        int low = 0;
        int high = k - 1;

        int window_sum = 0;
        int max_sum = INT_MIN;

        // let do the sum of sliding window
        for (int i = low; i <= high; i++)
        {
            window_sum = window_sum + arr[i];
        }
        max_sum = window_sum;

        // now let slide the window
        while (high < length)
        {
            low++;
            high++;
            window_sum = window_sum - arr[low - 1];

            if (high >= length)
            {
                break;
            }

            window_sum = window_sum + arr[high];
            max_sum = max(window_sum, max_sum);
        }

        return max_sum;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.maxSubarraySum(arr, k);

    return 0;
}
