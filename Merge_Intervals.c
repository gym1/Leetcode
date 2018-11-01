/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

// The algorithm uses sort and simple comparation.
// First sortting the intervals in an ascending order.
// Second, if the first intervals' item.start > the second intervals' item.end
// That means the intervals are overlapping, then the second interval need to update
// Then, set the second intervals' item.start = the first intervals' item.start
// second intervals' item.end > the fist intervals' item.end
// If they are overlapping, then keep the first intervals' item.start, 
// and find the maximum value between first intervals' item.end and second intervals' item.end
// Since the counter initialize as -1, thus add 1 at the end.

// Time complexity is O(nlogn).
// Space complexity is O(1).

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
int cmp(const void*a,const void*b)
{
    return (*(struct Interval *)a).start -(*(struct Interval *)b).start ;
}


struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    
    if (intervalsSize == 0) {
        return NULL;
    }
        qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    
    //struct Interval *ret = (struct Interval *)malloc(sizeof(struct Interval) * intervalsSize);
    int cur = -1;
    int temp_start = 0;
    int temp_end = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (cur == -1 || intervals[i].start > intervals[cur].end) {
            cur++;
            temp_start = intervals[i].start;
            temp_end = intervals[i].end; // append this interval to result
            intervals[cur].start = temp_start;
            intervals[cur].end = temp_end;
        }

        // merge operation
        // update the last interval in result
        intervals[cur].end = MAX(intervals[i].end, intervals[cur].end);
    }

    *returnSize = cur + 1;
    return intervals;
    
}
