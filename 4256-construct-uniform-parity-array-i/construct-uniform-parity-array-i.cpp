class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> nums2(n);

        for(int i = 0; i<n;i++)
        {
            if(nums1[i]%2==0)
            {
                int j=0;
                while(j<n)
                {
                if(nums1[j] % 2 !=0 && j!=i)
                {
                    nums2[i] = nums1[i] - nums1[j];
                    break;
                }
                else
                {
                    j++;
                }
                }
                
            }
            else
            {
                nums2[i] = nums1[i]; 
            }
        }
        return true;
    }
};