#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


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
	//printf("heapSort\n");
	int top,i,tmp;
	int *heap;
	heap = calloc(n, sizeof(int));

	for(i=0;i<n;i++){
		heapify(d,(n-i));
		//printf("d[0]:%d\n", d[0]);
		heap[i] = d[0];
		//printf("d[n]:%d\n", d[n-(i+1)]);
		//d[0] = d[n-(i+1)];
		//d[n-(i+1)] = INT_MAX;
		d[0] = d[n-(i+1)];
		memcpy(d, d, (n-1)*sizeof(int));

		//n--;//THIS MIGHT F IT UP
	}

	for(i=0;i<n;i++){
		d[i]=heap[i];
	}
	//printData(heap,n);
	//d = heap;
}

heapify(d, n)
int *d, n;
{
	//printf("heapify\n");
	int tmp, min, a, i;
	min = d[0];
	for(i=0;i<n;i++){
		//printf(".");
		if(min>d[i]){
			min=d[i];
			a=i;
		}
	}
	if(min<d[0]){
		d[a]=d[0];
		d[0]=min;
	}
	//printf("\n");
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
