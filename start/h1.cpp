#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int left = 1, right = nums.size();
        int sum = right * (right + 1) / 2;

        while (left <= right)
        {
            int mid = (left + right) >> 1;
            cout << mid << " " << countLess(nums, mid) << endl;
            if (countLess(nums, mid) < sum / 2)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (sum & 1)
        {
            if (countLess(nums, right + 1) <= sum / 2)
                return right + 1;
        }
        return right;
    }

    int countLess(vector<int> &nums, int tar)
    {
        if (tar <= 1) return 0;
        unordered_map<int, int> record;
        int res = 0;
        int left = 0, right = 0;
        while (left < nums.size())
        {
            while (record.size() < tar - 1 && right < nums.size())
            {
                ++record[nums[right++]];
            }
            res += (right - left);
            if (--record[nums[left]] == 0)
                record.erase(nums[left]);
            ++left;

        }
        return res;
    }
};