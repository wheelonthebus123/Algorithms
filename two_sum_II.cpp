
/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

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