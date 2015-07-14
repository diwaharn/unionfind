/*
 ============================================================================
 Name        : unionfind.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

enum { MAX_ARRAY_SIZE = 10 };
int union_array[MAX_ARRAY_SIZE];

int union_init()
{
	int idx;

	for (idx = 0; idx < MAX_ARRAY_SIZE; idx++){
		union_array[idx] = idx;
	}
}

int union_connect(int p, int q)
{
	/* complex union - N^2, easy find - 1 */
	int qid = union_array[q];
	int pid = union_array[p];
	int idx;

	for (idx = 0; idx < MAX_ARRAY_SIZE; idx++){
		if (union_array[idx] == pid) {
			union_array[idx] = qid;
		}
	}
	union_array[q] = union_array[p];
	return 1;
}

int union_algo2_root(int p)
{
	while (p != union_array[p]){
		p = union_array[p];
	}

	return (p);
}

int union_algo2_connect(int p, int q)
{
	int i = root(p);
	int j = root(q);

	union_array[i] = j;
	return 1;
}

void union_print()
{
	int idx;
	printf ("Union Array: ");
	for (idx = 0; idx < MAX_ARRAY_SIZE; idx++){
		printf (" %d ", union_array[idx]);
	}
	printf ("\n");
}

int main(void) {

	union_init();

	union_connect(4, 3); union_print();
	union_connect(3, 8); union_print();
	union_connect(6, 5); union_print();
	union_connect(9, 4); union_print();
	union_connect(2, 1); union_print();
	union_connect(8, 9); union_print();
	union_connect(5, 0); union_print();
	union_connect(7, 2); union_print();
	union_connect(6, 1); union_print();
	union_connect(1, 0); union_print();
	union_connect(6, 7); union_print();

	return EXIT_SUCCESS;
}
