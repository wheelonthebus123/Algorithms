#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstddef>
#include <stddef.h>
#include <stack>
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