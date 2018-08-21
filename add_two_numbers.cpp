/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include "misc.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        ListNode *p1 = l1, *p2 = l2;
        int carryon = 0;
        while( p1 || p2 || carryon != 0){
            int sum = (p1 != NULL ? p1->val : 0) + (p2 != NULL ? p2->val : 0) + carryon;
            ListNode * node = new ListNode(sum%10);
            carryon = sum/10;
            p->next = node;
            p = node;
            p1 = p1!=NULL?p1->next:NULL;
            p2 = p2!=NULL?p2->next:NULL;
        }
        return head->next;
    }
};

int main(){
    int arr1[] = {5};
    int arr2[] = {5};
    ListNode *l1 = new ListNode(arr1, sizeof(arr1)/sizeof(int));
    ListNode *l2 = new ListNode(arr2, sizeof(arr2)/sizeof(int));
    
    Solution sol;
    ListNode * head = sol.addTwoNumbers(l1, l2);
    head->Print();
    return 0;    
}