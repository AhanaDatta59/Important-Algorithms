#include<stdio.h>
#include<stdlib.h>

int binary(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binary(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binary(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int main() {
    int arr[] = {10, 9, 8, 1, 5, 3, 6, 7, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);

    int i = binary(arr, 0, n-1, ele);
    if (i != -1)
        printf("%d found at index %d", ele, i);
    else
        printf("%d not found in array");

    return 0;
}
