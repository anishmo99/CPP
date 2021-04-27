class Solution {
public:
    string reorganizeString(string S) {
        map<char, int> m;

        for(char c : S){
            m[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        
        for(auto x : m){
            pq.push({x.second, x.first});
        }
        
        string ans;
        
        while(pq.size() > 1){
            char mfc = pq.top().second;
            pq.pop();
            
            char nmfc = pq.top().second;
            pq.pop();
            
            ans.push_back(mfc);
            ans.push_back(nmfc);
            
            if(m[mfc] > 1){
                m[mfc]--;
                pq.push(make_pair(m[mfc], mfc));
            }
            
            if(m[nmfc] > 1){
                m[nmfc]--;
                pq.push(make_pair(m[nmfc], nmfc));
            }
        }
        
        if(!pq.empty()){
            char x = pq.top().second;
            if(m[x] > 1)
                return "";
            ans.push_back(x);
        }
        
        return ans;
    }
};