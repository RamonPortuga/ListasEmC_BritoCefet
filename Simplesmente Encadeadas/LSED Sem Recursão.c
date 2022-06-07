#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int valor;
	struct ptr *prox;
};
struct desc{
	int cont;
	struct ptr *ini, *fim,*prox;
};
struct desc *inicio;

//void criar_lista();
void criar_lista(struct ptr* aux);
void mostra();
void media();
void contador();
void maior_menor();
void inserir_fim();
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
//	criar_lista();
	criar_lista(inicio->ini);
	mostra();
//	contador();
//	media();
//	maior_menor();
//	inserir_fim();
//	mostra();
}
/*void criar_lista(){
	struct ptr*aux;
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	while(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox = inicio->ini;
		inicio->ini=aux;
		inicio->cont++;
		if(inicio->fim == (struct ptr*)NULL)
			inicio->fim=aux;
		aux=(struct ptr*)NULL;
	}
}*/
void criar_lista(struct ptr*aux){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox = inicio->ini;
		inicio->ini=aux;
		inicio->cont++;
		if(inicio->fim == (struct ptr*)NULL)
			inicio->fim=aux;
		aux=(struct ptr*)NULL;
		criar_lista(aux);
	}
}
void mostra(){
	struct ptr*aux;
	if(aux==inicio->ini)
		printf("Quantidade de nos: %d.\n", inicio->cont);
	while(aux!=(struct ptr*)NULL){
		printf("%d\t",aux->valor);
	}
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
}
