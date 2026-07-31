class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int left = 0, right = 0;
        vector<int> ans;
        double median;
        while(left<n1 && right<n2)
        {
            if(nums1[left]<nums2[right])
            {
                ans.push_back(nums1[left]);
                left++;
            }
            else
            {
                ans.push_back(nums2[right]);
                right++;
            }
        }
        while(left<n1)
        {
            ans.push_back(nums1[left]);
            left++;
        }
        while(right<n2)
        {
            ans.push_back(nums2[right]);
            right++;
        }
        int n = ans.size();
        if(ans.size() % 2 == 0)
        {
            median = (ans[n/2] + ans[(n/2)-1])/2.0;

        }
        else
        {
            median = ans[n/2];
        }
    return median;
    }
};