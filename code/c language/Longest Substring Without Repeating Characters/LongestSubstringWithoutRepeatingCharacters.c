/*
    Source:https://leetcode.com/problems/longest-substring-without-repeating-characters/?tab=Description
    Author:zhangjf
    Date  :2017/02/19
*/

/*
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int lengthOfLongestSubstring(char* s) {
    char *end = s, *tmp;
    char *addrtbl[128] = {NULL};
    int len = 0;
    
    while (*end) {
        tmp = addrtbl[*end];
        addrtbl[*end] = end;
        
        if (tmp >= s) {
            len = ((end - s) > len) ? (end - s) : len;
            s = tmp + 1;
        }
        end ++;
    }
    len = ((end - s) > len) ? (end - s) : len;
    
    return len;
}
