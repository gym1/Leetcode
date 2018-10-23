/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

// Thus, we start with a struct with intervals' start and end
// The algorithm is comparing the start value of the 2nd interval with end value of 1st interval
// if end value is greater than than the start value, taking the count
// then further comparing end value of 2nd interval with end value of 1st interval
// if 1st is greater than the 2nd one, go to next interation
// else go to next interation

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
//
//
// First Approach
//
//
// Inorder to have a sorted intervals array, we need to write a swap function for swaping two intervals
// then write a quick sort using swap function
void swap(int *r1,int *r2){
    int temp;
    temp=*r1;
    *r1=*r2;
    *r2=temp;
}
void quickSort(struct Interval *nums,int l,int r){
    int i,j;
    if(l<r){
        i=l;
        j=r+1;
        while(1){
            do i++;
            while(!(nums[l].start<=nums[i].start||i==r));
            do j--;
            while(!(nums[l].start>=nums[j].start||j==l));
            if(i<j)
            {
                swap(&nums[i].start,&nums[j].start);
                swap(&nums[i].end,&nums[j].end);
                printf("#%d,%d\n",i,j);
            }
                
            else
                break;
        }
        swap(&nums[l].start,&nums[j].start);
        swap(&nums[l].end,&nums[j].end);
        printf("$%d,%d\n",i,j);
        
        quickSort(nums,l,j-1);
        quickSort(nums,j+1,r);
    }
}

int eraseOverlapIntervals(struct Interval* intervals, int intervalsSize) {
    if (intervalsSize <= 1)
    {
        return 0;
    }
    quickSort(intervals, 0, intervalsSize-1);
    int j = 0;
    int count = 0;
    for (int i = 1; i < intervalsSize; i++)
    {
        printf("%d %d\n", intervals[i-1].start, i-1);
        if (intervals[i].start < intervals[j].end)
        {        
            count ++;
            if (intervals[i].end < intervals[j].end)
            {
                j = i;
            }
        }
        else
        {
            j = i;
        }
    }
    return count;
}
//
//
// Second Approach
//
//

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
int cmp(const void*a,const void*b)
{
    return (*(struct Interval *)a).end -(*(struct Interval *)b).end ;
}

int eraseOverlapIntervals(struct Interval* intervals, int intervalsSize) 
{
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    int first = 0;
    int count = 0;
    for (int second = first + 1; second < intervalsSize; second ++)
    {
        if (intervals[second].start < intervals[first].end)
        {
            count ++;
        }
        else
        {
            first = second;
        }
    }
    return count;
}
