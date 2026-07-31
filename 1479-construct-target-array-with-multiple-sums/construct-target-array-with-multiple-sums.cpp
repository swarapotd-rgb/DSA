class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<int> pq;

        for(int num : target)
        {
            sum += num;
            pq.push(num);
        }
        while(true)
        {
        long long largest = pq.top();
        pq.pop();

        long long rest = sum - largest;
        if(largest == 1 || rest == 1)
        {
            return true;
        }
        if(rest == 0 || largest<rest || largest % rest == 0)
        {
            return false;
        }
        long long previous = largest % rest;
        sum = rest+ previous;
        pq.push(previous);
        }
    }
};