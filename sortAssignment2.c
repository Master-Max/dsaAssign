#include <stdio.h>
#include <string.h>
#include <stdlib.h>


printData(d,n)
int *d,n;
{
	int i;
	for (i=0; i<n; i++)
		printf("data[%d] = %d\n", i, d[i]);
}


/* IMPLEMENT (only) one of your choosing */
quickSort(d, n)
int *d, n;
{
}

mergeSort(d, n)
int *d, n;
{
}

heapSort(d, n)
int *d, n;
{
	int top,i,tmp;
	int *heap;
	heap = calloc(n, sizeof(n));

	heap = d;

	for(i=0;i<n;i++){
		heap[i] = d[0];
		heapify(d,n);
	}
}

heapify(d, n)
int *d, n;
{
	for(int i=0;i<n;i++){
		if(d[i]<d[0]){
			tmp = d[0];
			d[i] = d[0];
			d[i] = tmp;
	}
}

//THIS ISNT A HEAP, need to replace
//top with last in


main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	char buf[1024];
	int n, *data, i;
	if (argc !=2 ) {
		printf("usage: sortAssignment1 #elements\n");
		exit(1);
	}

	n = atoi(argv[1]);
	data = calloc(n, sizeof(int));
	for (i=0; i<n; i++) {
		gets(buf);
		data[i] = atoi(buf);
	}


	printf("unsorted data:\n"); sleep(1);
	printData(data, n);


	heapSort(data, n);
	quickSort(data, n);
	mergeSort(data, n);
	printf("After sort\n");
	printData(data, n);
}
