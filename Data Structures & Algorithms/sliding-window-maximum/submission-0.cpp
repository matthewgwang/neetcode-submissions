class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        if (n==0) {return {};}
        if (k==1) {return nums;}

        vector<int>left_max(n), right_max(n);
        left_max[0] = nums[0];
        right_max[n-1] = nums[n-1];
        ///create running 
        for (int i = 1; i<n; i++) {
            if (i%k == 0) {
                left_max[i] = nums[i];
            } else {left_max[i] = max(left_max[i-1], nums[i]);}

            int j = n-i-1;
            if ((j+1)%k== 0) {right_max[j] = nums[j];}
            else {
                right_max[j] = max(right_max[j+1], nums[j]);
            }


        }

        vector<int> result;
        for (int i =0 ; i<=n-k; i++) {
            result.push_back(max(right_max[i], left_max[i+k-1]));
        }
        return result;

    }
};
