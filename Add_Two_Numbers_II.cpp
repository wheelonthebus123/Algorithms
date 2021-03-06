/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "misc.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode * prev = NULL;
        
        while(l1 != NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carryon = 0;
        while(!s1.empty() || !s2.empty() || carryon != 0){
            int sum = carryon + (s1.empty()?0:s1.top()) + (s2.empty()?0:s2.top());
            if (!s1.empty()) 
                s1.pop();
            if(!s2.empty())                
                s2.pop();

            ListNode *node = new ListNode(sum%10);   
            node ->next = prev;
            prev = node;      
            carryon = sum/10;
        }

        return prev;
    }
};

int main (){
    int arr1[] = {3,4,2,7};
    int arr2[] = {4,6,5};
    ListNode *l1 = new ListNode(arr1, sizeof(arr1)/sizeof(int));
    ListNode *l2 = new ListNode(arr2, sizeof(arr2)/sizeof(int));
    
    Solution sol;
    ListNode *ret = sol.addTwoNumbers(l1, l2);
    ret->Print();
    return 0;
}