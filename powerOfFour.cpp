// log
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0)
            return false;
        double a = log(num) / log(4);

        int b = a;

        return b == a;
    }
};

// naive
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num > 1)
        {
            while (num % 4 == 0)
            {
                num /= 4;
            }
        }
        return num == 1;
    }
};

