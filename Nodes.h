#pragma once

//No principal de frutas. Gurda lista de frutas por variedade.
typedef struct NODE_FRUTAS {
	char nome[50];
	struct NODE_FRUTAS* proximo_no;
	struct NODE_VARIEDADE* variedade;
}Frutas;

//No secundario de frutas, com as variedades de frutas, uma por no.
typedef struct NODE_VARIEDADE{
	char nome[50];
	struct NODE_VARIEDADE* proximo_no;
}Tipos;