#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int cont,valor;
	struct ptr*prox;
};
struct  ptr*inicio;
//void criar_lista(struct ptr* aux,struct ptr* inicio,struct ptr* fim);
void mostra(struct ptr* aux);
void contador(struct ptr* aux,int cont);
main(){
	inicio=(struct ptr*)NULL;
//	criar_lista(inicio,inicio,inicio);
	mostra(inicio);
	contador(inicio,0);
}
//void criar_lista(struct ptr* aux,struct ptr*inicio,struct ptr* fim){
//	int valor;
//	printf("Entre com um valor:\t");
//	scanf("%d",&valor);
//	if(valor>=0){
//		if(inicio==(struct ptr*)NULL){
//			inicio=(struct ptr *)malloc(sizeof(struct ptr));
//			inicio->valor=valor;
//			criar_lista(inicio,inicio,inicio);
//			fim=inicio;
//		}
//		else{
//			aux=(struct ptr*)malloc(sizeof(struct ptr));
//			aux->valor=valor;
//			aux->prox=inicio;
//			inicio=aux;
//			fim->prox=inicio;
//		//	criar_lista(aux,inicio,fim);
//		}
//		aux=(struct ptr*)NULL;
//		inicio =criar_lista(aux,inicio,fim);
//		fim=(struct ptr*)NULL;
//	}
//	return inicio;
//}
struct ptr criar_lista(struct ptr aux,struct ptr*inicio,struct ptr* fim){
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			fim=inicio;
		}
		else{
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=valor;
			aux->prox=inicio;
			inicio=aux;
			fim->prox=inicio;
		}
		aux=(struct ptr*)NULL;
		inicio=criar_lista(aux,inicio,fim);
		fim=(struct ptr*)NULL;
	}
	return inicio;
}
void mostra(struct ptr* aux){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
		else{
			printf("%d\t",aux->valor);
		}
	}
}
void contador(struct ptr* aux,int cont){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio){
			cont++;
			mostra(aux->prox);
		}
		else{
			cont++;
			printf("%d",cont);
		}
	}
}
