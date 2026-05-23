class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for (int num : nums) {
            count[num]++;
        }
        int index = 0;

        for (int color = 0; color < 3; color++) {
            while (count[color]--) {
                nums[index++] = color;
            }
        }
    }
};