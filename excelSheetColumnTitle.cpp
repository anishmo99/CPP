class Solution
{
public:
    string convertToTitle(int n)
    {
        string res;

        char temp;

        while (n != 0)
        {
            temp = 'A' + --n % 26;
            res = temp + res;
            n /= 26;
        }

        return res;
    }
};