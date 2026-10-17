class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int> v(n+1, true);
        int count = 0;
        for(int i = 2; i < n; i ++){
            if(v[i]){
                count ++;
                for(long j = (long)i * i; j < n; j += i){
                    v[j] = false;
                }
            }
        }
        return count;
    }
};