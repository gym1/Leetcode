int peakIndexInMountainArray(int* A, int ASize) {
    
    // The time complexity id O(logn)
    // For this question it ask to find an index that is the peak in the array
    // For example, [0,2,2,31,1,1,0], output is 3 becasue index 3 is 31, whcih is the peak of the array
    
    // Thus, this question use Binary Search
    // First, determine low and high and mid
    // then find the mid point, 
    // if the mid point's left < mid and mid < mid's right
    // that means the mountain is increasing, thus set low to the mid
    // and re-detemine the mid
    // if the mid point's left > mid and mid > mid's right
    // that means the mountain is decreasing, thus set high to the mid
    // and re-detemine the mid
    // else, it means the mid is the peak or it is flat
    // break the while loop and return mid
    
    int high = ASize -1 ;
    int low = 0;
    int mid;
    
    while (low < high)
    {
        mid = (high + low)/2;
        if (A[mid-1] < A[mid] && A[mid] < A[mid+1])
        {
            low = mid;
        }
        else if (A[mid-1] > A[mid] && A[mid] > A[mid+1])
        {
            high = mid;
        }
        else
        {
            break;
        }
    }
    return mid;
}
