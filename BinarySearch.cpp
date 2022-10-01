#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size,  int ele)
{
    int n = size;
    int s =0;
    int e = n-1;
    int mid;

    while(s<= e)
    {
        mid = s+(e-s)/2;
        if(arr[mid] == ele)
        {
            return mid;
        }
        else if(arr[mid] > ele)
        {
            e = mid -1;
        }
        else{
            s = mid +1 ;
        }
    }
    return -1;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    cout<<binarySearch(arr,5, 4);
    return 0;
}
