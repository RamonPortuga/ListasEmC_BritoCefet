#include<stdio.h>
struct ptr{
	int valor;
	struct ptr* prox,*ant;
};
struct ptr*inicio;
void inserir_ordenado(struct ptr* aux,struct ptr* ant,int cont);
void criar_lista(struct ptr* aux);
void mostra(struct ptr*aux);
main(){
	inicio=(struct ptr*)NULL;
	criar_lista(inicio);
	mostra(inicio);
	inserir_ordenado(inicio,inicio,-1);
	mostra(inicio);
}

void criar_lista(struct ptr*aux){
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->ant=(struct ptr*)NULL;
		aux->prox=inicio;
		if(inicio!=(struct ptr*)NULL)
			inicio->ant=aux;
		inicio=aux;
		aux=(struct ptr*) NULL;
		criar_lista(aux);
	}
		aux=(struct ptr*)NULL;
}
void mostra(struct ptr* aux){
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
	}
}
void inserir_ordenado(struct ptr*aux,struct ptr*ant,int cont){
	if(cont<0){
		printf("\nEntre com um valor a ser inserido:\t");
		scanf("%d",&cont);
	}
	if(cont>0){
		if(inicio==(struct ptr *)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor=cont;
			inicio->prox=aux;
			inicio->ant=(struct ptr*)NULL;
			printf("\nEI-1\n");
		}
		else{
			if(inicio->valor>cont){
				inicio=(struct ptr *)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=cont;
				inicio->ant=(struct ptr*)NULL;
				aux->ant=inicio;
				inicio->prox->ant=inicio;
				printf("\nEI-2\n");	
			}
			else{
				if((cont>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					inserir_ordenado(aux->prox,ant,cont);
				}
				else{
					if(cont<aux->valor){
						ant->prox=(struct ptr *)malloc(sizeof(struct ptr));
						ant=ant->prox;
						ant->valor=cont;
						ant->prox=aux;
						printf("\nEI-3\n");
					}
					else{
						aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->valor=cont;
						aux->prox=(struct ptr*)NULL;
						printf("\nEI-4\n");
					}
				}
			}
		}
		aux=(struct ptr *)NULL;
		ant=(struct ptr *)NULL;
		}
}
