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
	//printf("sSAsc:\n");
	int u, i, a, m, min, tmp;
	//int *tmp;
	for(i=0; i<n; i++){
		a = d[i];
		min = a;
		//printf("\nsort %d: %d\n", i, a);
		//printf("adress: %d\n", &d[i]);
		for(u=i; u<n; u++){
			if(d[u] < min){
				//printf("new min: %d\n", d[u]);
				m = u;
				min = d[u];
			}
		}
		if(min < d[i]){
			tmp = d[i];
			d[i] = d[m];
			d[m] = tmp;
			//printf("rep d[%i]: %d\n",i,d[i]);
			//printData(d, n);
		}
	}
}

/* FILL ME IN */
insertionSortDescending(d, n)
int *d, n;
{
	int u, i, a, m, max, tmp;
	for(i=0; i<n; i++){
		a = d[i];
		max = a;
		for(u=i; u<n; u++){
			if(d[u] > max){
				m = u;
				max = d[u];
			}
		}
		if(max > d[i]){
			tmp = d[i];
			d[i] = d[m];
			d[m] = tmp;
		}
	}
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
