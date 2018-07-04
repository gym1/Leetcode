int pivotIndex(int* nums, int numsSize) 
{
    // For this question, the time complexity is O(n)
    // The question is asking to find a index in the array that 
    // the sum of its right elements is eqaul to its sum of left elements
    
    // For example, [2,6,7,7,5,8,2], output is 3, since index 3 's left sum is 15, right sum is 15
    // 
    //
    // Thus, first compute the sum of the array
    // Then, compare the sum of the right sum is equal or not to the left sum
    // the right sum = sum - left sum - the current index value
    // if they are equal, return the current index
    // if not, let the left sum add the current index value
    // then conmtinue to compare untill all the elemrnts finished
    // at the final, if not finding any, return -1
    
    int pivot = 0, i = 0;
    int lsum = 0, sum = 0;

    for(i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    } 
    while (pivot < numsSize)
    {
        if (sum - lsum - nums[pivot] == lsum)
        {
            return pivot;
        }
        else
        {
            lsum += nums[pivot];
            pivot ++;
        }
    }
    return -1;
}
