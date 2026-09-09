class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count_map;
        for (int num: nums){
            count_map[num]++;
        }

        vector<vector<int>>buckets(nums.size()+1);
        for (auto& pair: count_map){
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        vector<int>result;
        for (int i = buckets.size()-1; i>= 0; i--){
            for (int num : buckets[i]) {
                result.push_back(num);

                if (result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
