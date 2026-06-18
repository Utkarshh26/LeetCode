class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), i = 0, j =0, idx = 0;
        vector<int> mergedarr(n + m);

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                mergedarr[idx++] = nums1[i++];
            }
            else if(nums1[i] > nums2[j]){
                mergedarr[idx++] = nums2[j++];
            }
            else{
                mergedarr[idx++] = nums2[j++];
                mergedarr[idx++] = nums1[i++];
            }
        }
        while(i < m){
            mergedarr[idx++] = nums1[i++];
        }

        while(j < n){
            mergedarr[idx++] = nums2[j++];
        }
        n = n + m;
        if(n % 2 != 0){
            return static_cast<double> (mergedarr[n/2]);
        }else{
            int left = mergedarr[n/2 -1];
            int right = mergedarr[n/2];
            return static_cast<double> (left + right) /2.0;
        }
    }
};