#include <stdio.h>
struct ptr{
	int valor;
	struct ptr*prox,*ant;
};
struct ptr* inicio;
void cria_lista(struct ptr*fim);
void mostra(struct ptr*aux);
main(){
	inicio=(struct ptr*)NULL;
	cria_lista(inicio);
	mostra(inicio);
}
void cria_lista(struct ptr* fim){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->ant=(struct ptr*)NULL;
			inicio->prox=(struct ptr*)NULL;
			fim=inicio;
		}
		else{
			fim->prox=(struct ptr*)malloc(sizeof(struct ptr));
			fim->prox->ant=fim;
			fim=fim->prox;
			fim->valor=valor;
		//	printf("\n%d\n",fim->valor);
			fim->prox=(struct ptr*)NULL;
		}
		cria_lista(fim);
		fim=(struct ptr*)NULL;
	}
}
void mostra(struct ptr*aux){
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
	}
}

