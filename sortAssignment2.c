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
}




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


