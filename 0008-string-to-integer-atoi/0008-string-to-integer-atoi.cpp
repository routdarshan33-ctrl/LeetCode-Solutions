class Solution {
public:
    int myAtoi(string s) {
        int i  = 0;
        long long ans = 0;
        while(i < s.size() && s[i] == ' '){
            i ++;
        }
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i ++;
        }
        else if(s[i] == '+'){
            sign = 1;
            i ++;
        }
        while(i < s.length()){
            if(!isdigit(s[i])) break;
            ans = ans * 10 + (s[i] - '0');
            if(sign == 1 && ans > INT_MAX) return INT_MAX;
            if(sign == -1 && -ans < INT_MIN) return INT_MIN;
            i ++;
        }
        return ans * sign;
    }
};