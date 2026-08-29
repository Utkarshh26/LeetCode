class Solution {
public:
    typedef pair<int, string> P;

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string word : words) {
            mp[word]++;
        }

        auto cmp = [](const P& a, const P& b) {
            if (a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        };

        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        for (auto& it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};