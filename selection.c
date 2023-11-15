#include<stdio.h>
#include<stdlib.h>
// void selection(int *arr,int n){
//     int min;
//     for(int i=0;i<n-1;i++){
//         min=i;
//         for(int j=i+1;j<n;j++){
//             if(*(arr+j)<*(arr+min))
//             min=j;

//             if(min!=i)
//             {
//                 int temp = *(arr+min);
//                 *(arr + min)= *(arr + i);
//                 *(arr + i) =temp ;
//             }
//         }
//     }
// }
void selection(int arr[], int n)
{
    int i, j, min;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min])
            min = j;
 
        // Swap the found minimum element with the first element
           if(min != i)
            {
                int temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
    }
}
int main(){
    int arr[]={10,9,8,1,5,3,6,7,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }
     printf("\n");
}