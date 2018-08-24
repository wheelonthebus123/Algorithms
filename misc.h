#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstddef>
#include <stddef.h>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}    

    //initiate a list of nodes in reverse order
    //eg., 342: 2->4->3
    ListNode(int arr[], int size){
        ListNode *prev = NULL;
        for(int i=0; i<size; ++i){
            ListNode *node = new ListNode(arr[i]);
            node ->next = prev;
            prev = node;
        }
        val = prev->val;
        next = prev->next;
    }

    void Print(){
        ListNode *p = this;
        while(p != NULL){
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
    }
};

vector<string> mysplit(string input, string d)
{
    vector<string> vec;
    string currentstr = input;
    while(true){
        size_t p = currentstr.find_first_of(d);
        if(p!=string::npos){  
            vec.push_back(currentstr.substr(0, p));           
            currentstr = currentstr.substr(p+1, string::npos);
        }else{
            vec.push_back(currentstr);
            break;
        }
    } 
    return vec;
}

template <typename T>
void printVector(vector<T> vec){
    for (typename vector<T>::iterator it = vec.begin() ; it != vec.end(); ++it){
        cout<<*it<<endl;
    }
}