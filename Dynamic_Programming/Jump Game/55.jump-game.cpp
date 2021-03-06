/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/
 *
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size(), i, reachable = 0, count = 0;

        if (arr[0] == 0 && len == 1 || len == 1) // [0]
            return true;

        if (arr[0] == 0)
            return false;

        // Peak Valley Approach  <------  GREEDY APPROACH
        for (i = 0; i < len; i++)
        {
            if (i > reachable) // could not react Index
                return false;

            reachable = max(reachable, i + nums[i]); //  Index Trace

            if (reachable >= len - 1)
                return true;
        }

        return false;
    }
};
// @lc code=end
