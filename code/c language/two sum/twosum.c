/*
Source : https://leetcode.com/problems/add-two-numbers/
Author : zhangjf
Date   : 2017/01/03
*/

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully. 
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *retarr = NULL;
    
    retarr = malloc(2*sizeof(int));
    if (retarr == NULL)
        return NULL;
    
    /* Init retarr mems to -1 */
    retarr[0] = retarr[1] = -1;
        
    for (i = 0; i < numsSize; i++)
        for (j = i + 1; j < numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                retarr[0] = i;
                retarr[1] = j;
                return retarr;
            }
        }
    
    return retarr;
}
