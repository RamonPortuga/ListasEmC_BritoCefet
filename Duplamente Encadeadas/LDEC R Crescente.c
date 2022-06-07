#include<stdio.h>
struct ptr{
	int valor;
	struct ptr*prox,*ant;
};
struct ptr*inicio;
void criar_lista();
void mostra(struct ptr*aux);
main(){
	inicio=(struct ptr*)NULL;
	criar_lista();
	mostra(inicio);
}
void criar_lista(){
	int valor;
	void criar_lista2(struct ptr* aux,struct ptr*fim,struct ptr*ant,int valor ){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=(struct ptr*)NULL;
		}
		else{
			if(inicio->valor>valor){
				inicio=(struct ptr*)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=valor;
			}
			else{
				if((valor>aux->valor)&&(aux->prox!=(struct ptr*)NULL)){
					ant=aux;
					criar_lista2(aux->prox,fim,ant,valor);
				}
				else{
					if(valor<aux->valor){
						ant->prox=(struct ptr*)malloc(sizeof (struct ptr));
						ant=ant->prox;
						ant->valor=valor;
						ant->prox=aux;
					}
					else{
						aux->prox=(struct ptr*)malloc(sizeof (struct ptr));
						aux=aux->prox;
						aux->prox=inicio;
						aux->valor=valor;
						fim=aux;
					}
				}
			}
		}
	aux=(struct ptr*)NULL;
	ant=(struct ptr*)NULL;
	}
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		criar_lista2(inicio,inicio,inicio,valor);
		printf("\n\n");
		mostra(inicio);
		printf("\n");
		criar_lista();
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
