#include <stdio.h>
struct ptr{
	int valor;
	struct ptr* prox,*ant;
};
struct desc{
	int cont;
	struct ptr* ini,*fim;
};
struct desc* inicio;
void criar_lista();
void mostra(struct ptr*aux);
main(){
	inicio=(struct ptr*)malloc(sizeof(struct ptr));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	criar_lista();
	mostra(inicio->ini);
}
void criar_lista(){
	void crescente(int valor){
		struct ptr*aux,*ant;
		aux=inicio->ini;
		ant=inicio->ini;
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->prox=(struct ptr*)NULL;
			inicio->ini->ant=(struct ptr*)NULL;
		}
		else{
			if(inicio->ini->valor>valor){
				inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
				inicio->ini->valor=valor;
				inicio->ini->prox=aux;
				inicio->ini->ant=(struct ptr*)NULL;
				aux->ant=inicio->ini;
				inicio->ini->prox->ant=inicio->ini;
			}
			else{
				while((valor>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					aux=aux->prox;
				}
					if(valor<aux->valor){
						ant->prox=(struct ptr*)malloc(sizeof(struct ptr));
						ant=ant->prox;
						ant->valor=valor;
						ant->prox=aux;
					}
					else{
						aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->valor=valor;
						aux->prox=(struct ptr*)NULL;
						inicio->fim=aux;
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
		mostra(inicio->ini);
		printf("\n\n");
		criar_lista();
	}
}
void mostra(struct ptr*aux){
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
	}
}
