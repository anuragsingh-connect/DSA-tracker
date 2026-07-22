class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int n = nums.size();
        int num = 0;
        for (int i = 0 ; i < n; i++) {

             num = nums[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[num   ] = i;
        }
        return  {-1, -1};

        
        }
};