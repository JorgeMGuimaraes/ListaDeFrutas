#include <stdio.h>
#include "Utils.h"
#include "Nodes.h"

//Imprime Header de boas vindas
void boasVindas() {
	printf("Frutas.com PDV 0.4.1\n\n");
	return;
}

//Imprime menu de selecao e retorna a opcao do usuario
int menuSelecao() {
	int resposta, _retScanf;
	do {
		printf("\n  [%d] - Adicionar fruta ao inventario\n",			ADICIONAR_FRUTA);
		printf("  [%d] - Adicionar variedades a alguma fruta\n",	ADICIONAR_VARIEDADE);
		printf("  [%d] - Imprimir inventario na tela\n",			IMPRIMIR_INVENTARIO);
		printf("  [%d] - Salvar as alteracoes no banco de dados\n", SALVAR_DADOS);
		printf("  [%d] - Sair\n",									SAIR);
		printf("\nEscolha uma opcao: ");
		_retScanf = scanf("%d", &resposta);
	} while(ADICIONAR_FRUTA > resposta && resposta > SAIR);
	return resposta;
}

//Retorna o indice da fruta selecionada pelo usuario
int selecionarFruta(Frutas** lista) {
	int
			resposta,
			contador,
			_retScanf;
	Frutas* aux;
	do {
		aux			= (*lista)->proximo_no;
		contador	= 0;
		while(aux) {
			printf("[%d] - %s\n", ++contador, aux->nome);
			aux		= aux->proximo_no;
		}
		printf("Escolha uma fruta: ");
		_retScanf	= scanf("%d", &resposta);
	} while(0 > resposta || resposta > contador);
	return resposta;
}
//Salva os dados atuais em disco.
void salvar(Frutas** lista) {
	FILE*	fp;
	Frutas*	fruta;
	Tipos*	tipo;
	fruta	= (*lista)->proximo_no;
	fp		= fopen(ARQUIVO, "w");
	while(fruta) {
		fprintf(fp, "#%s\n", fruta->nome);
		tipo	= fruta->variedade;
		while(tipo) {
			fprintf(fp, "$%s\n", tipo->nome);
			tipo = tipo->proximo_no;
		}
		fruta	= fruta->proximo_no;
	}
	fclose(fp);//TODO: arquivo salvo com sucesso
	return;
}

//Carrega os dados do disco para a memoria.
void carregar(Frutas** lista) {
	FILE* fp;
	int _retScanf;
	char dado[50];
	fp			= fopen(ARQUIVO, "r");
	while(0) {//not eof
		if(dado[0] == '#') {
			//criar nova fruta e add em lista
		}
		else {
			//criar nova variedade e add a fruta
		}
	}

	_retScanf	= fscanf(fp, "%s", dado);
	fclose(fp);
	return;
}