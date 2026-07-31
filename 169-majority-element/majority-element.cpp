class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int i = 0; i< nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]]++;
            }else{
                mp[nums[i]] =1;
            }
        }
        int majority =0,ele;
        for(auto &it : mp){
            if(majority < it.second){
                ele =it.first;
                majority =it.second;
            }
        }
        return ele;
    }
};