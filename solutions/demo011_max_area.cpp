#include <iostream>
#include <vector>
#include <climits>


using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;



class Solution{
    public:
        int maxArea(vector<int> &height){
            //方法1：O(n)
            int area = 0;
            int i = 0;
            int j = height.size()-1;
            while(i < j){
                area = max(area, (j-i)*min(height[i], height[j]));
                if(height[i] < height[j]){
                    ++i;
                }else{
                    --j;
                }
            }
            return area;

            //方法1：二重循环O(n^2)
            /*
            int area = 0;
            for(int i=0;i<height.size();++i){
                for(int j=i+1;j<height.size();++j){
                    int temp = (j-i)*(height[i]<height[j]?height[i]:height[j]);
                    if(temp > area){
                        area = temp;
                    }
                }
            }
            return area;
            */
        }
};


int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution s;
    cout<<s.maxArea(height)<<endl;

    return 0;
}

