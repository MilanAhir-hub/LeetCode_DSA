//threeSumClosest problem from leetcode
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int length = nums.size();
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < length; i++)
        {
            int num1 = nums[i];

            int low = i + 1;
            int high = length - 1;

            while (low < high)
            {
                int sum = num1 + nums[low] + nums[high];

                if (sum == target)
                {
                    return sum;
                }

                if (abs(sum - target) < abs(closest - target))
                {
                    closest = sum;
                }

                if (sum < target)
                {
                    low++;
                }

                if (sum > target)
                {
                    high--;
                }
            }
        }
        return closest;
    }
};

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    Solution s;
    int ans = s.threeSumClosest(nums, target);
    cout << ans << endl;

    return 0;
}
