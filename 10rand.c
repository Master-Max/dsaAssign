#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

	srand(time(NULL));
	
	for(int i = 0; i<10; i++){
		int r = rand() %101;
		printf("%d\n",r);
	}
}
