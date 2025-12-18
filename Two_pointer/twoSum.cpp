//leetcode Q:1
//two sum solution using two-pointer method
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], i}); // first = value, second = index
        }

        sort(v.begin(), v.end());
        int left = 0;
        int right = v.size() - 1;

        while (left < right)
        {
            int sum = v[left].first + v[right].first;
            if (sum == target)
            {
                return {v[left].second, v[right].second};
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return {}; // return empty vector if no answer
    }
};

int main()
{
    Solution sol;

    // sample input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = sol.twoSum(nums, target);

    // Print result
    if (!ans.empty())
    {
        cout << "Indexes: " << ans[0] << ", " << ans[1] << endl;
    }
    else
    {
        cout << "No valid pair found" << endl;
    }

    return 0;
}
