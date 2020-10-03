//30 jan
// Merge Sort

#include <stdio.h>

void merge_sort(int arr[], int start, int end);
void merge(int arr[], int start, int end);

int main()
{
	int arr[10],i,n,start=0,end;
	
	printf("Enter no of elements : ");
	scanf("%d", &n);
	
	end = n-1;
	
	printf("Enter the values\n");
	for(i=0; i<n; i++)
	     scanf("%d", &arr[i]);
	
	merge_sort(arr, start, end);
	
	printf("The sorted array is \n");
	for(i=0; i<n; i++)
	      printf("%d ", arr[i]);
	
	return 0;
}

void merge_sort(int arr[], int start, int end)
{
	if(start < end)
	{
		int mid = (start+end)/2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid +1, end);
		merge(arr, start , end);
	}
}

void merge(int arr[], int start, int end)
{
	
	int k=0, temp[end-start+1], i=start;
	int mid = (start+end)/2;
	int j = mid+1;
	while(i<=mid && j<=end)
	{
		if(arr[i]<= arr[j])
		{
			temp[k]= arr[i];
			i++;
			k++;
		}
		else
		{
			temp[k]= arr[j];
			j++;
			k++;
		}
	}
	if(i!=mid+1)
	{
		while(i<=mid)
		{
			temp[k]= arr[i];
			i++;
			k++;			
		}
	}
	else if (j!=end+1)
	{
		while(j<=end)
		{
			temp[k]= arr[j];
			j++;
			k++;
		}
	}
	for(i=start ; i<=end; i++)
	{
		arr[i] = temp[i-start];     //for arr ,index can be anything but for temp it is 0,1,...
	}
}
