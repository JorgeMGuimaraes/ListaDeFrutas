#include <stdio.h>
#include <stdlib.h>
#include "Nodes.h"
#include "Utils.h"

int main() {
	Frutas* lista = NULL;
	int		opcao;
	//adicionarVariedade(&lista);
	//imprimirLista(&lista);
	boasVindas();
	opcao = menuSelecao();
	do {
		switch(opcao) {
		case ADICIONAR_FRUTA:
			if(lista)	{ adicionarFruta(&lista); }
			else		{ lista = criaListaDeFrutas(); }
			break;

		case ADICIONAR_VARIEDADE:
			//TODO: selecionar a fruta
			adicionarVariedade(&lista);//TODO: loop do while deve estar aqui
			break;
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