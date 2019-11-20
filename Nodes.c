#include <stdlib.h>
#include <stdio.h>
#include "Nodes.h"

//Retorna uma lista de Frutas.
Frutas* criaListaDeFrutas() {
	Frutas*	lista;
	lista				= (Frutas*)malloc(sizeof(Frutas)); //Node Head
	if(!lista) { exit(EXIT_FAILURE); }
	lista->proximo_no	= NULL;
	lista->variedade	= NULL;
	adicionarFruta(&lista);
	return lista;
}

//Adiciona uma fruta a lista de frutas eistente.
void adicionarFruta(Frutas** lista) {
	do {
		Frutas*	novo;
		int		_retScanf;
		novo					= (Frutas*)malloc(sizeof(Frutas));
		if(!novo) { exit(EXIT_FAILURE); }
		printf("Adicione uma fruta a lista: ");
		_retScanf				= scanf("%s", novo->nome);	//TODO: scanf com %49s
		novo->proximo_no		= (*lista)->proximo_no;
		novo->variedade			= NULL;
		(*lista)->proximo_no	= novo;
	} while(deveAdicionarNovoItem());
	return;
}

//Adiciona uma variedade de fruta a um dos nodes da lista.
void adicionarVariedade(Frutas** lista) {
	do {
		Tipos*	novo;
		char	nome[50];
		int		_retScanf;
		novo							= (Tipos*)malloc(sizeof(Tipos));
		if(!novo) { exit(EXIT_FAILURE); }
		printf("Adicione uma variedade a lista de %s(s): ", (*lista)->proximo_no->nome);	//TODO: verificar se dá pra imprimir char acentudos em todos os casos
		_retScanf						= scanf("%s", novo->nome);	//TODO: scanf com %49s
		novo->proximo_no				= (*lista)->proximo_no->variedade;
		(*lista)->proximo_no->variedade	= novo;
	} while(deveAdicionarNovoItem());
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

//Imprime lista com todas as frutas, seguidas de suas variedades.
void imprimirLista(Frutas** lista) {
	int		contFrutas		= 0,
			contVariedades	= 0;
	Frutas* fruta;
	Tipos*	tipo;
	fruta	= (*lista)->proximo_no;
	printf("+===========================================================+\n");//TODO: adionar quebra antes
	printf("+===================== Lista de Frutas =====================+\n");
	printf("+===========================================================+\n\n");
	while(fruta) {
		contFrutas++;
		printf("> %s\n", fruta->nome);
		tipo	= fruta->variedade;
		while(tipo) {
			contVariedades++;
			printf("\t- %s\n", tipo->nome);
			tipo = tipo->proximo_no;
		}
		printf("\n");
		fruta	= fruta->proximo_no;
	}
	printf("Total de %d frutas e %d variedades.\n", contFrutas, contVariedades);
	return;
}