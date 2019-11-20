#include <stdlib.h>
#include <stdio.h>
#include "Nodes.h"

//Retorna uma lista de Frutas.
Frutas* criaListaDeFrutas() {
	Frutas*	lista;
	lista				= (Frutas*)malloc(sizeof(Frutas)); //No Head
	if(!lista) { exit(EXIT_FAILURE); }
	lista->proximo_no	= NULL;
	lista->variedade	= NULL;
	do { adicionarFruta(&lista); } while(deveAdicionarNovoItem());
	return lista;
}

//Adiciona uma fruta a lista de frutas eistente.
void adicionarFruta(Frutas** lista) {
	Frutas*	novo;
	int		_retScanf;
	novo					= (Frutas*)malloc(sizeof(Frutas));
	if(!novo) { exit(EXIT_FAILURE); }
	printf("Adicione uma fruta a lista: ");
	_retScanf				= scanf("%s", novo->nome);
	novo->proximo_no		= (*lista)->proximo_no;
	novo->variedade			= NULL;
	(*lista)->proximo_no	= novo;
	return;
}

//Adiciona uma variedade de fruta a um dos nodes da lista.
void adicionarVariedade(Frutas** lista) {
	Tipos*	novo;
	char	nome[50];
	int		_retScanf;
	novo							= (Tipos*)malloc(sizeof(Tipos));
	if(!novo) { exit(EXIT_FAILURE); }
	_retScanf						= scanf("%s", novo->nome);
	novo->proximo_no				= (*lista)->proximo_no->variedade;
	(*lista)->proximo_no->variedade	= novo;
	return;
}

//Imprime menu de confirmacao para adionar novo item e retorna booleano da resposta.
int deveAdicionarNovoItem() {
	int		_retScanf;
	char	sim_ou_nao[10];
	printf("Deseja adicionar novo item?[s/S] ou [n/N]: ");
	_retScanf = scanf("%s", sim_ou_nao);
	return sim_ou_nao[0] == 's' || sim_ou_nao[0] == 'S';
}