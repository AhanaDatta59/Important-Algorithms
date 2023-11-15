#include<stdio.h>
#include<stdlib.h>
void insertion(int *arr,int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j] > key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[]={10,9,8,1,5,3,6,7,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion(arr,n);
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }
     printf("\n");
}