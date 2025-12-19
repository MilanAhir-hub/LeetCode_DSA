//gfg: remove duplicates
#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution
{
public:
    string removeDups(string &s)
    {
        int left = 0;

        while (left < (int)s.size())
        {
            int right = s.size() - 1; // last valid index

            while (left < right)
            {
                if (s[left] == s[right])
                {
                    s.erase(s.begin() + right);
                    right = s.size() - 1; // update after erase
                }
                else
                {
                    right--;
                }
            }
            left++;
        }

        return s;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution ob;
    cout << ob.removeDups(s);
    return 0;
}
