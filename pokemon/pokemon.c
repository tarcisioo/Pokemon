#include "pokemon.h"

//A função explorar mostra todos as possibilidades do jogador a partir do ponto que esse se encontra
void explorar(int mapa[matriz_max][matriz_max],jogador *A, int n, caminho trilha){
    int x = A->x;
    int y = A->y;
    printf("(%d,%d)\n\n",x,y);
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
          printf("%d ",mapa[i][j]); // obtem matriz...
        }//fim do for interno
        printf("\n");
    }//fim do for externo

    //todas as 8 possibilidades encontradas pelo jogador
    // o valor de -100 é atrabuido caso esteja na margem da matriz aos que não devem ser acessados
    if((y-1)>=0){
       A->possibilidade_atual[0] = mapa[x][y-1];//   esqueda
    }
    else{
        A->possibilidade_atual[0] = matriz_inicializada;
    }
    for(i=0;i<matriz_max;i++){
        if((trilha.x[i]==x)&&(trilha.y[i]==(y-1))){// analiza se a celula ja foi visitada
            A->possibilidade_atual[0] = matriz_inicializada;// coloca na celula o valor de -100 para marcar que o caminho já foi feito
        }//fim do if
    }// fim do for
    if(((y-1)>=0)&&((x-1)>=0)){
       A->possibilidade_atual[1] = mapa[x-1][y-1];// esqueda-cima
    }
    else{
        A->possibilidade_atual[1]= matriz_inicializada;
    }
    for(i=0;i<matriz_max;i++){
        if((trilha.x[i]==x-1)&&(trilha.y[i]==(y-1))){// analiza se a celula ja foi visitada
            A->possibilidade_atual[1] = matriz_inicializada;// coloca na celula o valor de -100 para marcar que o caminho já foi feito
        }//fim do if
    }// fim do for

    if((x-1)>=0){
        A->possibilidade_atual[2] = mapa[x-1][y];//   cima
    }
    else{
        A->possibilidade_atual[2]= matriz_inicializada;
    }
    for(i=0;i<matriz_max;i++){
        if((trilha.x[i]==x-1)&&(trilha.y[i]==(y))){// analiza se a celula ja foi visitada
            A->possibilidade_atual[2] = matriz_inicializada;// coloca na celula o valor de -100 para marcar que o caminho já foi feito
        }//fim do if
    }// fim do for

    if(((y+1)<n)&&((x-1)>=0)){
        A->possibilidade_atual[3] = mapa[x-1][y+1];//  cima-direita
    }
    else{
        A->possibilidade_atual[3]= matriz_inicializada;
    }
    for(i=0;i<matriz_max;i++){
        if((trilha.x[i]==x-1)&&(trilha.y[i]==(y+1))){// analiza se a celula ja foi visitada
            A->possibilidade_atual[3] = matriz_inicializada;// coloca na celula o valor de -100 para marcar que o caminho já foi feito
        }//fim do if
    }// fim do for

    if((y+1)<n){
        A->possibilidade_atual[4] = mapa[x][y+1];//   direita
    }
    else{
        A->possibilidade_atual[4]= matriz_inicializada;
    }
    for(i=0;i<matriz_max;i++){
        if((trilha.x[i]==x)&&(trilha.y[i]==(y+1))){// analiza se a celula ja foi visitada
            A->possibilidade_atual[4] = matriz_inicializada;// coloca na celula o valor de -100 para marcar que o caminho já foi feito
        }//fim do if
    }// fim do for

    if(((y+1)<n)&&((x+1)<n)){
        A->possibilidade_atual[5] = mapa[x+1][y+1];// direita-baixo
    }
    else{
        A->possibilidade_atual[5]= matriz_inicializada;
    }
    for(i=0;i<matriz_max;i++){
        if((trilha.x[i]==x+1)&&(trilha.y[i]==(y+1))){// analiza se a celula ja foi visitada
            A->possibilidade_atual[5] = matriz_inicializada;// coloca na celula o valor de -100 para marcar que o caminho já foi feito
        }//fim do if
    }// fim do for

    if((x+1)<n){
        A->possibilidade_atual[6] = mapa[x+1][y];// baixo
    }
    else{
    A->possibilidade_atual[6]= matriz_inicializada;
    }
    for(i=0;i<matriz_max;i++){
        if((trilha.x[i]==x+1)&&(trilha.y[i]==(y))){// analiza se a celula ja foi visitada
            A->possibilidade_atual[6] = matriz_inicializada;// coloca na celula o valor de -100 para marcar que o caminho já foi feito
        }//fim do if
    }// fim do for

    if(((y-1)>=0)&&((x+1)<n)){
        A->possibilidade_atual[7] = mapa[x+1][y-1];// baixo-esquerda
    }
    else{
        A->possibilidade_atual[7]= matriz_inicializada;
    }
    for(i=0;i<matriz_max;i++){
        if((trilha.x[i]==x+1)&&(trilha.y[i]==(y-1))){// analiza se a celula ja foi visitada
            A->possibilidade_atual[7] = matriz_inicializada;// coloca na celula o valor de -100 para marcar que o caminho já foi feito
        }//fim do if
    }// fim do for

}//fim

void andar(jogador *A){
    int i,j=0,maior=A->possibilidade_atual[0];// faz maior igual ao primeiro
    for(i=1;i<8;i++){//existem 8 possobilidades
        if(A->n_de_pokebolas>0){
        if((maior < A->possibilidade_atual[i])&&(A->possibilidade_atual[i]!=Pokestop)){// procuro o maior cp entre os cps e que seja diferente da pokestop
            maior = A->possibilidade_atual[i];
            j=i;// guardo o indice desse amior elemento do vetor de 8 posições
        }// fim if
        }// fim do if externo
        if(A->n_de_pokebolas==0){
            if(maior < A->possibilidade_atual[i]){// procuro o maior elemento cp entre os elementos
            maior = A->possibilidade_atual[i];
            j=i;// guardo o indice desse amior elemento do vetor de 8 posições
        }// fim if
        }
    }// fim do for
    //serie de ifs para mudança de localidade do jogador
    if(j==0){
        A->x;
        A->y -=1;
    }if(j==1){
        A->x -=1;
        A->y -=1;
    }if(j==2){
        A->x -=1;
        A->y;
    }if(j==3){
        A->x -=1;
        A->y +=1;
    }if(j==4){
        A->x;
        A->y +=1;
    }if(j==5){
        A->x +=1;
        A->y +=1;
    }if(j==6){
        A->x+=1;
        A->y;
    }if(j==7){
        A->x +=1;
        A->y -=1;
    }
}// fim

void caminho_percorrido(jogador *A){
/// isto está em main, depois resolvo!
}

void recarrega_pokebola(jogador *A){

    A->n_de_pokebolas = add_pokebola;
}
