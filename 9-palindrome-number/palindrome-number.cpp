class Solution {
public:
    bool isPalindrome(int x) {
        int revn = 0;
        int dup = x;
        while(x != 0 )
        {
            int last_digit = x % 10;
            if((revn > INT_MAX / 10 )||(revn == INT_MAX / 10 && last_digit > 7))
                return 0;
            if((revn < INT_MIN / 10 )||(revn == INT_MIN / 10 && last_digit <-8))
                return 0;

            revn = (revn * 10) + last_digit;
            x = x / 10;
        }
        if(dup == revn && dup >= 0)
            return true;
        else
            return false;   
    }
};