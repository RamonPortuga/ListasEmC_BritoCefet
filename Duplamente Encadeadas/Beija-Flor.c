#include <stdio.h>
struct ptr{
	int valor;
	struct ptr*prox,*ant;
};
struct desc{
	int cont;
	struct ptr*ini,*fim;
};
struct desc*inicio;
void criar_lista(struct ptr* aux);
void mostra(struct ptr*aux);
void inserir_ordenado(struct ptr*aux,struct ptr*ant,int cont);
main(){
	inicio=(struct desc*)malloc(sizeof (struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
	criar_lista(inicio->ini);
	inserir_ordenado(inicio->ini,inicio->ini,-1);
	mostra(inicio->ini);
}
void criar_lista(struct ptr*aux){
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->prox=(struct ptr*)NULL;
			inicio->ini->ant=(struct ptr*)NULL;
			inicio->cont++;
			aux=inicio;
		}
		else{
			if(aux->prox==(struct ptr*)NULL){
				aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux->ant=aux;
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct ptr*)NULL;
				inicio->cont++;
			}
		}
		criar_lista(aux);
		aux=(struct ptr*)NULL;
	}
}
void inserir_ordenado(struct ptr*aux,struct ptr*ant,int cont){
	if(cont<0){
		printf("Entre com o valor a ser inserido no ordenado:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=cont;
			inicio->ini->prox=(struct ptr*)NULL;
			inicio->ini->ant=(struct ptr*)NULL;
			inicio->cont++;
		}
		else{
			if(inicio->ini->valor>cont){
				inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
				inicio->ini->prox=aux;
				inicio->ini->valor=cont;
				inicio->ini->ant=(struct ptr*)NULL;
				aux=(struct ptr*)NULL;
			}
			else{
				if((cont>aux->valor)&&(aux->prox!=(struct ptr*)NULL)){
					ant=aux;
					inserir_ordenado(aux->prox,ant,cont);
				}
				else{
					if(cont>aux->valor){
						aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->valor=cont;
						aux->prox=(struct ptr*)NULL;
						aux->ant=inicio;
					}
					else{
						aux=(struct ptr*)malloc(sizeof(struct ptr));
						aux->valor=cont;
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
void mostra(struct ptr*aux){
	if(aux!=(struct ptr*)NULL){
		printf("%d\t",aux->valor);
		mostra(aux->prox);
	}
	if(inicio->ini==(struct ptr*)NULL){
		printf("\nLista Vazia");
	}
}
