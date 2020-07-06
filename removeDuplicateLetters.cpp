class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char, int> hash_map;
        unordered_map<char, bool> used;
        stack<char> stack;
        for (auto x : s)
            hash_map[x]++;
        for (auto x : s)
        {
            hash_map[x]--;
            if (!used[x])
            {
                while (stack.size() && stack.top() > x && hash_map[stack.top()] > 0)
                {
                    used[stack.top()] = false;
                    stack.pop();
                }
                stack.push(x);
                used[x] = true;
            }
        }
        string res;
        while (!stack.empty())
        {
            res = stack.top() + res;
            stack.pop();
        }
        return res;
    }
};