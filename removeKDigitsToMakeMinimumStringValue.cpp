class Solution {
public:
    void buildLowestNumberRec(string str, int n, string &res)
{
    // If there are 0 characters to remove from str,
    // append everything to result
    if (n == 0)
    {
        res.append(str);
        return;
    }
  
    int len = str.length();
    if (len <= n)
        return;
        
    int minIndex = 0;
    for (int i = 1; i<=n ; i++)
        if (str[i] < str[minIndex])
            minIndex = i;
  
    res.push_back(str[minIndex]);
  
    string new_str = str.substr(minIndex+1, len-1);
  
    buildLowestNumberRec(new_str, n-minIndex, res);
}
    string buildLowestNumber(string str, int n)
{
    string res = "";
    buildLowestNumberRec(str, n, res);
    while(res[0]=='0')
    {
        res.erase(res.begin());
    }
    if(res.length()==0)
        return "0";
    return res;
}
    string removeKdigits(string str, int k) {
        return buildLowestNumber(str,k);
    }
};
