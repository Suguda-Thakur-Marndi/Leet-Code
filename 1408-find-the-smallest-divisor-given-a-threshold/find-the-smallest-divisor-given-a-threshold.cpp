class Solution {
public:
    int findSum(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;   
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (findSum(nums, mid) <= threshold) {
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }

        return low;
    }
};