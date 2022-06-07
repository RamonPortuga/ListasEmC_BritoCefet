#include<stdio.h>
#include <stdlib.h>
struct ptr{
	int cont,valor;
	struct ptr* prox;
};
void criar_lista(struct ptr* aux);
main(){
	inicio=(struct ptr*)NULL;
	criar_lista(inicio);
}
void criar_lista(struct ptr* aux){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox=(struct ptr*)NULL;
		criar_lista(inicio);
	}
}
