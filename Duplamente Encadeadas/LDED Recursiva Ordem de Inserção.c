#include<stdio.h>
struct ptr{
	int valor;
	struct ptr* prox,*ant;
};
struct desc{
	int cont;
	struct ptr* ini,*fim;
};
struct desc* inicio;
void cria_lista(struct ptr* fim);
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
	criar_lista(inicio->ini);
	mostra(inicio->ini);
}
void criar_lista(struct ptr*fim){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->prox=(struct ptr*)NULL;
			inicio->ini->ant=(struct ptr*)NULL;
			inicio->cont++;
			inicio->fim=fim;
			fim=inicio->ini;
		}
		else{
			fim->prox=(struct ptr*)malloc(sizeof(struct ptr));
			fim->prox->ant=fim;
			fim=fim->prox;
			fim->valor=valor;
			inicio->cont++;
			inicio->fim=fim;
			fim->prox=(struct ptr*)NULL;
		}
		criar_lista(fim);
		fim=(struct ptr*)NULL;
	}
}
void mostra(struct ptr* aux){
	if(inicio->ini=(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
	}
}
