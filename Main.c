#include <stdio.h>
#include <stdlib.h>
#include "Nodes.h"
#include "Utils.h"

int main() {
	Frutas* lista;
	int
			opcao,
			_retScanf;
	carregar(&lista);
	boasVindas();
	opcao = menuSelecao();
	do {
		switch(opcao) {//TODO: adicionar opção abrir relatorio
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
			Frutas*	fruta;
			fruta	= getFruta(&lista, selecionarFruta(&lista));
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
			//system("start relatorio.html");
			exit(EXIT_SUCCESS);
		}
		opcao = menuSelecao();
	} while(opcao != SAIR);
	
	return 0;
}