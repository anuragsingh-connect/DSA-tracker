class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 1. Find the first occurrence (>= target)
        auto lower = lower_bound(nums.begin(), nums.end(), target);

        // 2. Safety Check: Did we actually find the target?
        // If 'lower' hits the end of the array, or the number it points to
        // isn't the target, it means the target doesn't exist in the array at
        // all.
        if (lower == nums.end() || *lower != target) {
            return {-1, -1};
        }

        // 3. Find the element strictly GREATER than the target (> target)
        auto upper = upper_bound(nums.begin(), nums.end(), target);

        // 4. Convert iterators to numerical indices
        int start_pos = lower - nums.begin();

        // Since 'upper' points to the first number BIGGER than the target,
        // we subtract 1 from its index to get the LAST occurrence of the
        // target.
        int end_pos = (upper - nums.begin()) - 1;

        return {start_pos, end_pos};
    }
};