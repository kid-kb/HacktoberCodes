// 23 jan
// Insertion Sort
// kaisa hai bhai, sab theek. Dhyaan rakhi/
#include <stdio.h>

void insertion_sort(int arr[], int n);
int main()
{
	int arr[10],i,n;
	
	printf("Enter no of elements : ");
	scanf("%d", &n);
	
	printf("Enter the values\n");
	for(i=0; i<n; i++)
	     scanf("%d", &arr[i]);
	
	insertion_sort(arr, n);
	
	printf("The sorted array is \n");
	for(i=0; i<n; i++)
	      printf("%d ", arr[i]);
	
	return 0;
}

void insertion_sort(int arr[], int n)
{
	int i,j,element;
	
	for(i=1; i<n; i++)
	{
		element = arr[i];
		j = i-1;
		/* Move elements of arr[0..i-1], that are 
                 greater than key, to one position ahead 
                 of their current position */
		while(element < arr[j] && j>=0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = element;
	}
}
