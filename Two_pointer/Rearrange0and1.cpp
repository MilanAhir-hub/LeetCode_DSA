//gfg: rearranging 0 and 1

#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        // code here
        int length = arr.size();

        int left = 0;
        int right = length - 1;

        while (left < right)
        {
            if (arr[left] == 1 && arr[right] == 0)
            {
                swap(arr[left], arr[right]);
            }

            if (arr[left] == 0)
            {
                left++;
            }

            if (arr[right] == 1)
            {
                right--;
            }
        }
    }
};

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution ob;
    ob.segregate0and1(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
