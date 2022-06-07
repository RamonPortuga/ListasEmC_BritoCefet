#include <stdio.h>
struct ptr{
	int valor;
	struct ptr*prox,*ant;
};
struct desc{
	int cont;
	struct ptr*ini,*fim;
};
struct desc *inicio;
void criar_lista();
void mostra();
void inserir_ordenado();
main(){
	inicio=(struct desc*)malloc(sizeof (struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
	criar_lista();
	mostra();
	inserir_ordenado();
	mostra();
}
void criar_lista(){
	struct ptr*aux;
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	while(valor>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->prox=(struct ptr*)NULL;
			inicio->ini->ant=(struct ptr*)NULL;
			inicio->cont++;
			aux=inicio->ini;
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
		printf("Entre com um valor:\t");
		scanf("%d",&valor);
	}
	aux=(struct ptr*)NULL;
}
void inserir_ordenado(){
	struct ptr*aux,*ant;
	int cont;
	aux=inicio->ini;
	ant=inicio->ini;
	printf("\nEntre com o valor a ser inserido no ordenado:\t");
	scanf("%d",&cont);
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
				inicio->cont++;
			}
			else{
				while((cont>aux->valor)&&(aux->prox!=(struct ptr*)NULL)){
					ant=aux;
					aux=aux->prox;
				}
				if(aux->prox==(struct ptr*)NULL){
					if(cont>aux->valor){
						aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->valor=cont;
						aux->prox=(struct ptr*)NULL;
						aux->ant=inicio;
						inicio->cont++;
					}
					else{
						aux=(struct ptr*)malloc(sizeof(struct ptr));
						aux->valor=cont;
						aux->prox=ant->prox;
						ant->prox=aux;
						inicio->cont++;
					}
				}
				aux=(struct ptr*)NULL;
				ant=(struct ptr*)NULL;
			}
		}
	}
}
void mostra(){
	struct ptr*aux;
	aux=inicio->ini;
	if(aux==(struct ptr*)NULL)
		printf("\nA Quantidade de n%cs %c de:\t%d",162,130,inicio->cont);
	while(aux!=(struct ptr*)NULL){
		printf("%d\t",aux->valor);
		aux=aux->prox;
	}
	if(inicio->ini==(struct ptr*)NULL){
		printf("\nLista Vazia");
	}
}
