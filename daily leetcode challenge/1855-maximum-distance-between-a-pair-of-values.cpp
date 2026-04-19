class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int j = -1;
            int l = i, r = m-1;
            while(l <= r){
                int mid = (l+r)/2;
                if(nums1[i] == nums2[mid]){
                    j = max(j, mid);
                    l = mid + 1;
                }
                else if(nums2[mid] > nums1[i]){
                    j = max(j, mid);
                    l = mid +1;
                }
                else {
                    r = mid -1;
                }
            }
            if(j != -1) ans = max(ans, j-i);
        }

        return ans;
    }
};