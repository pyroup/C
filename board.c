#include <stdio.h>
#define MTX 5
int kbox[5][5] ;

int main() {
	int i,j ;
    char moji[8] = {'a','b','c','d','e','f','g'} ;
    
    printf("    ")  ;
	for(i = 0 ; i < MTX ; i++) {
	    printf("[%c] ",moji[i]) ; 
	    if(i == MTX - 1) {
	    	printf("\n") ;
	    }  
	}

	for (i = 0 ; i < MTX ; i++) {
		printf("[%d] ",i+1) ;
		for (j = 0 ; j < MTX ; j++) {
			if(kbox[i][j] == 0 ) {
				printf("   ") ;
			}
			else if(kbox[i][j] == 1) {
				printf(" 0  ") ;
			}
			else if(kbox[i][j] == 2) {
				printf(" 1  ") ;
			}
		    if (j == MTX-1) {
		    	printf("\n") ;
		    }
		}
	}
}