#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char tabuleiro[3][3];
int game_over;
int i;
int j;
void printar_tabuleiro(){
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c  ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int first_move(){ // feito
    srand(time(NULL));
    return rand() % 2;
}

int jogo() {
    int position;
    if(first_move() == 0){ //maquina começa
        srand(time(NULL));
        position = (rand()%5)+1;
        
             // 1~5
        switch(position){
            case 1:
                printf("1\n");
                tabuleiro[0][0] = 'x';
                break;
            case 2:
                printf("2\n");
                tabuleiro[0][2] = 'x';
                break;
            case 3:
                printf("3\n");
                tabuleiro[1][1] = 'x';
                break;
            case 4:
                printf("4\n");
                tabuleiro[2][0] = 'x';
                break;
            case 5:
                printf("5\n");
                tabuleiro[2][2] = 'x';
                break;
            }       
        
    }else{
        printf("player\n");
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
    
    return 0;
}

int main(){  
    game_over = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = '.';
        }
    }
    
    jogo();
    printar_tabuleiro();
    
    
    

    return 0;
}
