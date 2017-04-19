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


/* FILL ME IN */
selectionSortAscending(d, n)
int *d, n;
{
	int c = 0;
	int min = 0;
	int tmp = 0;
	int i;
	printf("N:%d\n",n);

	for(i=0; i<n; i++){
		min = d[i];
		for(int l=i;l<n;l++){
			if(d[l]<min)
				min=d[l];
		}
		
	}
}


/*
	if(d[l]<d[c]){
		tmp = d[c];
		d[c] = d[l]
		d[l] = tmp;
		c++;
}*/


/* FILL ME IN */
insertionSortDescending(d, n)
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


	selectionSortAscending(data, n);
	printf("After selection sort\n"); sleep(1);
	printData(data, n);

	insertionSortDescending(data, n);
	printf("After insertion sort\n"); sleep(1);
	printData(data, n);
}


