class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        unsigned int rev = 0;
        int copy_x = x;

        while (copy_x != 0)
        {
            int r = copy_x % 10;
            rev = rev * 10 + r;
            copy_x /= 10;
        }

        cout << rev;

        if (rev == x)
            return true;
        return false;
    }
};