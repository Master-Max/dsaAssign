#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(argc, argv)
int argc;
char **argv;
{

	srand(time(NULL));
	
	if(argc !=2){
		printf("Your Dumb");
		exit(1);
	}

	int n = atoi(argv[1]);

	for(int i = 0; i<n; i++){
		int r = rand() %n+1;
		printf("%d\n",r);
	}
}
