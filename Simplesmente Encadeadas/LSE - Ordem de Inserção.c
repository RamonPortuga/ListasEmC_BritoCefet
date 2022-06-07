//10) Criação de uma L.S.E; na ordem em que os elementos foram inseridos:

#include <stdio.h>
#include<stdlib.h>
int valor;
struct ptr{
	int valor;
	struct ptr*prox;
};
struct ptr* inicio;
struct ptr* inverso(struct ptr* aux, struct ptr* inicio);
//void mostra(struct ptr*aux), contador(struct ptr*aux,int cont), inserir_fim(struct ptr *aux,int valor);
//void media(struct ptr* aux, int cont,float m), maior_menor(struct ptr*aux,int maior,int menor);
//void inserir_ordenado(struct ptr *aux, struct ptr *ant, int valor), remover(struct ptr* aux, struct ptr* ant,int valor,int cont);
main(){
	cria_lista();
	mostra();
	apaga_lista();
	mostra();
}
void cria_lista(){
	int valor;
	struct ptr *fim;
	printf("Entre com o valor: ");
	scanf("%d",&valor);
	inicio=(struct ptr *)NULL;
	fim=inicio;
	if(valor>=0){
		inicio=(struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->prox=(struct ptr *)NULL;
		printf("Entre com o valor: ");
		scanf("%d", &valor);
		fim=inicio;
		while(valor>=0){
			fim->prox=(struct ptr *)malloc(sizeof(struct ptr));
			fim=fim->prox;
			fim->valor=valor;
			fim->prox=(struct ptr *)NULL;
			printf("Entre com o valor: ");
			scanf("%d", &valor);
		}
		fim=(struct ptr *)NULL;
	}
}
void mostra(){
	struct ptr *aux;
	aux=inicio;
	if(inicio==(struct ptr *)NULL)
		printf("\nLISTA VAZIA");
	else{
		while(aux!=(struct ptr *)NULL){
			printf("%d\t", aux->valor);
			aux=aux->prox;
		}
	}
}
//	11) Apagar a L.S.E. da memória: 

void apaga_lista(){
	struct ptr *aux;
	aux=inicio;
	while(aux!=(struct ptr *)NULL){
		inicio=inicio->prox;
		aux->prox=(struct ptr *)NULL;
		free(aux);
		aux=inicio;
	}
}
