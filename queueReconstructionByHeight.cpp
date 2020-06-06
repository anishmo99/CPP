class Solution {
public:
    inline static bool comp(vector<int> a,vector<int> b)
    {
        return (a[0]>b[0]||(a[0]==b[0]&&a[1]<b[1]));
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(),people.end(),comp);
        vector<vector<int> > sol;
        
        for(auto person:people)
        {
            sol.insert(sol.begin()+person[1],person);
        }
        
        return sol;
    }
};
