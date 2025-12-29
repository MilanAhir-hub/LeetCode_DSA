#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubWithSum(int x, vector<int> &arr)
    {
        int length = arr.size();
        int low = 0;
        int minLength = INT_MAX;
        int sum = 0;

        for (int high = 0; high < length; high++)
        {
            sum += arr[high];

            while (sum > x)
            {
                int currentLength = high - low + 1;
                minLength = min(minLength, currentLength);
                sum -= arr[low];
                low++;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

int main()
{
    int x;
    cin >> x;

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.smallestSubWithSum(x, arr);

    return 0;
}
