class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> vec;
        int inc_count=0;
        int dec_count=S.length();
        for(auto& i:S)
        {
            if(i=='I')
                vec.push_back(inc_count++);
            if(i=='D')
                vec.push_back(dec_count--);
        }
        vec.push_back(inc_count);
        return vec;
    }
};
