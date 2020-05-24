class Solution {
public:
    static bool comp(pair<char,int>p1,pair<char,int>p2)
    {
        if(p1.second==p2.second)
            return p1.first<p2.first;
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>ump;
        vector<pair<char,int>> vec;
        for(auto&i : s)
            ump[i]++;
        copy(ump.begin(),ump.end(),back_inserter(vec));
        sort(vec.begin(),vec.end(),comp);
        string result;
        for(auto& i:vec)
            for(int j=0;j<i.second;j++)
                result+=i.first;
        return result;
    }
};
