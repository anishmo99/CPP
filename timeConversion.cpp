# include <iostream>
using namespace std;

int main()
{
   
   string s;
   cin>>s;
   
   int h=(((int(s[0]))-48)*10)+(int(s[1])-48);
   int m=(((int(s[3]))-48)*10)+(int(s[4])-48);
   int ss=(((int(s[6]))-48)*10)+(int(s[7])-48);
   char f=s[8];
   if(f=='P' && h!=12)
        h+=12;
   if(f=='A' && h==12)
        h=0;
    printf("%02d:%02d:%02d",h,m,ss);

  
    return 0;
}