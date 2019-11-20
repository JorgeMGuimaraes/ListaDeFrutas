#include <stdio.h>
#include <stdlib.h>
#include "Nodes.h"

int main() {
	int retScanf;
	Frutas* banana, * uva;
	banana	= (Frutas*)malloc(sizeof(Frutas));
	uva		= (Frutas*)malloc(sizeof(Frutas));

	Tipos* prata, * italia;
	prata = (Tipos*)malloc(sizeof(Tipos));
	italia = (Tipos*)malloc(sizeof(Tipos));
	//TODO: Check null
	retScanf = scanf("%s %s", banana->nome, uva->nome);
	retScanf = scanf("%s %s", prata->nome, italia->nome);

	banana->proximo_no	= uva;
	banana->variedade = prata;
	uva->proximo_no		= NULL;
	uva->variedade = italia;

	printf("\n%s eh uma fruta e %s tambem.\n", banana->nome, banana->proximo_no->nome);
	printf("%s e %s sao tipos de frutas.\n", banana->variedade->nome, uva->variedade->nome);
	return 0;
}