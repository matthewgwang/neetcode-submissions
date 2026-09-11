class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        int volume = 0;

        vector<int>left_max(length);
        vector<int>right_max(length);

        left_max[0] = height[0];
        right_max[length-1] = height[length-1];

        for (int i =1 ; i<length; i++){
            left_max[i] = max(left_max[i-1], height[i]);
            

        }
        for (int i= length-2; i>= 0; i--) {
            right_max[i] = max(right_max[i+1], height[i]);
        }

        for (int i = 0; i<length; i++) {
            int surface_height = min(left_max[i], right_max[i]);

            if (height[i]>=surface_height) {
                volume += 0;
            } else {
                int added_volume = surface_height - height[i];
                volume += added_volume;
            }
        }

        return volume;


        
    }
};
