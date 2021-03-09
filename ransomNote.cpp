bool canConstruct(string s2, string s1) {
    int count[26]={0};
    for(int i=0;i<s1.length();i++)
    {
        count[s1[i]-'a']++;
    }
    for(int i=0;i<s2.length();i++)
    {
        if(count[s2[i]-'a']==0)
            return false;
        count[s2[i]-'a']--;
    }
    return true;
}

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> rans, mag;

        for (char c : magazine)
            mag[c]++;

        for (char c : ransomNote)
        {
            if (mag.find(c) != mag.end())
            {
                mag[c]--;

                if (mag[c] == 0)
                    mag.erase(c);
            }

            else
                return false;
        }

        return true;
    }
};