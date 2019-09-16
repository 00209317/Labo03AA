#include "stdio.h"
#include "stdlib.h"

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}


void MaxHeapify(int A[], int i, int size){
    int l, r, largest, temp;
    l = left(i);
    r = right(i);
    if( (l<=size) && (A[l]>A[i]) ){
        largest = l;
    }else{
        largest = i;
    }
    if( (r<=size) && (A[r]>A[largest]) ){
        largest = r;
    }
    if(largest!=i){
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MaxHeapify(A, largest, size);
    }
}

void BuildMaxHeap(int A[], int size){
    for(int i=size/2; i>=0; i--){
        MaxHeapify(A, i, size);
    }
}


void printArray(int A[], int size){
    for(int i=0; i<size; i++){
        printf("%d", A[i]);
        printf(" ");
    }
}

int main(void){
    int A[7] = {7,6,5,4,3,2,1}, temp=0;
    int B[6] = {1, 3, 3, 3, 6, 8};
    int size = sizeof(A)/sizeof(A[0]);
    BuildMaxHeap(A, size);
    for(int i=size; i>=1; i--){
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        size--;
        MaxHeapify(A, 0, size);
    }

    
    printArray(A, 7);
    printf("\n ");
    printf("%d", A[6]);
    printf("\n ");
    printf("\n ");
    if(A[6]%2==0){
        printf("%d", A[6]+2);
    }else{
        printf("%d", A[6]+1);
    }


    return 0;
}