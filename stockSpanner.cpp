class StockSpanner {
public:
    StockSpanner() {
    }
    stack<int> prices;
    stack<int> weights;
    int next(int price) {
        int w=1;
        while(!prices.empty()&&prices.top()<=price)
        {
            prices.pop();
            w+=weights.top();
            weights.pop();
        }
        prices.push(price);
        weights.push(w);
        return w;
    }
};

/*
 //geeksforgeeks
 #include <iostream>
 #include <stack>
 #include <vector>
 using namespace std;

 int main() {
     int cases;
     cin>>cases;
     while(cases--)
     {
         int n;
         cin>>n;
         int x;
         vector<int> output;
         stack<int> prices;
         stack<int> weights;

         for(int i=0;i<n;i++)
         {
             cin>>x;
             int w=1;
             while(!prices.empty()&&prices.top()<=x)
             {
                 prices.pop();
                 w+=weights.top();
                 weights.pop();
             }
             prices.push(x);
             weights.push(w);
             output.push_back(w);
         }
         for(auto& i:output)
             cout<<i<<" ";
         cout<<endl;
     }
     return 0;
 }
 */
