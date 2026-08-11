#include <vector>
using namespace std;

class Solution {
public:  
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2; // Total elements
        
        // Target indices for the median
        int index2 = n / 2;
        int index1 = index2 - 1;
        
        int count = 0; // Represents the current index in our imaginary merged array
        int ind1ele = -1, ind2ele = -1;
        
        int left = 0, right = 0;
        
        // Loop while BOTH arrays still have elements to compare
        while(left < n1 && right < n2) {
            if(nums1[left] < nums2[right]) {
                if(count == index1) ind1ele = nums1[left];
                if(count == index2) ind2ele = nums1[left];
                count++; 
                left++;
            } else {
                if(count == index1) ind1ele = nums2[right];
                if(count == index2) ind2ele = nums2[right];
                count++; 
                right++;
            }
        }

        // If nums2 is exhausted but nums1 still has elements
        while(left < n1) {
            if(count == index1) ind1ele = nums1[left];
            if(count == index2) ind2ele = nums1[left];
            count++; 
            left++;
        }

        // If nums1 is exhausted but nums2 still has elements
        while(right < n2) {
            if(count == index1) ind1ele = nums2[right];
            if(count == index2) ind2ele = nums2[right];
            count++; 
            right++;
        }
        
        // If total length is ODD, median is just the element at index2
        if (n % 2 != 0) {
            return (double)ind2ele;
        }
        
        // If total length is EVEN, median is the average of index1 and index2
        return (double)(ind1ele + ind2ele) / 2.0;
    }
};