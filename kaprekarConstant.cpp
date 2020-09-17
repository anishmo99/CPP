#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kaprekar(int n)
{
    int counter = 0;
    while (n != 6174)
    {
        counter++;
        int asc = 0, desc = 0;
        vector<int> digits;

        for (int i = 0; i < 4; i++)
        {
            digits.push_back(n % 10);
            n /= 10;
        }

        sort(digits.begin(), digits.end());

        for (int i = 0; i < digits.size(); i++)
        {
            asc = asc * 10 + digits[i];
        }

        sort(digits.begin(), digits.end(), greater<int>());

        bool padding = digits.size() < 4;

        for (int i = 0; i < digits.size(); i++)
        {
            desc = desc * 10 + digits[i];
        }

        if (padding)
            desc *= 10;

        int diff = abs(desc - asc);

        if (diff == 6174)
            return counter;

        n = diff;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    cout << kaprekar(n);
}