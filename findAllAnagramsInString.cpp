//sliding technique accepted

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.length()==0||p.length()>s.length())  return res;
        int hash[26]={0};
        for(int i=0;i<p.length();i++)
        {
            hash[p[i]-'a']++;
        }
        
        int left=0,right=0,count=p.length();
        
        while(right<s.length())
        {
            if(hash[s[right++]-'a']-- >=1)
                count--;
            
            if(count==0)
                res.push_back(left);
            
            if(right-left==p.length()&&hash[s[left++]-'a']++ >=0)
                count++;
        }
        
        return res;
    }
};

/*
//TLE
class Solution {
public:
    static bool isAnagram(string s1,string s2)
    {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<s1.length();i++)
            if(s1[i]!=s2[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec;
        if(s.length()==0||p.length()>s.length())   return vec;
        string check;
        for(int i=0;i<=s.length()-p.length();i++)
        {
            check=s.substr(i,p.length());
            if(isAnagram(check,p))
                vec.push_back(i);
        }
        return vec;
    }
};
*/

/*
//TLE
class Solution {
 public:
     inline bool isAnagram(string s1,string s2)
     {
         unordered_map<char,int>ump1,ump2;
         for(int i=0;i<s1.length();i++)
         {
             ump1[s1[i]]++;
             ump2[s2[i]]++;
         }
         if(ump1==ump2)
             return true;
         return false;
     }
     vector<int> findAnagrams(string s, string p) {
         vector<int> vec;
         if(s.length()==0||p.length()>s.length())   return vec;
         string check;
         for(int i=0;i<=s.length()-p.length();i++)
         {
             check=s.substr(i,p.length());
             if(isAnagram(check,p))
                 vec.push_back(i);
         }
         return vec;
     }
 };
*/
