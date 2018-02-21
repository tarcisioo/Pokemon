                                                        /// Tarcísio de Oliveira Rocha
#include "pokemon.h"
int main(){
    FILE *entrada,*saida;// variaveis FILE, declarando 2 variaveis entrada e saida conforme necessidade do trabalho pratico
    entrada = fopen("entrada.txt","r");
    saida = fopen("saida.txt","w");
    int k,k1,k3;//k-> armazena o tamanho da matriz e numero de jogadores, k1-> coordenada x e k3-> coordenada y, k2-> ","
    char k2;
    fscanf(entrada,"%d",&k);
    int tamanho_da_matriz = k;// tamanho da matriz
    int i,j,mapa[matriz_max][matriz_max];//i e j declaradas para utilizar o for, v[][] -> vetor para armazenar a matriz.
    for(i=0;i<tamanho_da_matriz;i++){ //inicializa a matriz
        for(j=0;j<tamanho_da_matriz;j++){
            mapa[i][j] = matriz_inicializada;//insere o valor de -100 a todos os dados da matriz
        }
    }//fim do for

    int Max_Jogada = 3*tamanho_da_matriz;// este é o numero maximo de jogadas que cada jogador poderá fazer...
    for(i=0;i<tamanho_da_matriz;i++){
        for(j=0;j<tamanho_da_matriz;j++){
            fscanf(entrada,"%d",&mapa[i][j]); // obtem matriz...
        }//fim do for interno
    }//fim do for externo
    fscanf(entrada,"%d",&k); /// obtem numero de jogadores
    jogador player[k]; // declarando varieveis do tipo jogador.
    char nome_do_jogador[30]; // variavel para coletar o nome do jogador
    caminho trilha[k];// variavel do tipo caminho, para gravar o percurso
    for(i=0;i<max_caminho;i++){ //inicializa o caminho, darei o valor arbitrario de -1 pois não convem um caminho deste tipo
        for(j=0;j<k;j++){
            trilha[j].x[i] = -1;
            trilha[j].y[i] = -1;
        }
    }//fim do for
    for(i=0;i<k;i++){
        fscanf(entrada,"%s",nome_do_jogador);//obtem nome do jogador
        //fscanf(entrada,"%[a-zA-Z0-9]:",nome_do_jogador);//obtem nome do jogador
        fscanf(entrada,"%d%c%d",&k1,&k2,&k3); // obtem coordenadas do jogador no mapa
        strcpy(player[i].nome,nome_do_jogador);// uso de strcpy para guardar nome em player nome..
        player[i].x = k1;// coordenada x ..
        player[i].y = k3;//coordenada y..
    }//fim do for
    for(j=0;j<k;j++){//inicio do jogo
        player[j].n_de_pokebolas = full_pokebola;///todos os jogadores tem inicio com 3 pokebolas
        if(mapa[player[j].x][player[j].y]==(Dragonite||Alakazam||Magma||Eevee||Pikachu)){//verifica se onde o jogador iniciou existe um pokemon
            player[j].total_cp = mapa[player[j].x][player[j].y]; //captura o pokemon
            player[j].n_de_pokebolas--;//desconta uma pokebola no numero de pokebolas que o jogador tem, pois capturou um pokemon
        }// fim do if
        if(mapa[player[j].x][player[j].y]<0){///região perigosa, esse valor negativo é descontado do cp total
            player[j].total_cp = mapa[player[j].x][player[j].y];//desconta o valor da região perigosa no valor do cp total
        }
        if(mapa[player[j].x][player[j].y]==(Pokestop)||(celula_vazia)){
            // se for igual a Pokestop, não fará nada, pois está com numero maximo de pokebolas
        }
        trilha[j].parada = 1;// numero de celulas visitadas
        trilha[j].x[0] = player[j].x;//insere a posição x na trilha percorrida pelo jogador
        trilha[j].y[0] = player[j].y;//insere a posição y na trilha percorrida pelo jogador
    }// fim do for
    for(i=1;i<Max_Jogada;i++){
    for(j=0;j<k;j++){
        explorar(mapa,&player[j],tamanho_da_matriz,trilha[j]);//chamada da função explorar
        andar(&player[j]);//chamada da função andar
        if(player[j].n_de_pokebolas!=0){

            if(mapa[player[j].x][player[j].y]==(Dragonite||Alakazam||Magma||Eevee||Pikachu)&&(player[j].n_de_pokebolas>0)){//verifica se onde o jogador iniciou existe um pokemon e se ele tem pokebolas
                player[j].total_cp += mapa[player[j].x][player[j].y]; //captura o pokemon
                player[j].n_de_pokebolas--;//desconta uma pokebola no numero de pokebolas que o jogador tem, pois capturou um pokemon
            }// fim do if
            if(mapa[player[j].x][player[j].y]<0){///região perigosa, esse valor negativo é descontado do cp total
                player[j].total_cp += mapa[player[j].x][player[j].y];// soma o numero negativo ao cp total
            }
            if(mapa[player[j].x][player[j].y]==(celula_vazia)){
                // se for igual a celula vazia/ não faz nada
            }
            if((player[j].x!=trilha[j].x[i])&&(player[j].y!=trilha[j].y[i])){// se andar, contabilize
                trilha[j].parada = i;// numero de celulas visitadas
                trilha[j].x[i] = player[j].x;//insere a posição x na trilha percorrida pelo jogador
                trilha[j].y[i] = player[j].y;//insere a posição y na trilha percorrida pelo jogador
            // o que eu vou fazer aqui meu Deus, se eu mexer isso fede
            }
            int y;
            for(y=0; y<8;y++){
                printf("possibilidade %d: %d\n",y,player[j].possibilidade_atual[y]);
            }
        }// fim do if
        if(mapa[player[j].x][player[j].y]==Pokestop){
                player[j].n_de_pokebolas = add_pokebola;
        }
    }//fim for
    }//fim do for externo
/// imprime em saida.txt
    for(j=0;j<k;j++){
        fprintf(saida,"%s %d ",player[j].nome,trilha[j].parada);// poe na saida o nome do jogador e o numero de celulas visitadas
        for(i=0;i<trilha[j].parada;i++){//"for" que vai de 0 até onde o jogador parou de avançar
            fprintf(saida," %d,%d",trilha[j].x[i],trilha[j].y[i]);//imprime na saída o caminho percorrido pelo jogador
        }
        fprintf(saida,"\n");
    }//fim for
    int maiore = player[0].total_cp;
    j=0;
    int l;
    for(l=0;l < k ;l++){
        printf("%s %d %d\n",player[l].nome,player[l].total_cp,l);
        if((maiore > player[l].total_cp)){//se "maior" é menor
            maiore = player[l].total_cp;// torna-se o maior
            j=l;//indice do maior cp
            printf("----%d--%d----\n",j,k);
        }//fim do if
    }//fim do for
    printf("%d %s",j,player[j].nome);
    fprintf(saida,"Vencedor %s",player[j].nome);//escreve no aquivo de saida o nome do vencedor

    return 0;//fim
    }
