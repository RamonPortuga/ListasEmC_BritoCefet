#include<stdio.h>
struct ptr{
	int valor;
	struct ptr* prox,*ant;
};
struct ptr*inicio;
void criar_lista(struct ptr*aux);
void mostra(struct ptr*aux);
void inserir_ordenado(struct ptr*aux,struct ptr*ant,int cont);
main(){
	inicio=(struct ptr*)NULL;
	criar_lista(inicio);
	mostra(inicio);
	inserir_ordenado(inicio,inicio,-1);
	mostra(inicio);
}
void criar_lista(struct ptr*aux){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=(struct ptr*)NULL;
			inicio->ant=(struct ptr*)NULL;
			aux=inicio;
		}
		else{
			if(aux->prox==(struct ptr*)NULL){
				aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux->prox->ant=aux;
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct ptr*)NULL;
			}
		}
		criar_lista(aux);
		aux=(struct ptr*)NULL;
	}
}
void mostra(struct ptr*aux){
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
		printf("\nEntre com o valor a ser inserido no ordenado:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->valor=cont;
			inicio->prox=(struct ptr*)NULL;
			inicio->ant=(struct ptr*)NULL;
		}
		else{
			aux=inicio;
			if(inicio->valor>cont){
				printf("\nEI");
				inicio=(struct ptr*)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=cont;
				inicio->ant=(struct ptr*)NULL;
				aux=(struct ptr*)NULL;
			}
			else{
				if((cont>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					inserir_ordenado(aux,ant,cont);
				}
				else{
					if(cont>aux->valor){
						aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->valor=cont;
						aux->prox=(struct ptr*)NULL; //Observar pois aqui pode ser recebendo aux ou inicio;
						aux->ant=inicio;
					}
					else{
						aux=(struct ptr *)malloc(sizeof(struct ptr));
						aux->valor=cont;
						aux->prox=ant->prox;
						ant->prox=aux;
					}
				}
			}
		}
	}
}
