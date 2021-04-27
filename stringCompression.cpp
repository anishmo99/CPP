class Solution {
public:
    int compress(vector<char>& chars) {
        
        if(chars.size() <= 1)
            return chars.size();
        
        string s;
        
        int count = 0;
        
        for(int i = 0; i < chars.size(); i++){
            count = 1;
            s.push_back(chars[i]);
           
            while(i < chars.size() - 1 and chars[i] == chars[i + 1]){
                i++;
                count++;
            }
            
            if(count > 1){
                s += to_string(count);
            }
        }
        
        for(int i = 0; i < s.size(); i++)
            chars[i] = s[i];
        
        return s.size();
    }
};