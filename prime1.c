#include<stdio.h>
#include<math.h>
// int prime(int n){
//     int c=0;
//     for(int i=1;i<=n;i++){
//         if(n%i==0)c++;
//     }
//     return (c==2)?1:0;
// }

// int prime(int n){
//     int c=0;
//     for(int i=2;i<(int)sqrt(n);i++){
//         if(n%i==0)return 0;
//     }
//     return 1;
// }

int prime(int n){
    int c=0;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)c++;
    }
    if(c==0)
    return 1;
    else
    return 0;
}
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int b=prime(n);
    if(b==1)
    printf("%d is a Prime Number",n);
    else
    printf("%d is not a Prime Number",n);
}