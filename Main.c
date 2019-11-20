#include <stdio.h>
#include <stdlib.h>
#include "Nodes.h"

int main() {
	Frutas* lista = criaListaDeFrutas();
	adicionarVariedade(&lista);
	imprimirLista(&lista);
	return 0;
}