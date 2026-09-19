class Solution {
    vector<vector<int>> subset;
    set<vector<int>> st;
private:    
    void helper(vector<int>&nums, vector<int>& ds, int idx, int n){
        if(idx>= n){
            if(st.find(ds) == st.end()){
                st.insert(ds);
                subset.push_back(ds);
            }
            return;
        }
        ds.push_back(nums[idx]);
        helper(nums,ds,idx+1,n);

        ds.pop_back();
        helper(nums,ds,idx+1,n);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        helper(nums,ds,0,nums.size());
        return subset;
    }
};