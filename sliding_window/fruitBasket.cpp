#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int length = fruits.size();

        int low = 0;
        unordered_map<int, int> freq;
        int ans = -1;

        for (int high = 0; high < length; high++)
        {
            freq[fruits[high]]++;

            while (freq.size() > 2)
            {
                freq[fruits[low]]--;
                if (freq[fruits[low]] == 0)
                {
                    freq.erase(fruits[low]);
                }
                low++;
            }
            ans = max(ans, high - low + 1);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> fruits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }

    Solution obj;
    cout << obj.totalFruit(fruits);

    return 0;
}
