//geekforgeeks problem
//Number of triplate availble with smaller sum than this

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    long long countTriplets(int n, long long sum, long long arr[])
    {
        // Your code goes here

        // let sort given array
        sort(arr, arr + n);

        long long count = 0;

        for (int i = 0; i < n; i++)
        {

            long long num1 = arr[i];
            int low = i + 1;
            int high = n - 1;

            while (low < high)
            {
                long long addition = num1 + arr[low] + arr[high];

                if (addition < sum)
                {
                    count += (high - low);
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }

        return count;
    }
};

int main()
{
    long long arr[] = {5, 1, 3, 4, 7};
    int n = 5;
    long long sum = 12;

    Solution s;
    long long result = s.countTriplets(n, sum, arr);

    cout << result << endl;

    return 0;
}
