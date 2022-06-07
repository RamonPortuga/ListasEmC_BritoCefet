#include<stdio.h>
struct ptr{
	int valor;
	struct ptr* prox;
};
struct ptr*inicio;
void criar_lista(struct ptr*aux,struct ptr*fim);
void mostra(struct ptr*aux);
void inserir_ordenado(struct ptr*aux,struct ptr*ant,int cont);
main(){
	inicio=(struct ptr*)NULL;
	criar_lista(inicio,inicio);
	mostra(inicio);
	inserir_ordenado(inicio,inicio,-1);
	mostra(inicio);
}
void criar_lista(struct ptr*aux,struct ptr*fim){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=inicio;
			aux=inicio;
		}
		else{
		//	printf("\nEI");
			aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=inicio;
		//	aux=inicio;
		}
		criar_lista(aux,fim);
		aux=(struct ptr*)NULL;
	}
}
void mostra(struct ptr*aux){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
		else
			printf("%d\t",aux->valor);
	}
}
void inserir_ordenado(struct ptr*aux,struct ptr*ant,int cont){
	if(cont<0){
		printf("\nEntre com o valor a ser inserido no ordenado:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->prox=inicio;
			inicio->valor=cont;
		}
		else{
			if(inicio->valor>cont){
				inicio=(struct ptr*)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=cont;
			//	aux=(struct ptr*)NULL;
			}
			else{
				if((cont>inicio->valor)&&(aux->prox!=inicio)){
					printf("\nEI\n");
					ant=aux;
					inserir_ordenado(aux->prox,ant,cont);
				}
				else{
					if(cont>aux->valor){
						aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->valor=cont;
						aux->prox=inicio;
					}
					else{
						aux=(struct ptr*)malloc(sizeof(struct ptr));
						aux->valor=cont;
						aux->prox=ant->prox;
						ant->prox=aux;
					}
				}
			}
			aux=(struct ptr*)NULL;
			ant=(struct ptr*)NULL;
		}
	}
}
