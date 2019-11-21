#pragma once
#define LIMITE_NOME	50
//No principal de frutas. Guarda lista de frutas por variedade.
typedef struct NODE_FRUTAS {
	char	nome[LIMITE_NOME];
	struct  NODE_FRUTAS*	proximo_no;
	struct  NODE_VARIEDADE*	variedade;
}Frutas;

//No secundario de frutas, com as variedades de frutas, uma por no.
typedef struct NODE_VARIEDADE{
	char	nome[LIMITE_NOME];
	struct  NODE_VARIEDADE* proximo_no;
}Tipos;

Frutas*	criaListaDeFrutas();
void	adicionarFruta(Frutas** lista, char nome[LIMITE_NOME]);
void	adicionarVariedade(Frutas** fruta, char nome[LIMITE_NOME]);
Frutas* getFruta(Frutas** lista, int indice);
void	imprimirLista(Frutas** lista);
int		deveAdicionarNovoItem();