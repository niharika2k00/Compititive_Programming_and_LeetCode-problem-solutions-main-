/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int len = nums.size(), i, reachable = 0, count = 0;

        if (nums[0] == 0 && len == 1) // [0]
            return true;

        if (nums[0] == 0)
            return false;

        // Peak Valley Approach  <------  GREEDY APPROACH
        for (i = 0; i < len; i++)
        {
            if (reachable < i)
                return false;

            reachable = max(reachable, i + nums[i]);
        }

        if (reachable == len - 1)
            return true;
        return true;
    }
};
// @lc code=end

/*
        // If No Zero element  =>  always return true
        if (nums[0] != 0)
        {
            for (i = 1; i < len; i++)
                if (nums[i] != 0)
                    count++;
            if (count == len - 1)
                return true;
        }
 */