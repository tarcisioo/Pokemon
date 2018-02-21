#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#endif // POKEMON_H_INCLUDED

#define celula_vazia  0 //valor cp celula vazia
#define Dragonite 1 //cp do pokemon
#define Alakazam 2 // cp do pokemon
#define Magma 3 // cp do pokemon
#define Eevee 4 //cp do pokemon
#define Pikachu 5 // cp do pokemon
#define Pokestop 6 // indintificador de pokestop
#define add_pokebola 1 // aciciona uma pokebola caso pokestop ok
#define matriz_max 100 // tamanho maximo da matriz para o jogo
#define full_pokebola 3 // inicio, todos os jogadores tem 3 pekebolas
#define matriz_inicializada -100 // identifidador para valores impossiveis de ir
#define max_caminho 1000// numero maximo de coordenadas possiveis 2xn
#include <stdio.h>
#include <stdlib.h>
#include <string.h>// biblioteca necessaria para utilizar o strcpy
typedef struct caminho
{
    int x[max_caminho];
    int y[max_caminho];
    int parada;
}caminho;

typedef struct jogador
{
    char nome[30];//nome do jogador
    int n_de_pokebolas;
    //int n_pokemons_cp[6];//numero de pokemon obtidos
    int x,y; //posição do jogador
    int total_cp;// somatorio de cps de todos os pokemons obtidos
    int possibilidade_atual[8];
}jogador;
//cabeçalho das funções para TAD jogador
void explorar(int [matriz_max][matriz_max],jogador*,int, caminho);
void andar(jogador *A);
void caminho_percorrido();
void recarrega_pokebola(jogador*);




