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
		printf("\n  [%d] - Adicionar fruta ao inventario\n",		ADICIONAR_FRUTA);
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
			fprintf(fp, "%s\n", tipo->nome);
			tipo = tipo->proximo_no;
		}
		fruta	= fruta->proximo_no;
	}
	fclose(fp);
	printf("Dados salvos com sucesso.\n\n");
	return;
}

//Carrega os dados do disco para a memoria.
void carregar(Frutas** lista) {
	FILE*	fp;
	int
			_retScanf,
			i,
			indice = 0;
	char
			dado[LIMITE_NOME],
			nome[LIMITE_NOME];
	fp			= fopen(ARQUIVO, "r");
	(*lista)	= criaListaDeFrutas();
	_retScanf	= fscanf(fp, "%s", dado);
	while(_retScanf > 0) {
		if(dado[0] == '#') {
			i			= 1;
			while(dado[i] != '\0') {
				nome[i - 1] = dado[i];
				++i;
			}
			nome[i - 1] = '\0';
			adicionarFruta(lista, nome);
		}
		else {
			Frutas* f;
			f			= getFruta(lista, indice);
			adicionarVariedade(&f, dado);
		}
		_retScanf		= fscanf(fp, "%s", dado);
	}
	fclose(fp);
	return;
}