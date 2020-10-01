class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> sol(nums.size(), -1);
        stack<int> stack;

        for (int i = 0; i < nums.size() * 2; i++)
        {
            int n = nums.at(i % nums.size());

            while (stack.size() and nums.at(stack.top()) < n)
            {
                sol.at(stack.top()) = n;
                stack.pop();
            }

            stack.push(i % nums.size());
        }

        return sol;
    }
};