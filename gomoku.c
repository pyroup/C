#include <stdio.h>  //kakunin
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MTX 5

int kbox[5][5] ;

void board () ;
int turn () ;
int stone(char x1,int y1,int player) ;
int hantei() ;

int main () {
    char str[5] ;
    int turn1 ;
    char x ;
    int y ;
    int error ;
    int hantei1 = 0 ;
    int i ;
    
    //順番を決める際に使用
    srand(time(NULL)) ; 
    
    printf("[gomokunarabe]\n") ;
    board() ;
    turn1 = turn () ;
    while(hantei1 == 0) {
    	error = 1 ;
        if(turn1 == 1) {
    	    while (error == 1) {
    	        printf("(player1) Input spot (ex.a 3) > ") ;
    	        fgets(str,4,stdin) ;
    	        if(strlen(str) == 3 && str[2] != '\n') {
    		        while (getchar() != '\n') {}
    	        }
    	        //finと入力したらプログラムが終了する
    	        if(strcmp(str,"fin") == 0) {
    	        	hantei1 = 4 ;
                    break ;
    	        }

                sscanf(str,"%c %d",&x,&y) ;
                error = stone(x,y,turn1) ;
            }
            turn1++ ;
        }
        else if(turn1 == 2) {
        	while(error == 1) {
    	        printf("(player2) Input spot (ex.a 3) > ") ;
    	        fgets(str,4,stdin) ;
    	        if(strlen(str) == 3 && str[2] != '\n') {
    	           while (getchar() != '\n') {}
                }
                //finと入力したらプログラムが終了する 
                if(strcmp(str,"fin") == 0) {
    	        	hantei1 = 4 ;
                    break ;
    	        }

                sscanf(str,"%c %d",&x,&y) ;
                error = stone(x,y,turn1) ;
    	    }
    	    turn1-- ;
        }
        //安全措置
        else {
        	break ;
        }
        if (hantei1 == 4 ) {
        	break ;
        }
        board () ;
        hantei1 = hantei() ;
    }
    if(hantei1 == 1) {
    	printf("player1 won the game") ;
    } 
    else if(hantei1 == 2) {
    	printf("player2 won the game") ;
    } 
    else if(hantei1 == 3) {
    	printf("drow the game") ;
    }
    else if (hantei1 == 4){
        printf("finish the game") ;
    }
    return 0 ;
}

// コイントス形式で順番を決定する関数
int turn () {
	char s[7] ;
    int r ; 
    int i = 0;
    char *coin[] = {"front","back"} ;

	printf("[turn is decided by coin toss]\n") ;
	while (i == 0) { 
		i = 1 ;
	    printf("(player1) select front or back > ") ;
	    fgets(s,sizeof(s),stdin) ;
        if (strlen(s) == sizeof(s)-1 && s[5] != '\n') {
    	    while (getchar() != '\n') {}
        }
        else if (s[5] == '\n') {
            s[5] = '\0' ;
        }
        else if (s[4] == '\n') {
            s[4] = '\0' ;
        }	
        r = rand()%2 ;
        if (strcmp(s,*(coin+r)) == 0) {
    	    printf("coin is %s\n",*(coin+r)) ;
    	    printf("first turn start from player1\n") ;
    	    return 1 ;
        }
        else if (r == 0 && strcmp(s,*(coin+r+1)) == 0) {
    	    printf("coin is %s\n",*(coin+r)) ;
            printf("first turn start from player2\n") ;
            return 2 ;
        }
        else if (r == 1 && strcmp(s,*(coin+r-1)) == 0) {
    	    printf("coin is %s\n",*(coin+r)) ;
            printf("first turn start from player2\n") ;
            return 2 ;
        }
        else {
        	i = 0 ;
        }
    }    
}

//盤面を出力する関数
void board () {
	int i,j ;
    char moji[] = {'a','b','c','d','e'} ;
    
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
				printf(" 0  ") ;
			}
			//プレイヤー番号が自分の石となる
			else if(kbox[i][j] == 1) {
				printf(" 1  ") ;
			}
			else if(kbox[i][j] == 2) {
				printf(" 2  ") ;
			}
		    if (j == MTX-1) {
		    	printf("\n") ;
		    }
		}
	}
}

//石を置く関数、戻り値で有効な入力かどうか判断
int stone (char x1,int y1,int player) {
	int x2 ;
    
    if (x1 == 'a') {
        x2 = 0 ;
        if (y1 <= 5 && y1 > 0 && kbox[y1-1][x2] == 0/*0以外が入っていたらキャンセルする*/) {
        	kbox[y1-1][x2] = player ;
        	return 0 ;
        }
        else {
        	return 1 ;
        }
    }
    else if (x1 == 'b') {
    	x2 = 1 ;
    	if (y1 <= 5 && y1 > 0 && kbox[y1-1][x2] == 0) {
        	kbox[y1-1][x2] = player ;
        	return 0 ;
        }
        else {
        	return 1 ;
        }
    }
    else if (x1 == 'c') {
    	x2 = 2 ;
    	if (y1 <= 5 && y1 > 0 && kbox[y1-1][x2] == 0) {
        	kbox[y1-1][x2] = player ;
        	return 0 ;
        }
        else {
        	return 1 ;
        }
    }
    else if (x1 == 'd') {
    	x2 = 3 ;
    	if (y1 <= 5 && y1 > 0 && kbox[y1-1][x2] == 0) {
        	kbox[y1-1][x2] = player ;
        	return 0 ;
        }
        else {
        	return 1 ;
        }
    }
    else if (x1 == 'e') {
    	x2 = 4 ;
    	if (y1 <= 5 && y1 > 0 && kbox[y1-1][x2] == 0) {
        	kbox[y1-1][x2] = player ;
        	return 0 ;
        }
        else {
        	return 1 ;
        }
    }
    else {
        return 1 ;
    }
}

//勝負の判定をする関数
int hantei() {
    int count1 ;
    int count2 ;
    int i,j ;

    //横の判定
    for(i = 0 ; i < MTX ; i++) {
    	if(kbox[i][0] == 1) {
    	    for(j = 1 , count1 = 0 , count2 = 0 ; j < MTX ; j++) {
    	        if(kbox[i][j] == 1) {
                    count1++ ;
    	        }
    	        else {
    	        	break ;
    	        }
    	    }
        }
        else if(kbox[i][0] == 2) {
        	for(j = 1 , count1 = 0 , count2 = 0 ; j < MTX ; j++) {
    	        if(kbox[i][j] == 2) {
                    count2++ ;
    	        }
    	        else {
    	        	break ;
    	        }
    	    }
        }
        if(count1 == 4 || count2 == 4) {
        	break ;
        }
    }
    if(count1 == 4) {
    	return 1 ;
    }
    else if (count2 == 4) {
    	return 2 ;
    }

    //縦の判定
    for(j = 0 , count1 = 0 , count2 = 0 ; j < MTX ; j++) {
    	if(kbox[0][j] == 1) {
    	    for(i = 1 , count1 = 0 , count2 = 0 ; i < MTX ; i++) {
    	        if(kbox[i][j] == 1) {
                    count1++ ;
    	        }
    	        else {
    	        	break ;
    	        }
    	    }
        }
        else if(kbox[0][j] == 2) {
        	for(i = 1 , count1 = 0 , count2 = 0 ; i < MTX ; i++) {
    	        if(kbox[i][j] == 2) {
                    count2++ ;
    	        }
    	        else {
    	        	break ;
    	        }
    	    }
        }
        if (count1 == 4 || count2 == 4) {
        	break ;
        }
    }
    if(count1 == 4) {
    	return 1 ;
    }
    else if (count2 == 4) {
    	return 2 ;
    }

    // 左斜め(\)方向
    for(i = 0 , count1 = 0 ,count2 = 0 ; i < MTX ; i++) {
    	if(kbox[i][i] == 1) {
    		count1++ ;
    	}
    	else if(kbox[i][i] == 2) {
    		count2++ ;
    	}
    	if(kbox[i][i] == 0 || count1 == 5 || count2 == 5) {
    		break ;
    	}
    }	
    if (count1 == 5) {
    	return 1 ;
    }
    else if (count2 == 5) {
    	return 2 ;
    }
    //右斜め(/)方向
    for(i = 0 , count1 = 0 , count2 = 0 ; i < MTX ; i++) {
    	if(kbox[4-i][i] == 1) {
            count1++ ;
    	}
    	else if(kbox[4-i][i] == 2) {
    		count2++ ;
    	}
    	if(kbox[4-i][i] == 0 || count1 == 5 || count2 == 5) {
    		break ;
    	}
    }
    if (count1 == 5) {
    	return 1 ;
    }
    else if (count2 == 5) {
    	return 2 ;
    }
    
    //置くマスがあるかどうか判断
    for(i = 0 , count1 = 0 ; i < MTX ; i++) {
    	for(j = 0 ; j < MTX ; j++) {
    		if(kbox[i][j] != 0) {
    			count1++ ;
    		}
    	}
    }
    if(count1 == 25) {
    	return 3 ;
    }

    //該当なし
    else {
    	return 0 ;
    }
}