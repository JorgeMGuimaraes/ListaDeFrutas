#include <stdio.h>
#include <stdlib.h>
#include "Nodes.h"

int main() {
	Frutas* lista = criaListaDeFrutas();
	printf("%s\n", lista->proximo_no->nome);
	adicionarVariedade(&lista);
	printf("Variedade %s\n", lista->proximo_no->variedade->nome);
	return 0;
}