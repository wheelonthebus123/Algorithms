#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret(2, 0);
        int size = numbers.size();
        int l = 0, r = size - 1;        
        while(l < r){
            int sum = numbers[l] + numbers[r];
            if (sum == target){
                ret[0] = l + 1;
                ret[1] = r + 1;
                return ret;
            }else if(sum < target){
                l++;
            }else{
                r--;
            }
        }
        return ret;
    }
};

int main(){
    int arr[] = {1,2,3,4};
    vector<int> test(arr, arr + sizeof(arr)/sizeof(int));
    Solution sol;
    vector<int> ret = sol.twoSum(test, 5);
    cout<<ret[0]<<" "<<ret[1]<<endl;
    return 0;    
}