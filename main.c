
#include "heap.h"

int main(){

  struct binary_heap A;
  int i;

  FILE *f;
  f = fopen("couting.txt", "r");

  fscanf(f, "%d", &A.length);
  new_heap(&A, A.length);

  for(i = 0; i < A.length; i++)
    fscanf(f, "%d", &A.arr[i]);

  heapsort(&A);
  	
  for(i = 0; i < A.length; i++)
  	printf("%d ", A.arr[i]);
  printf("\n");
	
  free(A.arr);

  return 0;
}
