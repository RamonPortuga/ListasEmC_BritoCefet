#include<stdio.h>
struct ptr{
	int valor;
	struct ptr*prox;
};
struct desc{
	int cont;
	struct ptr*ini,*fim;
};
struct desc* inicio;
void criar_lista();
void mostra();
void inserir_ordenado();
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
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
	aux=inicio->ini;
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	while(valor>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->prox=(struct ptr*)NULL;
			aux=inicio->ini;
		}
		else{
			if(aux->prox==(struct ptr*)NULL){
				aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct ptr*)NULL;
			}
		}
		printf("Entre com o valor:\t");
		scanf("%d",&valor);
	}
}
void mostra(){
	struct ptr*aux;
	aux=inicio->ini;
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(inicio->cont!=0)
			printf("\nA quantidade de nos nessa lista %c\t:\t%d",130,inicio->cont);
		while(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}
	}
}
void inserir_ordenado(){
	int valor;
	struct ptr*aux,*ant;
	aux=inicio->ini;
	ant=inicio->ini;
	printf("\nEntre com um valor a ser inserido no ordenado:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->prox=(struct ptr*)NULL;
		}
		else{
			if(inicio->ini->valor>valor){
				inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
				inicio->ini->prox=aux;
				inicio->ini->valor=valor;
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
	}
}
