class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> vec;
        for (int a : nums)
            vec.push_back(to_string(a));

        sort(vec.begin(), vec.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        string sol;
        for (auto a : vec)
            sol = sol + a;

        if (sol[0] == '0')
            return "0";

        return sol;
    }
};