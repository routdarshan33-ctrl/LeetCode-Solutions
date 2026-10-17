
class Solution {
public:
    string frequencySort(string s) {
        if(s.empty()) return "";
        unordered_map<char, int> mp;
        for(auto it : s){
            mp[it] ++;
        }
        vector<string> v(s.size() + 1);
        for(auto it : mp){
            v[it.second].append(it.second, it.first);
        }
        string result = "";
        for(int i = s.size(); i >= 1; i --){
            result += v[i];
        }
        return result;
    }
};
