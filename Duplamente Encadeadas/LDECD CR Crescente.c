#include <stdio.h>
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
void mostra(struct ptr*aux);
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
	criar_lista();
	mostra(inicio->ini);
}
void criar_lista(){
	void crescente(struct ptr *aux,struct ptr*fim, int valor){
		if(inicio->ini==(struct ptr *)NULL){
			inicio->ini=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->prox=inicio->ini;
		}
		else{
			if(inicio->ini->valor>valor){
				inicio->ini=(struct ptr *)malloc(sizeof(struct ptr));
				inicio->ini->prox=aux;
				inicio->ini->valor=valor;	
			}
			else{
				if((valor>aux->valor)&&(aux->prox!=inicio->ini)){
					aux->ant=aux;
					crescente(aux->prox,fim,valor);
				}
				else{
					if(valor<aux->valor){
						aux->ant->prox=(struct ptr *)malloc(sizeof(struct ptr));
						aux->ant=aux->ant->prox;
						aux->ant->valor=valor;
						aux->ant->prox=aux;
					}
					else{
						aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->prox=inicio->ini;
						aux->valor=valor;
						fim=aux;
					}
				}
			}
		}
	aux=(struct ptr *)NULL;
//	aux->ant=(struct ptr *)NULL;
	}
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		crescente(inicio->ini, inicio->ini,valor);
		printf("\n");
		mostra(inicio->ini);
		printf("\n\n");
		criar_lista();
	}
}
void mostra(struct ptr* aux){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio->ini){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
		else
			printf("%d\t",aux->valor);
	}
}
