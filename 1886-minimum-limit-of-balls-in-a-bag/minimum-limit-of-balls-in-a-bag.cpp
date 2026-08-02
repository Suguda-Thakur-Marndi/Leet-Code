class Solution {
public:
    bool canMake(vector<int>& nums, int maxOperations, int penalty) {
        long long operations = 0;

        for (int balls : nums) {
            operations += (balls - 1) / penalty;

            if (operations > maxOperations)
                return false;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canMake(nums, maxOperations, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};