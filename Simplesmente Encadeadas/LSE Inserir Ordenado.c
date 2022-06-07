#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int valor;
	struct ptr *prox;
};
struct ptr*inicio;
void inserir_ordenado(struct ptr *aux, struct ptr*ant,int valor);
void criar_lista();
void mostra();
main(){
	inicio=(struct ptr*)NULL;
	criar_lista();
	mostra();
	inserir_ordenado(inicio,inicio,-1);
	mostra();
}
void criar_lista(){
	struct ptr*aux;
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	while(valor>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=(struct ptr*)NULL;
			aux=inicio;
		}
		else{
			if(aux->prox==(struct ptr*)NULL){
				aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct ptr*)NULL;
			}
		}
		printf("Entre com um valor:\t");
		scanf("%d",&valor);
	}
}
void mostra(){
	struct ptr*aux;
	aux=inicio;
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}
	}
}
void inserir_ordenado(struct ptr*aux,struct ptr*ant,int valor){
	if(valor<0){
		printf("\nEntre com o valor a ser inserido no ordenado:\t");
		scanf("%d",&valor);
	}
	if(valor>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=(struct ptr*)NULL;
		}
		else{
			if(inicio->valor>valor){
				inicio=(struct ptr*)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=valor;
				aux=(struct ptr*)NULL;
			}
			else{
				if((valor>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					inserir_ordenado(aux->prox,ant,valor);
				}
				else{
					if(valor>aux->valor){
						aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->valor=valor;
						aux->prox=(struct ptr*)NULL;
					}
					else{
						aux=(struct ptr*)malloc(sizeof(struct ptr));
						aux->valor=valor;
						aux->prox=ant->prox;
						ant->prox=aux;
					}
				}
				aux=(struct ptr*)NULL;
				ant=(struct ptr*)NULL;
			}
		}
	}
}
/*void inserir_ordenado(struct ptr* aux, struct ptr*ant,int valor){
	if(valor<0){
		printf("\nEntre com um valor a ser inserido na ordenada:\t");
		scanf("%d", &valor);
	}
	if (valor>=0){
		if(inicio==(struct ptr *)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=(struct ptr*)NULL;
		}
		else{
		//	aux=inicio;
			if(inicio->valor>valor){
				inicio=(struct ptr *)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=valor;
				aux=(struct ptr*)NULL;
			}
			else{
				if((valor>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					inserir_ordenado(aux->prox,ant,valor);
				}
				if(valor>aux->valor){
					aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
					aux=aux->prox;
					aux->valor=valor;
					aux->prox=(struct ptr*)NULL;
				}
				else{
					aux=(struct ptr *)malloc(sizeof(struct ptr));
					aux->valor=valor;
					aux->prox=ant->prox;
					ant->prox=aux;
				}
				aux=(struct ptr *)NULL;
				ant=(struct ptr *)NULL;
			}
		}
	}
}*/
/*void inserir_ordenado(){
	struct ptr *aux, *ant;
	int valor;
	printf("\nEntre com um valor a ser inserido na ordenada:\t");
	scanf("%d", &valor);
	if(inicio==(struct ptr *)NULL){
		inicio=(struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->prox=(struct ptr*)NULL;
	}
	else{
		aux=inicio;
		if(inicio->valor>valor){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->prox=aux;
			inicio->valor=valor;
			aux=(struct ptr*)NULL;
		}
		else{
			while((valor>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
				ant=aux;
				aux=aux->prox;
			}
			if(valor>aux->valor){
				aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct ptr*)NULL;
			}
			else{
				aux=(struct ptr *)malloc(sizeof(struct ptr));
				aux->valor=valor;
				aux->prox=ant->prox;
				ant->prox=aux;
			}
			aux=(struct ptr *)NULL;
			ant=(struct ptr *)NULL;
		}
	}
}*/

