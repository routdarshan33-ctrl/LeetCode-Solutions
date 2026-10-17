class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string result = goal + goal;
        return result.find(s) != string::npos;
    }
};