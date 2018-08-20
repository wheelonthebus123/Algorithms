/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class TwoSum {
public:
    unordered_map<int, int> hash; //value, count
    /** Initialize your data structure here. */
    TwoSum() {}
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        hash[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto h:hash){
            int u = h.first;
            int v = value - u;
            if(u == v && hash[u] > 1){
                return true;
            }else if (u != v && hash.count(v) > 0){
                return true;
            }
        }
        return false;
    }
};

int main(){
    TwoSum ts;
    ts.add(1);
    ts.add(3);
    ts.add(5);
    cout<<ts.find(4)<<endl;
    return 0;
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */