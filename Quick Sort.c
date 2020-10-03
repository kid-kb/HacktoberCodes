// 30 Jan 
// Quick Sort

#include <stdio.h>

void qsort(int arr[], int start, int end);
void swap(int *x , int *y);

int main()
{
	int arr[10],i,n,start=0,end;
	
	printf("Enter no of elements : ");
	scanf("%d", &n);
	
	end = n-1;
	
	printf("Enter the values\n");
	for(i=0; i<n; i++)
	     scanf("%d", &arr[i]);
	
	qsort(arr, start, end);
	
	printf("The sorted array is \n");
	for(i=0; i<n; i++)
	      printf("%d ", arr[i]);
	
	return 0;
}

void qsort(int arr[], int start, int end)
{
	if(start < end)
	{
		int pivot = arr[start];
		int i = start ;
		int j = end+1 ;
		
		while (i<j)
		{
			do
			{
				i++;
			}while( arr[i]<pivot && i<end );
			do
			{
				j--;
			}while (arr[j]>pivot );
			if (i<j)
			{
				swap ( arr+i, arr+j);
			}
		}
		swap (arr+start, arr+j);
		qsort(arr, start, j-1);
		qsort(arr, j+1, end);
	}
}

void swap(int *x , int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
