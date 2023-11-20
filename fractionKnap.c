#include<stdio.h>
#include<stdlib.h>
void printarr(float *arr,int n){
    int i;
    for (i=0;i<n;i++){
        printf("%lf      ",arr[i]);
    }
    printf("\n");
}
void printarrc(char *arr,int n){
    int i;
    for (i=0;i<n;i++){
        printf("%c\t        ",arr[i]);
    }
    printf("\n");
}
void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    char items[]={'1','2','3','4','5'};
    float weights[]={3,3,2,5,3};
    float profits[]={10,13,12,20,17};
    float ratio[5];
    for(int i=0;i<5;i++) {
        ratio[i]=profits[i]/weights[i];
    }
    //printarr(ratio,5);
    for(int i=0;i<5-1;i++){
        for(int j=0;j<5-i-1;j++){
            if(ratio[j+1]>ratio[j])
            {
                swap(&ratio[j],&ratio[j+1]);
                
                char temp=items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
                
                swap(&weights[j],&weights[j+1]);
                swap(&profits[j],&profits[j+1]);
            }
        }
    }
    printarrc(items,5);
    printarr(weights,5);
    printarr(profits,5);
    printarr(ratio,5);

    int cap=10;//knapsack capacity
    float knap[5];
    //initialize with 0s
    
    for(int i=0;i<5;i++)
    knap[i]=0.0;
    //fill the array
    for(int i=0;i<5;i++){
        if(weights[i]<cap)
        {
            knap[i]=1.0;
            cap=cap-weights[i];
        }
        else{
            knap[i]=(cap)/weights[i];
            break;
        }
    }
   printarr(knap,5);
   //calculating profit
   double p=1;
   for(int i=0;i<5;i++)
   p+=profits[i]*knap[i];
   printf("Profit is %f",p);
}