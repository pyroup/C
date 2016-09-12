#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MTX 4

int suji[10][10] ;
int r ; 

void initboard () ;
void output () ;
void move () ;
int decision () ;

int main () {
	int i ;
  int hantei = 0 ;

  srand(time(NULL)) ;
  initboard () ;
  output  () ;
  while (hantei == 0) {
  	move () ;
  	hantei = decision () ;
    //0が代入されたら終了
    if(r == 0) {
    	printf("finish program") ;
      break	;
    }
    output () ;
  }
}

void initboard () {
  int kbox[25] ;  
  int r ;
  int i , j ;

  srand(time(NULL)) ;
  for (i = 0 ; i < MTX ; i++) {
    for (j = 0 ; j < MTX ; j++) {
      do {
        r = rand()%(MTX*MTX-1) + 1 ;
        suji[i][j] = r ;
        if ((i == MTX-1) && (j == MTX-1)) {
          suji[MTX-1][MTX-1] = 0 ;
          break ;
        }
      } while (kbox[r] == 1) ;
      kbox[r] = 1 ;
    } 
  }
}

void output () {
  int i ,j ;

  for(i = 0 ; i < MTX ; i++) {
    for(j = 0 ; j < MTX ; j++) {
      if (j+1 == MTX) {
        if (suji[i][j] == 0) {
          printf("  \n") ;
        }
        else if (suji[i][j] < 10) {
          printf("0%d\n",suji[i][j]) ;
        }
        else {
          printf("%d\n",suji[i][j]) ;
        }
      }
      else {
        if(suji[i][j] == 0) {
          printf("   ") ;
        }
        else if (suji[i][j] < 10) {
          printf("0%d ",suji[i][j]) ;
        }
        else {
          printf("%d ",suji[i][j]) ;
        }
      }
    }
  }
}

void move () {
  static int x = MTX-1 , y = MTX-1 ;
  char s[4] ;

  printf ("Input number which you want to move > ") ;
  fgets(s,4,stdin) ;
  r = atoi(s) ;

  if ( (y-1 > -1) && (suji[x][y-1] == r) ) {
    suji[x][y] = suji [x][y-1] ;
    suji[x][y-1] = 0 ;
    y = y-1 ;
  }
  else if ( (x-1 > -1) && (suji[x-1][y] == r) ) {
    suji[x][y] = suji [x-1][y] ;
    suji[x-1][y] = 0 ;
    x = x-1 ;
  }
  else if ((y+1 < 5) && (suji[x][y+1] == r) ) {
    suji[x][y] = suji [x][y+1] ;
    suji[x][y+1] = 0 ;
    y = y+1 ;
  } 
  else if ((x+1 < 5) && (suji[x+1][y] == r) ) {
    suji[x][y] = suji [x+1][y] ;
    suji[x+1][y] = 0 ;
    x = x + 1 ;
  } 
  else if (r == 0) {}
  else {
  	printf("error!\n") ;
  }
}

int decision () {
	int i , j ; 
	int k = 1 ;

	for (i = 0 ; i < MTX ; i++) {
		for (j = 0 ; j < MTX ; j++) {
			if (suji[i][j] == k) {
				k++;
			}
			else {
				goto finish ; // 二重ループを抜ける
			}
		}	
	}

	finish :
  
  if (k == MTX*MTX) {
  	return 1 ;
  }
  else {
  	return 0 ;
  }
}
