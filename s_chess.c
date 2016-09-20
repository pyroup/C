#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MTX 5

char banmen[6][6] ;

void board() ;
int turn() ; 
int move(char piece,char x1,int y1,char x2,int y2) ;

int main () { 
    char s[20] ; //入力の全部(一行分)を格納
    char piece ; //動かす駒を格納
    char x1,x2 ; //x1が動かす前の、x2が動かした後のx座標
    int y1,y2 ;  //y1が動かす前の、y2が動かした後のy座標
    int hantei = 3; //勝負の判定
    int turn1 ;
    int size1 ; //player1の駒がどちらか

    //初期化
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
    size1 = turn1 ;  //1ならsmall、2ならlarge

    //hantei = 1　のとき、入力を再度行う。
    //hantei = 2 のとき、プログラムを終了する。
    //hantei = 3 のとき、繰り返し処理
    //hantei = 4 のとき、smallが勝利
    //hantei = 5　のとき、largeが勝利
    while (hantei == 3) {
    	if (turn1 == 1)  {
    	    while(1) {
    		    printf("(player1) Select piece and spot (ex.K (b,2) -> (a,3)) > ") ;
                fgets(s,17,stdin) ;
                if (strlen(s) == 16 && s[15] != '\n') {
                    while (getchar() != '\n') {}
                }
                //finと入力するとプログラムが終了する
                if(strcmp(s,"fin\n") == 0) {
                	hantei = 2 ;
                	break ;
                }
                sscanf(s,"%c %c %d %c %d",&piece,&x1,&y1,&x2,&y2) ;

                hantei = move(piece,x1,y1,x2,y2) ;

                //move関数の返し値（入力が正常かどうか）によって繰り返すか判断
    		    if(hantei == 1) {
    		    	printf("error!\n") ;
    		    	continue ;
    		    } 
    		    else {
                    turn1++ ;
                    break ;    
    		    } 
    	    }
    	}
    	else if (turn1 == 2) {
    		while(1) {
    		    printf("(player2) Select piece and spot (ex.K (b,2) -> (a,3)) > ") ;
                fgets(s,17,stdin) ;
                if (strlen(s) == 16 && s[15] != '\n') {
                    while (getchar() != '\n') {}
                }
                //finと入力するとプログラムが終了する
                if(strcmp(s,"fin\n") == 0) {
                	hantei = 2 ;
                	break ;
                }
                sscanf(s,"%c %c %d %c %d",&piece,&x1,&y1,&x2,&y2) ;
                
                hantei = move(piece,x1,y1,x2,y2) ;

                //move関数の返し値（入力が正常かどうか）によって繰り返すか判断
    		    if(hantei == 1) {
    		    	printf("error!\n") ;
    		    	continue ;
    		    } 
    		    else {
                    turn1-- ;
                    break ;    
    		    }
    	    } 
        }
        else {
        	hantei = 2 ;
        }

        board () ;
    }

    if (hantei == 2) {
        printf("finish the program") ;
    }
    //smallが勝利の場合
    else if (hantei == 4) {
    	if(size1 == 1) {
    		printf("player1 won the game!") ;
    	}
    	else {
    	    printf("player2 won the game!") ;
    	}
    }
    //largeが勝利の場合
    else if (hantei == 5) {
    	if(size1 == 1) {
    	    printf("player2 won the game!") ;
    	}
    	else {
    		printf("player1 won the game!") ;
    	}
    }

    return 0 ;
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
    		printf("\n") ;
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
        		printf(" - ") ;
         	}
         	if(j == MTX-1) {
         		printf("\n") ;
         	}
        }
    }
}

//順番を決める関数
int turn() {
	char s[10] ;
  
    while(1) {
        printf("(player1)  Select large or small (Small is first turn)  > ") ;
        fgets(s,6,stdin) ;
        if (strlen(s) == 5 && s[4] != '\n') {
    	    while (getchar() != '\n') {}
        }
        //finと入力するとプログラムが終了する
        if(strcmp(s,"fin\n") == 0) {
            return 3 ;
        }
        if (strcmp(s,"small") == 0) {
            return 1 ;   
        }
        else if (strcmp(s,"large") == 0) {
            return 2 ;
        }
    } 
}

//駒を動かす関数
int move(char piece,char x1,int y1,char x2,int y2 ) {
	int x3,x4 ; //x1,x2を数字に変換するための変数
	static int count ; //smallかlargeどちらをうごかすか判断するための変数

	//値が正常かどうかを判断(最初)
    if (x1 == 'a') {
        if(y1 >= 1 && y1 <= 5) {
        	x3 = 1 ; 
        }	
        else {
            return 1 ;	
        }	
    }
    else if (x1 == 'b') {
        if(y1 >= 1 && y1 <= 5) {
        	x3 = 2 ; 
        }	
        else {
            return 1 ;	
        }	
    }
    else if (x1 == 'c') {
        if(y1 >= 1 && y1 <= 5) {
        	x3 = 3 ; 
        }	
        else {
            return 1 ;	
        }	
    }
    else if (x1 == 'd') {
        if(y1 >= 1 && y1 <= 5) {
        	x3 = 4 ; 
        }	
        else {
            return 1 ;	
        }	
    }
    else if(x1 == 'e') {
        if(y1 >= 1 && y1 <= 5) {
        	x3 = 5 ; 
        }	
        else {
            return 1 ;	
        }	
    }
    else {
    	return 1 ;
    }

    //値が正常かどうかを判断(最後)
    if (x2 == 'a') {
        if(y1 >= 1 && y1 <= 5) {
        	x4 = 1 ; 
        }	
        else {
            return 1 ;	
        }	
    }
    else if (x2 == 'b') {  
        if(y1 >= 1 && y1 <= 5) {
        	x4 = 2 ; 
        }	
        else {
            return 1 ;	
        }		
    }
    else if (x2 == 'c') {
        if(y1 >= 1 && y1 <= 5) {
        	x4 = 3 ; 
        }	
        else {
            return 1 ;	
        }		
    }
    else if (x2 == 'd') {
        if(y1 >= 1 && y1 <= 5) {
        	x4 = 4 ; 
        }	
        else {
            return 1 ;	
        }		
    }
    else if(x2 == 'e') {
        if(y1 >= 1 && y1 <= 5) {
        	x4 = 5 ; 
        }	
        else {
            return 1 ;	
        }	
    }
    else {
    	return 1 ;
    }

    //最初に指定した座標と駒が一致するかどうか判断
    if(piece != banmen[y1-1][x3-1] ) {
    	return 1 ;
    }

    //自分の駒かどうかの判断
    if ( piece  != 'r' && piece != 'b' && piece != 'k' && count%2 == 0) {
   		return 1 ;
   	}
   	else if (piece != 'R' &&  piece != 'B' && piece != 'K' && count%2 == 1) {
   	    return 1 ;
    }

    //自分の駒と駒がかぶらないかどうか
    if (piece == 'k' || piece == 'b' || piece == 'r') {
        if (banmen[y2-1][x4-1] == 'k' || banmen[y2-1][x4-1] == 'b' || banmen[y2-1][x4-1] == 'r') {
        	return 1 ;
        }
    }
    else if (piece == 'K' || piece == 'B' || piece == 'R') {
    	if (banmen[y2-1][x4-1] == 'K' || banmen[y2-1][x4-1] == 'B' || banmen[y2-1][x4-1] == 'R'){
    		return 1 ;
    	}
    }

    
    //駒の移動、その移動が可能かどうかを判断
    //ルークの移動
    if (piece == 'R' || piece == 'r') {
    	if((x4 == x3+2 && y2 == y1) || (x4 == x3-2 && y2 == y1) || (x4 == x3 && y2 == y1+2) || (x4 == x3 && y2 == y1-2) /*縦横２マス移動*/
    	    || (x4 == x3+1 && y2 == y1) || (x4 == x3-1 && y2 == y1) || (x4 == x3 && y2 == y1+1) || (x4 == x3 && y2 == y1-1) /*縦横１マス移動*/)  {
            if (banmen[y2-1][x4-1] == 'K') {
            	banmen[y2-1][x4-1] = piece ;
                banmen[y1-1][x3-1] = 0 ;
            	return 4 ;
            }
            else if (banmen[y2-1][x4-1] == 'k') {
            	banmen[y2-1][x4-1] = piece ;
                banmen[y1-1][x3-1] = 0 ;
            	return 5 ;
            }
            else {
            	banmen[y2-1][x4-1] = piece ;
                banmen[y1-1][x3-1] = 0 ;
                count++ ;  //そのターンにどちらの駒を使うかを判断
            	return 3 ;
            	
            }
        }
        else {
        	return 1 ;
        }
    } 

    //ビショップの移動
    else if (piece == 'B' || piece == 'b') {
        if( (x4 == x3+2 && y2 == y1+2) || (x4 == x3+2 && y2 == y1-2) || (x4 == x3-2 && y2 == y1+2) || (x4 == x3-2 && y2 == y1-2) /*斜め２マス移動*/
            || (x4 == x3+1 && y2 == y1+1) || (x4 == x3+1 && y2 == y1-1) || (x4 == x3-1 && y2 == y1+1) || (x4 == x3-1 && y2 == y1-1) /*斜め１マス移動*/) {
            if (banmen[y2-1][x4-1] == 'K' ) {
            	banmen[y2-1][x4-1] = piece ;
                banmen[y1-1][x3-1] = 0 ;
            	return 4 ;
            }
            else if (banmen[y2-1][x4-1] == 'k' ) {
            	banmen[y2-1][x4-1] = piece ;
                banmen[y1-1][x3-1] = 0 ;
            	return 5 ;
            }
            else {
            	banmen[y2-1][x4-1] = piece ;
                banmen[y1-1][x3-1] = 0 ;
                count++ ; //そのターンにどちらの駒を使うかを判断
            	return 3 ;
            }
        }
        else {
        	return 1 ;
        }
    }
    
    //キングの移動
    else if (piece == 'K' || piece == 'k') {
    	if( (x4 == x3+2 && y2 == y1) || (x4 == x3-2 && y2 == y1) || (x4 == x3 && y2 == y1+2) || (x4 == x3 && y2 == y1-2) /*縦横２マス移動*/
    	    || (x4 == x3+1 && y2 == y1) || (x4 == x3-1 && y2 == y1) || (x4 == x3 && y2 == y1+1) || (x4 == x3 && y2 == y1-1) /*縦横１マス移動*/
    		|| (x4 == x3+2 && y2 == y1+2) || (x4 == x3+2 && y2 == y1-2) || (x4 == x3-2 && y2 == y1+2) || (x4 == x3-2 && y2 == y1-2) /*斜め２マス移動*/
    	    || (x4 == x3+1 && y2 == y1+1) || (x4 == x3+1 && y2 == y1-1) || (x4 == x3-1 && y2 == y1+1) || (x4 == x3-1 && y2 == y1-1) /*斜め１マス移動*/) {
            if (banmen[y2-1][x4-1] == 'K' ) {
            	banmen[y2-1][x4-1] = piece ;
                banmen[y1-1][x3-1] = 0 ;
            	return 4 ;
            }
            else if (banmen[y2-1][x4-1] == 'k' ) {
            	banmen[y2-1][x4-1] = piece ;
                banmen[y1-1][x3-1] = 0 ;
            	return 5 ;
            }

            else {
            	banmen[y2-1][x4-1] = piece ;
                banmen[y1-1][x3-1] = 0 ;
            	count++ ; //そのターンにどちらの駒を使うかを判断
            	return 3 ;
            }
        }
        else {
        	return 1 ;
        }
    }
    
    return  2 ;
}