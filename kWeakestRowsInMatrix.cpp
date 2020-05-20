class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.second==p2.second)
            return p1.first<p2.first;
        return p1.second<p2.second;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int,int> um;
        for(int i=0;i<mat.size();i++)
        {
            int count=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
            um[i]=count;
        }
        vector< pair<int,int> > vec;
        copy(um.begin(),um.end(),back_inserter(vec));
        sort(vec.begin(),vec.end(),comp);
        vector<int> res;
        for(int i=0;i<k;i++)
            res.push_back(vec[i].first);
        return res;
    }
};
