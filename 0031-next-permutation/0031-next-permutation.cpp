#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int brkpt = -1;
        
        // STEP 1: Find the breakpoint (the first dip from the right)
        for (int i = n - 2; i >= 0; i--) { // Start safely at n-2
            if (arr[i] < arr[i+1]) {       // Compare with the neighbor to the right
                brkpt = i;
                break;                     // Stop the exact moment we find it!
            }
        }

        // STEP 2: Find the next largest number, but ONLY if a breakpoint exists
        if (brkpt != -1) {                 // This prevents the arr[-1] crash!
            for (int i = n - 1; i > brkpt; i--) { // Scan right-to-left!
                if (arr[i] > arr[brkpt]) {
                    swap(arr[brkpt], arr[i]);
                    break;
                }
            }
        }

        // STEP 3: Reverse everything after the breakpoint
        reverse(arr.begin() + brkpt + 1, arr.end());
    }
};