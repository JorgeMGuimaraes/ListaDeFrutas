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
	return lista;
}

//Adiciona uma fruta a lista de frutas eistente.
void adicionarFruta(Frutas** lista, char nome[LIMITE_NOME]) {
	Frutas*	novo;
	int
			_retScanf,
			i;
	novo					= (Frutas*)malloc(sizeof(Frutas));
	if(!novo) { exit(EXIT_FAILURE); }
	i						= 0;
	while(nome[i] != '\0') {
		novo->nome[i]		= nome[i];
		++i;
	}
	novo->nome[i]			= '\0';
	novo->proximo_no		= (*lista)->proximo_no;
	novo->variedade			= NULL;
	(*lista)->proximo_no	= novo;
	return;
}

//Retorna uma fruta de indice i
Frutas* getFruta(Frutas** lista, int indice) {
	Frutas* fruta;
	int		i;
	fruta = (*lista)->proximo_no;
	for(i = 1; i < indice; i++) { fruta = fruta->proximo_no; }
	return fruta;
}

//Adiciona uma variedade de fruta a um dos nodes da lista.
void adicionarVariedade(Frutas** fruta, char nome[LIMITE_NOME]) {
	Tipos*	novo;
	int		i;
	novo				= (Tipos*)malloc(sizeof(Tipos));
	if(!novo) { exit(EXIT_FAILURE); }
	i					= 0;
	while(nome[i] != '\0') {
		novo->nome[i]	= nome[i];
		++i;
	}
	novo->nome[i]		= '\0';
	novo->proximo_no	= (*fruta)->variedade;
	(*fruta)->variedade	= novo;
	return;
}

//Imprime menu de confirmacao para adionar novo item e retorna booleano da resposta.
int deveAdicionarNovoItem() {
	int		_retScanf;
	char	sim_ou_nao[LIMITE_NOME];
	printf("Deseja adicionar novo item?[s/S] ou [n/N]: ");
	_retScanf = scanf("%s", sim_ou_nao);
	return sim_ou_nao[0] == 's' || sim_ou_nao[0] == 'S';
}

//Imprime lista com todas as frutas, seguidas de suas variedades.
void imprimirLista(Frutas** lista) {	//TODO: mover para utils
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
			printf("   - %s\n", tipo->nome);
			tipo = tipo->proximo_no;
		}
		printf("\n");
		fruta	= fruta->proximo_no;
	}
	printf("Total de %d frutas e %d variedades.\n", contFrutas, contVariedades);
	//Todo: adicionar +===+ no fim
	return;
}