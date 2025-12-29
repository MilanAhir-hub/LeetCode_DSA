//longest subarray of atmost two

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalElements(vector<int> &arr)
    {
        int length = arr.size();
        int low = 0;
        unordered_map<int, int> freq;
        int result = -1;

        for (int high = 0; high < length; high++)
        {
            freq[arr[high]]++;

            while (freq.size() > 2)
            {
                freq[arr[low]]--;
                if (freq[arr[low]] == 0)
                {
                    freq.erase(arr[low]);
                }
                low++;
            }

            result = max(result, high - low + 1);
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.totalElements(arr);

    return 0;
}
