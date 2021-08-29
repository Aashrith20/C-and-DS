#include <stdio.h>
#include <limits.h>

int max(int a,int b)
{
    return a>b?a:b;
}

int maxsum_subarray(int arr[], int start,int end)
{
    if(start==end)
    {
        return arr[start];
    }
    int mid = (start+end)/2;
    
    int leftsubarray_max = maxsum_subarray(arr,start,mid);
    int rightsubarray_max = maxsum_subarray(arr,mid+1,end);
	
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int temp_sum = 0;
    for(int i=mid;i>=start;i--)
    {
        temp_sum = temp_sum + arr[i];
        left_sum = max(left_sum,temp_sum);
    }
    temp_sum = 0;
    for(int i=mid+1;i<=end;i++)
    {
        temp_sum = temp_sum + arr[i];
        right_sum = max(right_sum,temp_sum);
    }

    return max(max(leftsubarray_max,rightsubarray_max),left_sum+right_sum);
}

int main()
{
    int arr[] = {-5,-10,6,3,-1,-2,13,4,-9,-1,4,12,-3,0};
    int ans = maxsum_subarray(arr,0,13);
    printf("%d \n",ans);
    return 0;
}
