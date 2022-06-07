#include<stdio.h>
struct ptr{
	int valor;
	struct ptr* prox,*ant;
};
struct ptr* inicio;
void criar_lista();
void mostra(struct ptr* aux);
main(){
	inicio=(struct ptr*)NULL;
	criar_lista();
	mostra(inicio);
}
void criar_lista(){
	struct ptr*fim,*primeiro;
	fim=inicio;
	primeiro=inicio;
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=inicio;
			inicio->ant=inicio;
			fim=inicio;
			primeiro=inicio;
			printf("Entre com um valor:\t");
			scanf("%d",&valor);
			while(valor>=0){
				fim->prox=(struct ptr*)malloc(sizeof(struct ptr));
				fim=fim->prox;
				fim->valor=valor;
				fim->ant=primeiro->ant;
				fim->prox=primeiro;
				printf("Entre com um valor:\t");
				scanf("%d",&valor);
			}
		}
		fim=(struct ptr*)NULL;
	}
}
void mostra(struct ptr*aux){
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
		if(aux->prox==inicio)
			printf("%d",aux->valor);
	}
}
