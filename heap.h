
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct binary_heap{
    int size_heap;
    int length;
    int* arr;
};

void new_heap(struct binary_heap* A, int length);

int father(int i);

int son_left(int i);

int son_right(int i);

void max_heapify(struct binary_heap* A, int i);

void build_maxheap(struct binary_heap* A);

void heapsort(struct binary_heap* A);
