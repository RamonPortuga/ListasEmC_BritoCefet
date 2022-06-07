#include<stdio.h>
struct ptr{
	int valor;
	struct ptr* prox,*ant;
};
struct desc{
	int cont;
	struct ptr*ini,*fim;
};
struct desc*inicio;
void criar_lista();
void mostra(struct ptr* aux);
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
	criar_lista();
	mostra(inicio->ini);
}
void criar_lista(struct ptr* fim,struct ptr* primeiro){
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->prox=inicio->ini;
			inicio->ini->ant=inicio->ini;
			fim=inicio->ini;
			primeiro=inicio->ini;
			inicio->cont++;
			printf("Entre com um valor:\t");
			scanf("%d",&valor);
			while(valor>=0){
				fim->prox=(struct ptr*)malloc(sizeof(struct ptr));
				fim=fim->prox;
				fim->valor=valor;
				fim->prox=primeiro;
				fim->ant=primeiro->ant;
				inicio->cont++;
				printf("Entre com um valor:\t");
				scanf("%d",&valor);
			}
		}
		fim=(struct ptr*)NULL;
	}
}
void mostra(struct ptr*aux){
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio->ini){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
		else
			printf("%d",aux->valor);
	}
}
