class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        digits[n - 1] = digits[n - 1] + 1;
        carry = digits[n - 1] / 10;
        digits[n - 1] %= 10;
        
        for(int i = n - 2; i >= 0; i--){
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        
        if(carry == 1)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};