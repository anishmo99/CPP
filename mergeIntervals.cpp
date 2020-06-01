//
// Created by Anish Mookherjee on 30/05/20.
//

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty())
            return result;
        sort(intervals.begin(),intervals.end(),[](vector<int> p1,vector<int> p2){return p1[0]<p2[0];});

        result.push_back(intervals.front());
        for(int i=0;i<intervals.size();i++)
        {
            if(result.back()[1]<intervals[i][0])
                result.push_back(intervals[i]);
            else
                result.back()[1]=max(result.back()[1],intervals[i][1]);
        }

        return result;
    }
};