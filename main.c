#include <string.h>
#include "heap.h"

int main(int argc, char* argv[]){

  struct binary_heap A;
  int i;
  char diretory[40] = "instancias-num/";
  strcat(diretory, argv[1]);	

  printf("%s\n", diretory);
  FILE *f;
  f = fopen(diretory, "r");

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
