class Solution {
public:
    bool checkInclusion(string p, string s) {
        if(s.length()==0||p.length()>s.length())
            return false;
    
        int hash[26]={0};
        for(char& i:p)
            hash[i-'a']++;
        
        int left=0,right=0,count=p.length();
        
        while(right<s.length())
        {
            if(hash[s[right++]-'a']-- >=1)
                count--;
            
            if(count==0)
                return true;
            
            if(right-left==p.length()&&hash[s[left++]-'a']++ >=0)
                count++;
            
        }
        return false;
    }
};
