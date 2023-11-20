// // Heap Sort in C

// #include <stdio.h>
// void swap(int* a, int* b)
// {

// 	int temp = *a;
// 	*a = *b;
// 	*b = temp;
// }
// void heapify(int arr[], int N, int i)
// {
// 	// Find largest among root,
// 	// left child and right child

// 	// Initialize largest as root
// 	int largest = i;

// 	// left = 2*i + 1
// 	int left = 2 * i + 1;

// 	// right = 2*i + 2
// 	int right = 2 * i + 2;

// 	// If left child is larger than root
// 	if (left < N && arr[left] > arr[largest])

// 		largest = left;

// 	// If right child is larger than largest
// 	// so far
// 	if (right < N && arr[right] > arr[largest])

// 		largest = right;

// 	// Swap and continue heapifying
// 	// if root is not largest
// 	// If largest is not root
// 	if (largest != i) {

// 		swap(&arr[i], &arr[largest]);

// 		// Recursively heapify the affected
// 		// sub-tree
// 		heapify(arr, N, largest);
// 	}
// }

// // Main function to do heap sort
// void heapSort(int *arr, int N)
// {

// 	// Build max heap
// 	for (int i = N / 2 - 1; i >= 0; i--)

// 		heapify(arr, N, i);

// 	// Heap sort
// 	for (int i = N - 1; i >= 0; i--) {

// 		swap(&arr[0], &arr[i]);

// 		// Heapify root element
// 		// to get highest element at
// 		// root again
// 		heapify(arr, i, 0);
// 	}
// }

// // A utility function to print array of size n
// void printArray(int *arr, int N)
// {
// 	for (int i = 0; i < N; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }
// // Driver's code
// int main()
// {
// 	int arr[] = { 12, 11, 15, 5, 6, 7 };
// 	int N = sizeof(arr) / sizeof(arr[0]);

// 	// Function call
// 	heapSort(arr, N);
// 	printf("Sorted array is\n");
// 	printArray(arr, N);

// }

#include <stdio.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int arr[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n&&arr[left]>arr[largest])
	largest=left;
	if(right<n&&arr[right]>arr[largest])
	largest=right;

	if(largest!=i){
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}
void heapSort(int arr[],int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}
void printArray(int *arr, int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 12, 11, 15, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);

}
