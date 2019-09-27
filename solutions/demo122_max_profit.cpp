#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


class Solution{
    public:
        int MaxProfit(vector<int> &prices){
            //方法2：只要后面的比前面的大就加
            int max_profit = 0;
            for(int i=1;i<prices.size();i++){
                if(prices[i] > prices[i-1]){
                    max_profit += prices[i] - prices[i-1];
                }
            }
            return max_profit;


            //方法1：不够简洁
            /*
            if(prices.empty()){
                return 0;
            }
            int max_profit = 0;
            int buy_pos = 0;
            int i;
            for(i=0;i<prices.size()-1;++i){
                if(prices[i] < prices[i+1]){
                    continue;
                }else{
                    max_profit += prices[i] - prices[buy_pos];
                    buy_pos = i+1;
                }
            }
            max_profit += prices[i] - prices[buy_pos];
            return max_profit;
            */
        }

};


int main(){
    vector<int> v = {7,1,5,3,6,4};
    //vector<int> v = {1,2,3,4,5,6,7};

    Solution s;
    cout<<s.MaxProfit(v)<<endl;

    return 0;
}
