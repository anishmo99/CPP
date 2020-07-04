class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int ugly[n];
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++)
        {
            ugly[i] = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));
            if (ugly[i2] * 2 == ugly[i])
                ++i2;
            if (ugly[i3] * 3 == ugly[i])
                ++i3;
            if (ugly[i5] * 5 == ugly[i])
                ++i5;
        }
        return ugly[n - 1];
    }
};


// better understanding

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int ugly[n];
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int nm2 = 2, nm3 = 3, nm5 = 5;
        for (int i = 1; i < n; i++)
        {
            ugly[i] = min(nm2, min(nm3, nm5));
            if (nm2 == ugly[i])
                nm2 = ugly[++i2] * 2;
            if (nm3 == ugly[i])
                nm3 = ugly[++i3] * 3;
            if (nm5 == ugly[i])
                nm5 = ugly[++i5] * 5;
        }
        return ugly[n - 1];
    }
};