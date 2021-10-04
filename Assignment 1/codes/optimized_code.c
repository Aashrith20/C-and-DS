#include <stdio.h>
#include <limits.h>

int max(int a,int b)
{
    return a>b?a:b;
}

int maxsum_subarray(int arr[],int n)
{
    int GlobalMax = INT_MIN;
    int LocalMax = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(LocalMax==INT_MIN)
        {
            LocalMax = arr[i];   
        }
        else
        {
            if(LocalMax<0)
            {
                LocalMax = arr[i];
            }
            else
            {
                LocalMax = LocalMax + arr[i];
            }
            // Deciding whether to continue with previous subarray or to start a new subarray
        }
        GlobalMax = max(GlobalMax,LocalMax); // Updating global_max
    }
    return GlobalMax;
}

int main()
{
    int arr[] = {-5,-10,6,3,-1,-2,13,4,-9,-1,4,12,-3,0};
    int ans = maxsum_subarray(arr,13);
    printf("%d \n",ans);
    return 0;
}