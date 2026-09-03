class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxsum = 0, total = 0;
        int n = cardPoints.size();
        for(int i = 0; i<k; i++)
        {
            total += cardPoints[i];
        }
        maxsum = total;
        for(int j = 0; j <k; j++)
        {
            total -= cardPoints[k-j-1];
            total += cardPoints[n-j-1];
            maxsum = max(maxsum, total);

        }
        
    return maxsum;
        
    }
    
};