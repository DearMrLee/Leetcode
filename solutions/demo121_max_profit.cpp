#include <iostream>
#include <vector>
#include <climits>

using std::endl;
using std::cout;
using std::vector;


class Solution{
    public:
    int maxProfit(vector<int> &prices){
        int min_price = INT_MAX;
        int maxProfit = 0;
        for(int i=0;i<prices.size();++i){
            if(prices[i] < min_price){
                min_price = prices[i];
            }else {
                if(prices[i] - min_price > maxProfit){
                    maxProfit = prices[i] - min_price;
                } 
            }
        }
        return maxProfit;


    }
};


int main(){
    
    //vector<int> v = {7,1,5,3,6,4};
    vector<int> v = {7,6,5,4,3,2,1};
    Solution s;
    cout<<s.maxProfit(v)<<endl;

    return 0;
}
