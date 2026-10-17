class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset <char> s1, s2;
        for(auto it : s){
            s1.insert(it);
        }
        for(auto it : t){
            s2.insert(it);
        }
        if(s1 == s2) return true;
        return false;
    }
};