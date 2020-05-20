//
//  countAndSay.cpp
//  C++
//
//  Created by Anish Mookherjee on 28/03/20.
//  Copyright © 2020 Anish Mookherjee. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

string countAndSay(int n) {
    n = n-1;
    vector<vector<int>> res(30);    //2D vector to store the series
    res[0].push_back(1);            //1st element
    int freq = 0;                   //Freq stores the count of the number being considered
    int num = 0;                    //num stores the value of the number being considered
    int i = 0;                      //eg. 1211 -> when num = 2 freq = 1
    while(i<29)
    {
        num = res[i][0];            //store the first digit of the nth element of the series
        for(int j=0;j<res[i].size();j++)
        {
            if(num!=res[i][j])      //Now check if the next digit is same as the one in cosideration.
            {
                if(freq==0) freq = 1;       //If this is the first digit then freq = 1
                res[i+1].push_back(freq);   //Then push the frequency and the number into the vector
                res[i+1].push_back(num);
                num = res[i][j];            //Then set the new digit as num and its freq as 1
                freq = 1;
            }
            else
            {
                freq++;                //if its not a new digit, keep counting its frequency
            }
        }
        res[i+1].push_back(freq);       //Push the last element into the vector
        res[i+1].push_back(num);
        i++;
        freq = 0;
    }
    string ans;
    for(int j=0;j<res[n].size();j++)     //converting integer to string as the return type is string
    {
        ans.push_back(res[n][j]+'0');
    }
    return ans;
}
