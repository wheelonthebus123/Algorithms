/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret(2, 0);
        unordered_map<int, int> hash;//<value, index>
        int size = nums.size();
        for(int i=0; i<size; ++i){
            int u = nums[i];
            int v = target - u;
            if (hash.find(v) != hash.end()){
                ret[0] = i;
                ret[1] = hash[v];
                return ret;
            }else{
                hash[u] = i;
            }
        }
        return ret;
    }
};

int main()
{
    int arr[] = {1,2,3,4};
    vector<int> test(arr, arr + sizeof(arr)/sizeof(int));

    Solution solu;
    vector<int> ret = solu.twoSum(test, 4);
    cout << ret[0] << " " << ret[1] << endl;
    return 0;
}