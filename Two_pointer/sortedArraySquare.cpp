//sortedArraySquare leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n);

        int left = 0, right = n - 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                v[i] = nums[left] * nums[left];
                left++;
            }
            else
            {
                v[i] = nums[right] * nums[right];
                right--;
            }
        }
        return v;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> ans = obj.sortedSquares(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
