class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int ele = 0; 
        int cnt = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            
            // 1. If the throne is empty, claim it!
            if (cnt == 0) {
                ele = arr[i]; 
                cnt = 1; 
            }
            // 2. If it's the same number, add a vote
            else if (arr[i] == ele) {
                cnt++;
            }
            // 3. If it's a different number, lose a vote
            else {
                cnt--;
            }
            
        }

        return ele;
    }
};