#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MTX 5

char banmen[6][6] ;
int turn1 ;   
char size1 ; 　//player1がsmallかlargeの判定

void board() ;
int turn() ; 
int move(char piece,char x1,int y1,char x2,int y2) ;

int main () { 
    char s[20] ; //入力の全部を格納
    char piece ;
    char x1,x2 ;
    int y1,y2 ;
    int hantei ; 　//勝負の判定
    
    banmen[0][0] = 'r' ;
    banmen[0][1] = 'b' ;
    banmen[0][2] = 'k' ;
    banmen[0][3] = 'b' ;
    banmen[0][4] = 'r' ;
    banmen[4][0] = 'R' ;
    banmen[4][1] = 'B' ;
    banmen[4][2] = 'K' ;
    banmen[4][3] = 'B' ;
    banmen[4][4] = 'R' ;
    
	board () ;
    
	turn1 = turn() ;

	//turn1=1ならplayer1がsmall
    //turn1=2ならplayer1がlarge
	if (turn1 == 1) {
		size1 = 's' ;
	}
	else {
		size1 = 'l' ;
	}

    while ( hantei != 2 ) {
    	if (turn1 == 1)  {
    	    do {
    		    printf("(player1) Select piece and spot (ex.K (b,2) -> (a,3)) > ") ;
                fgets(s,17,stdin) ;
                if (strlen(s) == 16 && s[15] != '\n') {
                    while (getchar() != '\n') {}
                }
                sscanf(s,"%c (%c,%d) -> (%c,%d)",piece,x1,y1,x2,y2) ;
                hantei = move(piece,x1,y1,y2,y2) ;

                //move関数の返し値（入力が正常かどうか）によって繰り返すか判断
    		    if(hantei == 1) {
    		    	printf("error!") ;
    		    	continue ;
    		    } 
    		    else {
                    turn1++ ;
                    break ;    
    		    }
    	    }
    	} 
    	else if (turn1 == 2) {

        }
    }
}

//盤面を出力する関数
void board () {
	int i = 0 , j = 0 ;
	char s[] = {"abcdefghi"} ;
	
    for(i = 0 ; i < MTX ; i++) {
    	if (i == 0) {
    		printf("    ") ;
    	}
        printf("[%c]",s[i]) ;
    	if (i == MTX-1) {
    		printf("\n\n") ;
    	}
    }

    for(i = 0 ; i < MTX ; i++) {
        for(j = 0 ; j < MTX ; j++) {
        	if(j == 0) {
        		printf("[%d] ",i+1) ;
        	}
        	if(banmen[i][j] == 'R') {
        		printf(" R ") ;
        	}
        	else if(banmen[i][j] == 'B') {
        		printf(" B ") ;
        	}
        	else if(banmen[i][j] == 'K') {
        		printf(" K ") ;
        	}
        	else if(banmen[i][j] == 'r') {
        		printf(" r ") ;
        	}
        	else if(banmen[i][j] == 'b') {
        		printf(" b ") ;
        	}
        	else if(banmen[i][j] == 'k') {
        		printf(" k ") ;
        	}
        	else {
        		printf("    ") ;
         	}
         	if(j == MTX-1) {
         		printf("\n") ;
         	}
        }
    }
}

//順番を決める関数
int turn() {
	char s[10]
    int i ;
  
    while (i == 0) {
        printf("(player1)  Select large or small (Small is first turn)  > ") ;
        fgets(s,6,stdin) ;
        if (strlen(s) == 5 && s[4] != '\n') {
    	    while (getchar() != '\n') {}
        }
        if (strcmp(s,"small") == 0) {
            return 1 ;   
            i = 1 ;
        }
        else if (strcmp(s,"large") == 0) {
            return 2 ;
            i = 1 ;
        }
    }
}

//駒を動かす関数
int move(char piece,char x1,int y1,char x2,int y2 ) {
	int x3,x4 ;

	//値が正常かどうかを判断(最初)
    if (x1 == 'a') {
        x3 = 1 ;
        if(y1 > 5 || y1 < 1) {
        	return 1 ;
        }	
    }
    else if (x1 == 'b') {
        x3 =2 ;
        if(y1 > 5 || y1 < 1) {
        	return 1 ;
        }	
    }
    else if (x1 == 'c') {
    	x3 = 3 ;
        if(y1 > 5 || y1 < 1) {
        	return 1 ;
        }	
    }
    else if (x1 == 'd') {
        x3 = 4 ;
        if(y1 > 5 || y1 < 1) {
        	return 1 ;
        }	
    }
    else if(x1 == 'e') {
        x3 = 5 ;
        if(y1 > 5 || y1 < 1) {
        	return 1 ;
        }	
    }
    else {
    	return 1 ;
    }
    //値が正常かどうかを判断(最後)
    if (x2 == 'a') {
        x4 = 1 ;
        if(y2 > 5 || y2 < 1) {
        	return 1 ;
        }	
    }
    else if (x2 == 'b') {
        x4 =2 ;
        if(y2 > 5 || y2 < 1) {
        	return 1 ;
        }		
    }
    else if (x2 == 'c') {
    	x4 = 3 ;
        if(y2 > 5 || y2 < 1) {
        	return 1 ;
        }	
    }
    else if (x2 == 'd') {
        x4 = 4 ;
        if(y2 > 5 || y2 < 1) {
        	return 1 ;
        }	
    }
    else if(x2 == 'e') {
        x4 = 1 ;
        if(y2 > 5 || y2 < 1) {
        	return 1 ;
        }	
    }
    else {
    	return 1 ;
    }

    //最初に指定した座標と駒が一致するかどうか判断
    if(piece != banmen[x3-1][y1-1]) {
    	return 1 ;
    }
	

    //駒の移動、その移動が可能かどうかを判断
    if (piece == 'R' || piece == 'r') {
　　　　   if( (x4 == x3+2 && y2 == y1) || (x4 == x3-2 && y2 == y1) || (x4 == x3 && y2 == y1+2) || (x4 == x3 && y2 == y1-2) /*縦横２マス移動*/) {
            if (banmen[y2][x4] == 'K' )
            banmen[y2][x4] = piece ;
            banmen[y1][x3] = 0 ;
        }
        else {
        	return 1 ;
        }
    } 	
    else if (piece == 'B' || piece == 'b') {
        if( (x4 == x3+2 && y2 == y1+2) || (x4 == x3+2 && y2 == y1-2) || (x4 == x3-2 && y2 == y1+2) || (x4 == x3-2 && y2 == y1-2) /*斜め２マス移動*/) {
        
        }
        else {
        	return 1 ;
        }
    }
    else if (piece == 'K' || piece == 'k') {
    	if( (x4 == x3+2 && y2 == y1) || (x4 == x3-2 && y2 == y1) || (x4 == x3 && y2 == y1+2) || (x4 == x3 && y2 == y1-2) /*縦横２マス移動*/
    		(x4 == x3+2 && y2 == y1+2) || (x4 == x3+2 && y2 == y1-2) || (x4 == x3-2 && y2 == y1+2) || (x4 == x3-2 && y2 == y1-2) /*斜め２マス移動*/) {
        
        }
        else {
        	return 1 ;
        }
    }
    else {

    }

}
