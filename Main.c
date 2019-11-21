#include <stdio.h>
#include <stdlib.h>
#include "Nodes.h"
#include "Utils.h"

int main() {
	Frutas* lista = NULL;
	int
			opcao,
			_retScanf;
	//adicionarVariedade(&lista);
	//imprimirLista(&lista);
	boasVindas();
	opcao = menuSelecao();
	do {
		switch(opcao) {
		case ADICIONAR_FRUTA:
			if(!lista) { lista = criaListaDeFrutas(); }
			do {
				char	nome[LIMITE_NOME];
				printf("Adicione uma fruta a lista: ");
				_retScanf = scanf("%49s", nome);
				adicionarFruta(&lista, nome);
			} while(deveAdicionarNovoItem());
			break;

		case ADICIONAR_VARIEDADE:
			{
			int		i = 2;
			Frutas*	fruta;
			fruta	= getFruta(&lista, i);
			if(!fruta) { exit(EXIT_FAILURE); }
			do {
				char	nome[LIMITE_NOME];
				printf("Adicione uma variedade a lista de %s(s): ", fruta->nome);
				_retScanf	= scanf("%49s", nome);
				adicionarVariedade(&fruta, nome);
			} while(deveAdicionarNovoItem());
			break;
			}
		case IMPRIMIR_INVENTARIO:
			imprimirLista(&lista);
			break;
		case SALVAR_DADOS:
			salvar(&lista);
			break;
		case SAIR:
			exit(EXIT_SUCCESS);
		}
		opcao = menuSelecao();
	} while(opcao != SAIR);
	return 0;
}