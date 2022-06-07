#include <stdio.h>
#include<stdlib.h>
struct ptr{
	int valor,cont;
	struct ptr*prox;
	struct ptr* ant;
};
struct ptr* inicio;
void cria_lista_dupla_inv();
void mostra();
void contador();
void media();
void maior_menor();
void inserir_fim(int cont);
void inserir_ordenada_dupla();
void remover(int cont);
void apaga_lista();
main(){
	cria_lista_dupla_inv();
	mostra();
//	contador();
//	media();
//	maior_menor();
//	inserir_fim(-1);
//	mostra();
//	apaga_lista();
//	mostra();
	remover(-1);
	mostra();
}
void cria_lista_dupla_inv(){
	struct ptr*aux;
	int valor;
	inicio=(struct ptr*) NULL;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		inicio=(struct ptr*)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->ant=(struct ptr*)NULL;
		inicio->prox=inicio->ant;
		printf("Entre com um valor:\t");
		scanf("%d",&valor);
		while(valor>=0){
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=valor;
			aux->ant=(struct ptr*)NULL;
			aux->prox=inicio;
			inicio->ant=aux;
			inicio=aux;
			printf("Entre com um valor:\t");
			scanf("%d",&valor);
		}
		aux=(struct ptr*)NULL;
	}
}

void mostra(){
	struct ptr* aux;
	aux=inicio;
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia\n");
	else{
		while(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}
	}
}
void contador(){
	int cont;
	struct ptr* aux;
	aux=inicio;
	cont=0;
	while (aux!=(struct ptr*)NULL){
		cont++;
		aux=aux->prox;
	}
	if(cont==0)
		printf("\nLista Vazia");
	else{
		printf("\nA quantidade de elementos dessa lista e:\t%d",cont);
	}
}
void media(){
	float m;
	int cont;
	struct ptr* aux;
	aux=inicio;
	while(aux!=(struct ptr*)NULL){
		cont++;
		m+=aux->valor;
		aux=aux->prox;
	}
	if(cont==0)
		printf("\nA media dos elementos e igual a 0");
	else{
		printf("\nA media e:\t%f",m/cont);
	}
}
void maior_menor(){
	int maior,menor;
	struct ptr* aux;
	aux=inicio;
	if((struct ptr*)NULL){
		printf("\nLista Vazia\n");
	}
	else{
		maior=aux->valor;
		menor=maior;
		while(aux!=(struct ptr*)NULL){
			if(maior<aux->valor)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			aux=aux->prox;
		}
	}
	aux=(struct ptr*)NULL;
	printf("\nO maior valor e:\t%d\n",maior);
	printf("\nO menor valor e:\t%d",menor);
}
void inserir_fim(int cont){
	struct ptr* aux;
	aux=inicio;
	if(cont<0){
		printf("\nEntre com o valor a ser inserido no final da lista:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		printf("\nEI");
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof (struct ptr));
			inicio->prox=(struct ptr*)NULL;
			inicio->cont=cont;
			printf("\nEI");
		}
		else{
			while(aux->prox!=(struct ptr*)NULL){
				aux=aux->prox;
				printf("\nEI\n\n");
			}
			printf("\nEI2");
			aux->prox=(struct ptr*)malloc(sizeof (struct ptr));
			aux=aux->prox;
			aux->valor=cont;
			aux->prox=(struct ptr*)NULL;
			aux=(struct ptr*)NULL;
		}
	}
}
void remover(int cont){
	struct ptr*aux;
	aux=inicio;
	if(cont<0){
		printf("\nEntre com o valor a ser removido:\t");
		scanf("%d", &cont);
	}
	if(inicio==(struct ptr *)NULL)
		printf("Lista vazia.");
	else{
		if(inicio->prox==(struct ptr *)NULL){
			if(inicio->valor!=cont)
				printf("Valor não consta.");
			else{
				free(inicio);
				inicio=(struct ptr *)NULL;
			}
		}
		else{
			if(inicio->valor==cont){
				inicio=inicio->prox;
				aux->prox=(struct ptr *)NULL;
				free(aux);
			}
			else{
				while((cont!=aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					aux->ant=aux;
					aux=aux->prox;
				}
//				if(aux->valor!=cont)
//					printf("O valor não existe.");
//				else{
					if(aux->prox==(struct ptr *)NULL){
						aux->ant->prox=(struct ptr *)NULL;
						free(aux);
					}
					else{
						aux->ant->prox=aux->prox;
						aux->prox->ant=aux->ant;
						free(aux);
					}
//				}
			}
		}
		aux=(struct ptr *)NULL;
//		aux->ant=aux;
	}
}
void apaga_lista(){
	struct ptr *aux;
	aux=inicio;
	while(aux!=(struct ptr *)NULL){
		inicio=inicio->prox;
		aux->prox=(struct ptr *)NULL;
		free(aux);
		aux=inicio;
	}
}
