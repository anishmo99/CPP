class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;

        double a = log10(n) / log10(3); // loga(b) = log(b)/log(a)

        int b = a;

        // cout << a << " " << b;

        return b == a;
    }
};