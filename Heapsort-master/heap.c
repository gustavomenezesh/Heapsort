#include "heap.h"

void new_heap(struct binary_heap* A, int length){

    A->arr = (int*)malloc(sizeof(int)*length);
    if(A->arr == 0) printf("Unsuccessfully\n");

}

int father(int i){
    return (int)floor(i/2);
}

int son_left(int i){
    return (int)floor(2*i + 1);
}

int son_right(int i){
    return (int)floor(2*i + 2);
}

void max_heapify(struct binary_heap* A, int i){
    
    int bigger, smaller, aux, l, r;
    l = son_left(i);;
    r = son_right(i);

    if( l <= A->size_heap-1 && A->arr[l] > A->arr[i]){
        bigger = l;
        smaller = i;
    }else
        bigger = i;

    if(r <= A->size_heap-1 && A->arr[r] > A->arr[bigger]){
        smaller = i;
        bigger = r;
    }

    if(bigger != i){
        
        aux = A->arr[bigger];
        A->arr[bigger] = A->arr[smaller];
        A->arr[smaller] = aux;

        max_heapify(A,bigger);
        max_heapify(A,smaller);

    }

}

void build_maxheap(struct binary_heap* A){
	
	int i;
    	A->size_heap = A->length;
	for (i = (int)floor(A->length/2)-1; i >= 0; i--){
		
		max_heapify(A, i);
		
	}
	
}

void heapsort(struct binary_heap* A){

	int i, aux;	
	build_maxheap(A);
	for(i = A->length-1; i > 0; i--){
		
		aux = A->arr[i];
		A->arr[i] = A->arr[0];
		A->arr[0] = aux;
		
		A->size_heap--;
		max_heapify(A, 0);
		
	}
	
}
