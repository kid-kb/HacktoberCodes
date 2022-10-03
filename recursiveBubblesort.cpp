
#include <bits/stdc++.h>
using namespace std;

void RecursiveBubbleSort(int arr[], int n)
{
	if (n == 1)
		return;

	int count = 0;
	for (int i=0; i<n-1; i++)
		if (arr[i] > arr[i+1]){
			swap(arr[i], arr[i+1]);
			count++;
		}

	
	if (count==0)
		return;

	
	RecursiveBubbleSort(arr, n-1);
}

void printArray(int arr[], int n)
{
	for (int i=0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	
    int n;
    cout<<"Enter size of array  ";
    cin>>n;
    int arr[n];
	 cout<<"Enter the array  ";
    for(int i=0 ; i<n ; i++)
    {cin>>arr[i];}
	
	RecursiveBubbleSort(arr, n);
	printf("Sorted array : \n");
	printArray(arr, n);
	return 0;
}

