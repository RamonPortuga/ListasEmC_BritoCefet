#include<stdio.h>
struct ptr{
	int valor;
	struct ptr*prox;
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
	void crescente(int valor){
		struct ptr*aux,*ant,*fim;
		aux=inicio;
		ant=inicio;
		fim=inicio;
		if(inicio==(struct ptr *)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=inicio;
		}
		else{
			if(inicio->valor>valor){
				inicio=(struct ptr *)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=valor;	
			}
			else{
				while((valor>aux->valor)&&(aux->prox!=inicio)){
					ant=aux;
					aux=aux->prox;
				}
				if(valor<aux->valor){
					ant->prox=(struct ptr *)malloc(sizeof(struct ptr));
					ant=ant->prox;
					ant->valor=valor;
					ant->prox=aux;
				}
				else{
					aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
					aux=aux->prox;
					aux->prox=inicio;
					aux->valor=valor;
					fim=aux;
				}
			}
		}
	aux=(struct ptr *)NULL;
	ant=(struct ptr *)NULL;
	}
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		crescente(valor);
		printf("\n");
		mostra(inicio);
		printf("\n\n");
		criar_lista();
	}
}
void mostra(struct ptr* aux){
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
