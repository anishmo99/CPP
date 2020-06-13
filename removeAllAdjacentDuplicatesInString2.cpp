class Solution {
public:
    string removeDuplicates(string str, int k) {
        if (str.empty()) 
            return str;
        stack<pair<char, int>> stack;
        for (int i=0;i<str.length();i++) 
        {
            if (!stack.empty()&&stack.top().first==str[i]) 
            {
                stack.top().second++;
                if(stack.top().second==k) 
                    stack.pop(); 
            } 
            else
                stack.push(make_pair(str[i], 1));
        }
        str="";
        while (!stack.empty()) 
        {
            int count=stack.top().second;
            while (count--) 
            {
                str=stack.top().first+str;
            }
            stack.pop();
        }
        return str;
    }
};

// two pointer

class Solution {
public:
   string removeDuplicates(string s, int k) {
        int i=0,j=1;
        while(j<s.length()){
            if(s[i]==s[j]){
                if(j-i+1==k){
                    s.erase(i,k);
                    i = 0;
                    j = 1;
                }
                else j++;
            }
            else{
                i = j;
                j++;
            }
        }
        return s;
    }
};