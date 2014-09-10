// CConsoleApplicationMemoryHeap.c: Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int stack = 7;
	int anotherStack = 7;
	int yetAnotherStack = 7;

	int * heap = malloc(sizeof(int));
	*heap = 42;
	int * anotherHeap = malloc(sizeof(int));
	*anotherHeap = 42;
	int *sameHeap = heap;

	printf("stack=%i\n", stack);
	printf("address of stack=%i\n", &stack);
	printf("anotherStack=%i\n", anotherStack);
	printf("address of anotherStack=%i\n", &anotherStack);
	printf("yetAnotherStack=%i\n", yetAnotherStack);
	printf("address of yetAnotherStack=%i\n", &yetAnotherStack);

	printf("heap=%i\n", *heap);
	printf("address of heap=%i\n", heap);
	printf("anotherHeap=%i\n", *anotherHeap);
	printf("address of anotherHeap=%i\n", anotherHeap);
	printf("sameHeap=%i\n", *sameHeap);
	printf("address of sameHeap=%i\n", sameHeap);

	getchar();				//wait for keypress

	free(heap);
	free(anotherHeap);

	printf("heap=%i\n", *heap);
	printf("address of heap=%i\n", heap);
	printf("anotherHeap=%i\n", *anotherHeap);
	printf("address of anotherHeap=%i\n", anotherHeap);
	printf("sameHeap=%i\n", *sameHeap);
	printf("address of sameHeap=%i\n", sameHeap);

	getchar();				//wait for keypress

	*heap = NULL;

	printf("heap=%i\n", *heap);
	printf("address of heap=%i\n", heap);
	printf("anotherHeap=%i\n", *anotherHeap);
	printf("address of anotherHeap=%i\n", anotherHeap);
	printf("sameHeap=%i\n", *sameHeap);
	printf("address of sameHeap=%i\n", sameHeap);

	getchar();				//wait for keypress


	return 0;

}
