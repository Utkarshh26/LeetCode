class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]) != freq.end()) {
                freq[nums[i]]++;
            } else {
                freq[nums[i]] = 1;
            }
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        for(auto& it: freq){
            int fre = it.second, val = it.first;
            pq.push({fre, val});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};