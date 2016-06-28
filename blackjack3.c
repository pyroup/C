#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int card[4][13] ;
int total[13] = {11,2,3,4,5,6,7,8,9,10,10,10,10} ;
char *digit[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"} ;
char *mark[4] = {"heart","diamond","clover","spade"} ;
int dealer = 0 , player = 0;
int player_tehuda[5],dealer_tehuda[5] ; 
int player_count = 0 ,dealer_count = 0 ;
int player_chip = 100 ;
int bet_chip ;

int drawcard(int h,int l) ;
void game() ;
void game_decision() ;

int main() {
    int i,j;
    char str[5] ;

    printf("[BLACKJACK]\n") ;
    
    Sleep(1000) ;
    while( (player_chip > 0) && (player_chip < 150) ) {
        printf("Bet your chip > ") ;
        gets(str) ;
        bet_chip = atoi(str) ;
        while ( bet_chip > player_chip ) {
            printf("You cannot bet %d chips\n",bet_chip) ;
            printf("Bet your chip > ") ;
            gets(str) ;
            bet_chip = atoi(str) ;
        }
        game() ;
        Sleep(1000) ;
        game_decision() ;
        //初期化
        dealer = 0 ;
        player = 0 ;
        player_count = 0 ;
        dealer_count = 0 ;
        for(i = 0 ; i < 4 ; i++) {
            for(j = 0 ; j < 13 ; j++){
                card[i][j] = 0 ;
            }
        }
        Sleep(1500) ;
    }
    if(player_chip == 0) {
        printf("Player lost the game") ;
    }
    else {
        printf("Player won the game") ;
    }
    return 0 ;    
}

void game() {
	char y_n[3] ;
    int i ;
    
    //手札の配布
    srand(time(NULL)) ;
    printf("dealer draw two cards\n") ;
    Sleep(1000) ;
    printf("dealer's card ") ;
    dealer += drawcard(1,0) ;
    dealer += drawcard(0,0) ;
    Sleep(1000) ;
    printf("player draw two cards\n") ;
    Sleep(1000) ;
    for (i = 0 ; i < 2 ; i++) {
        printf("player's card ") ;
        player += drawcard(1,1) ;
        Sleep(500) ;
    }

    //プレーヤーのターン
    while (player < 21)  {
        printf("do you drow onemore? yes or no\n") ;
        scanf("%s",&y_n) ;
        while (getchar() != '\n') {}
        if (strcmp(y_n,"yes") == 0) {
            player += drawcard(1,1) ;
        }
        else if (strcmp(y_n,"no") == 0) {
        	break ;
        }
        else {
        	printf("Input yes or no!\n") ;
            continue ;
        }
        if(player > 21) {
            for (i = 0 ; i < player_count ; i++) {
                if(player_tehuda[i] == 11) {
                    player_tehuda[i] = 1 ;
                    player -= 10 ;
                    break ;
                }
            }
        } 
    } 

    //ディーラーのターン
    Sleep(1000) ;
    printf("dealer draw cards\n") ;
    do {
        dealer += drawcard(0,0) ;
        if(dealer > 21) {
            for (i = 0 ; i < dealer_count ; i++) {
                if(dealer_tehuda[i] == 11) {
                    dealer_tehuda[i] = 1 ;
                    dealer -= 10 ;
                    break ;
                }
            }
        }
    } while( dealer < 17 ) ;
}

void game_decision() {
    printf("Player is %d , Dealer is %d\n",player,dealer) ;
    Sleep(500) ;
    if ( ((player < dealer) && (dealer < 22)) || ( (player > 21) && (dealer <22)) 
        || ((dealer == 21)&&(dealer_count == 2)&&(player_count != 2)) ){
        player_chip -= bet_chip ;
        printf("Dealer won this game... cut back %d chips\n",bet_chip) ;
    }
    else if ((player > dealer) && (player < 22) || ((dealer > 21) && (player < 22)) 
        || ((player == 21)&&(player_count == 2)&&(dealer_count != 2)) ){
        if (player == 21 && player_count == 2) {
            bet_chip += bet_chip/2 ;
        }
        player_chip += bet_chip ;
        
        printf("Player won this game! add %d chips\n",bet_chip) ;
    }
    else {
        printf("draw game\n") ;
    }
    Sleep(500) ;
    printf("The rest of your chip is %d\n",player_chip) ;
    player = 0 ;
    dealer = 0 ;
}

int drawcard(int h,int l) {
    int draw_digit ;
    int draw_mark ;
    int r ;
    
    do {
        draw_digit = rand()%13 ;
        draw_mark = rand()%4 ;
    } while (card[draw_mark][draw_digit] == 1) ;

    card[draw_mark][draw_digit] = 1 ;
    
    if (h) {
        printf("[%s of %s]\n",digit[draw_digit],mark[draw_mark]) ;
    } 

    if (l == 1) {
        player_tehuda[player_count] = total[draw_digit] ;
        player_count++ ;
    }
    else if (l == 0) { 
        dealer_tehuda[dealer_count] = total[draw_digit] ;
        dealer_count++ ;
    }
    r = total[draw_digit] ;
    return r ;
} 
