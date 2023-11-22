#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char tabuleiro[3][3];
int game_over;
int i,j;
int movement,position;


void printar_tabuleiro(){
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c  ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void player1(){
    printf("player 1 to play\n");
    int ask = 1;
    int x,y;
    do{
    printf("choose a place to play\n");
    scanf("%d %d",&x,&y);
    if(x<0 || x>2 || y<0||y>2 ||tabuleiro[x][y]!= '.'){
        printf("invalid play\n");
    }
    else{
        tabuleiro[x][y]='x';
        ask=0;
    }
    }while(ask==1);

}
void player2(){
    printf("player 2 to play\n");
    int ask = 1;
    int x,y;
    do{
    printf("choose a place to play\n");
    scanf("%d %d",&x,&y);
    if(x<0 || x>2 || y<0||y>2 ||tabuleiro[x][y]!= '.'){
        printf("invalid play\n");
    }
    else{
        tabuleiro[x][y]='o';
        ask=0;
    }
    }while(ask==1);
}
int verify(){
    int win = 0;
    int emptySpaces = 0;
    for(i=0;i<3;i++){
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != '.') {
            win++;
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != '.') {
            win++;
        }
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != '.') {
        win++;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != '.') {
        win++;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == '.') {
                emptySpaces++;
            }
        }
    }
    if (win == 0 && emptySpaces == 0) {
        printf("tie");
        game_over = 1;
    }
    return win > 0 ? 1 : 0;
    
}
int jogo() {
    if(movement == 0){ //maquina começa
        player1();   
      }else{
        player2();      
    }
}



int main(){  
    game_over = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = '.';
            
        }
    }
    srand(time(NULL));
    movement = rand() % 2;       
    while(!game_over){
    
        jogo();
        printar_tabuleiro();
        movement = 1 - movement;
        if(verify()==1){
            if (movement==1){
            printf("player 1 wins");
        
            }else{
                printf("player 2 wins");
            }
        game_over = 1;
        }
    }
    return 0;
}
