
/*
Source : https://leetcode.com/problems/add-two-numbers/?tab=Description
Author : zhangjf
Date   : 2017/02/19
*/

/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int willadd = 0;
    int val1 = 0, val2 = 0, sum = 0;
    
    struct ListNode *listp = NULL;
    struct ListNode **nodepp = &listp;
    struct ListNode *list1 = l1, *list2 = l2;
  
    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL) {
            val1 = list1->val;
            list1 = list1->next; 
        }
        if (list2 != NULL) {
            val2 = list2->val;
            list2 = list2->next;
        }
      
        sum = willadd + val1 + val2;
        val1 = val2 = 0;
        willadd = sum / 10;

        *nodepp = (struct ListNode *)malloc(sizeof(struct ListNode));
        (*nodepp)->val = sum % 10;
        (*nodepp)->next = NULL;
        nodepp = &((*nodepp)->next);
    }
    
    if (willadd > 0)
    {
        *nodepp = (struct ListNode *)malloc(sizeof(struct ListNode));
        (*nodepp)->val = willadd;
        (*nodepp)->next = NULL;
    }
    
    return listp;
}
