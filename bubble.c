#include<stdio.h>
#include<stdlib.h>
void bubble(int *arr,int n){
    int temp=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(arr+j) > *(arr + j+1)){
                //swap elements
                temp=*(arr+j);
                *(arr+j)=*(arr + j+1);
                *(arr + j+1)=temp;
            }
        }
    }
}
int main(){
    int arr[]={10,9,8,1,5,3,6,7,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble(arr,n);
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }
     printf("\n");
}