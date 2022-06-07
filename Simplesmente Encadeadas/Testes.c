#include<stdio.h>
struct ptr{
	int valor;
	struct ptr*prox;
};
struct ptr*inicio;
void criar_lista(struct ptr*aux);
void mostra(struct ptr*aux);
main(){
	inicio=(struct ptr*)NULL;
	criar_lista(inicio);
	mostra(inicio);
}
void criar_lista(struct ptr*aux){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		aux=(struct ptr*)NULL;
		criar_lista(aux);
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
