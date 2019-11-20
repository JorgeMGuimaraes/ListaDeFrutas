#pragma once
#include "Nodes.h"
#define ARQUIVO				"data.fruit"
#define MARCADOR_FRUTA		'#'
#define MARCADOR_VARIEDADE	'$'
#define ADICIONAR_FRUTA		1
#define ADICIONAR_VARIEDADE	2
#define IMPRIMIR_INVENTARIO	3
#define SALVAR_DADOS		4
#define SAIR				5

void boasVindas();
int menuSelecao();
void salvar(Frutas** lista);
void carregar(Frutas** lista);