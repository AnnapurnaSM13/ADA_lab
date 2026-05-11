#include <stdio.h>
int a[50],b[50];
void mergeSort(int m,int n,int a[],int b[])
{
    int i=0,j=0,k=0,c[50];
    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<m){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<n){
        c[k]=b[j];
        j++;
        k++;
    }
    printf("Merged array:");
    for(int i=0;i<(m+n);i++){
        printf("%d\t",c[i]);
    }
    return ;
}
int main()
{
    int m,n;
    printf("enter the lenght of array 1:");
    scanf("%d",&m);
    printf("enter array 1 elements:");
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the lenght of array 2:");
    scanf("%d",&n);
    printf("enter array 2 elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    mergeSort(m,n,a ,b);
    return 0;
}
