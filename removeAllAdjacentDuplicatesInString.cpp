class Solution {
public:
    string removeDuplicates(string str) {
       stack<char>stack;
        string ans;
        for(int i{};i<str.length();i++)
        {
            if(stack.empty())
            {
                stack.push(str[i]);
                continue;
            }
            else if(stack.top()==str[i])
            {
                stack.pop();
            }
            else
                stack.push(str[i]);
        }
        while(!stack.empty())
        {
            ans=stack.top()+ans;
            stack.pop();
        }
        return ans;
    }
};