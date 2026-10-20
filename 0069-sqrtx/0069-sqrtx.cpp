class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int low = 0, high = x, f;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid <= x / mid){
                f = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return f;
    }
};