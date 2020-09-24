class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() == 1)
            return false;

        stack<char> stack;

        for (char c : s)
        {
            if (c == '(' or c == '{' or c == '[')
            {
                stack.push(c);
            }

            if (stack.empty())
                return false;

            if (c == ')' or c == '}' or c == ']')
            {
                if (c == ')' and (stack.top() == '[' or stack.top() == '{'))
                    return false;

                if (c == '}' and (stack.top() == '(' or stack.top() == '['))
                    return false;

                if (c == ']' and (stack.top() == '(' or stack.top() == '{'))
                    return false;

                stack.pop();
            }
        }
        return stack.empty();
    }
};