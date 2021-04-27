class Solution {
public:
    string pushDominoes(string dom) {
        
        char l = 'L';
        char r = 'R';
     
        vector<int> leftDist(dom.size(), 0);
        vector<int> rightDist(dom.size(), 0);
        
        int count;
        char prev;
        
        for(int i = 0; i < dom.size(); i++){
            if(dom[i] == r){
                prev = r;
                count = 1;
                continue;
            }
            
            else if(dom[i] == l){
                prev = l;
            }
            
            if(prev == r and dom[i] == '.'){
                rightDist[i] = count++;
            }
        }
        
        prev = '.';
        
        for(int i = dom.size() - 1; i >= 0; i--){
            if(dom[i] == l){
                prev = l;
                count = 1;
                continue;
            }
            
            else if(dom[i] == r){
                prev = r; 
            }
            
            if(prev == l and dom[i] == '.'){
                leftDist[i] = count++;
            }
        }
        
        string ans;
        
        for(int i = 0; i < dom.size(); i++){
            if(!leftDist[i] and !rightDist[i])
                ans += dom[i];
            
            else if(!leftDist[i])
                ans += r;
            
            else if(!rightDist[i])
                ans += l;
            
            else if(leftDist[i] == rightDist[i])
                ans += '.';
            
            else if(leftDist[i] > rightDist[i])
                ans += r;
            
            else
                ans += l;
        }
        
        return ans;
    }
};

// or

class Solution {
public:
    string pushDominoes(string dom) {
        
        int n = dom.size();
        
        char l = 'L';
        char r = 'R';
        
        dom = l + dom + r;
        
        int i = 0, j = 1;
        
        while(i < dom.size() and j < dom.size()){
            while(dom[j] == '.'){
                j++;
            }
            
            if(dom[i] == r and dom[j] == l){
                int tempi = i + 1, tempj = j - 1; 
                while(tempi < tempj){
                    dom[tempi++] = r;
                    dom[tempj--] = l;
                }
            }
            
            else if(dom[i] == l and dom[j] == l){
                int tempi = i, tempj = j - 1;
                while(tempi < tempj){
                    dom[tempj--] = l;
                }
            }
            
            else if(dom[i] == r and dom[j] == r){
                int tempi = i + 1, tempj = j;
                while(tempi < tempj){
                    dom[tempi++] = r;
                }
            }
            
            i = j;
            j++;
        }
        
        return dom.substr(1, n);
    }
};