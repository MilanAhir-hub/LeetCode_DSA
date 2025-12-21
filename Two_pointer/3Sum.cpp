//leetcode threesum problem
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> sums;

        for (int i = 0; i < length; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int num1 = nums[i];
            int low = i + 1;
            int high = length - 1;

            while (low < high)
            {
                int sum = num1 + nums[low] + nums[high];
                if (sum == 0)
                {
                    sums.push_back({num1, nums[low], nums[high]});
                    low++;
                    high--;

                    while (low < high && nums[low] == nums[low - 1])
                    {
                        low++;
                    }
                    while (low < high && nums[high] == nums[high + 1])
                    {
                        high--;
                    }
                }
                else if (sum < 0)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }

        return sums;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> result = s.threeSum(nums);

    for (auto &triplet : result)
    {
        for (int x : triplet)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
