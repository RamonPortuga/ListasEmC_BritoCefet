#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int cont,valor;
	struct ptr*prox;
};
struct  ptr*inicio;
struct ptr* criar_lista();
void mostra();
void contador();
void media();
void maior_menor();
void apagar();
void remover(int cont);
void inserir_fim(int cont);
main(){
	inicio=(struct ptr*)NULL;
	inicio=criar_lista(inicio,inicio,inicio);
	mostra();
//	contador();
//	media();
//	maior_menor();
//	remover(-1);
//	mostra();
	inserir_fim(-1);
	mostra();
//	apagar();
//	mostra();
}
struct ptr* criar_lista(){
	struct ptr* aux,*inicio,* fim;
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	inicio=(struct ptr*)NULL;
	while(valor>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			fim=inicio;
		}
		else{
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=valor;
			aux->prox=inicio;
			inicio=aux;
		}
		printf("Entre com um valor:\t");
		scanf("%d",&valor);
	}
	fim->prox=inicio;
	aux=(struct ptr*)NULL;
	fim=(struct ptr*)NULL;
	return inicio;
}
void mostra(){
	struct ptr* aux;
	aux=inicio;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux->prox!=inicio){
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}
		if(aux->prox==inicio)
			printf("%d\t",aux->valor);
	}
}
void contador(){
	int cont;
	struct ptr* aux;
	aux=inicio;
	cont=0;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux->prox!=inicio){
			cont++;
			aux=aux->prox;
		}
		if(aux->prox==inicio){
			cont++;
			printf("\nEssa lista possui %d elementos",cont);
		}
	}
}
void media(){
	struct ptr* aux;
	int cont;
	float m;
	aux=inicio;
	cont=0;
	m=0;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux->prox!=inicio){
			cont++;
			m+=aux->valor;
			aux=aux->prox;
		}
		if(aux->prox==inicio){
			cont++;
			m+=aux->valor;
			m=m/cont;
			printf("\nA m%cdia dessa lista %c %f",130,130,m);
		}
	}
}
void maior_menor(){
	struct ptr* aux;
	int maior,menor;
	maior=-1;
	menor=-1;
	aux=inicio;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(maior==-1)
			maior=aux->valor;
		if(menor==-1)
			menor=maior;
		while(aux->prox!=inicio){
			if(aux->valor>maior)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			aux=aux->prox;
		}
		if(aux->prox==inicio){
			if(aux->valor>maior)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			printf("\nO maior elemento dessa lista %c\t%d",130,maior);
			printf("\nO menor elemento dessa lista %c\t%d",130,menor);
		}
	}
}
void remover(int cont){
	struct ptr*aux,*ant;
	aux=inicio;
	ant=inicio;
	if(cont<0){
		printf("\nEntre com o valor a ser removido:\t");
		scanf("%d", &cont);
	}
	if(inicio==(struct ptr *)NULL)
		printf("Lista vazia.");
	else{
		if(inicio->prox==inicio){
			if(inicio->valor!=cont)
				printf("Valor não consta.");
			else{
				free(inicio);
				inicio=(struct ptr *)NULL;
			}
		}
		else{
			while(aux->prox!=inicio){
				if((ant==inicio) && (aux->prox->valor==cont)){
					ant=aux;
				}
				aux=aux->prox;
			}
			if(aux->prox==inicio){
				if(inicio->valor==cont || ant->prox->valor==cont){
					if(inicio->valor==cont){
						inicio=inicio->prox;
						aux->prox=inicio;
						free(ant);
					}
					else{
						if(ant->prox->prox==inicio){
							ant->prox=inicio;
							free(aux);
						}
						else{
							aux=ant->prox;
							ant->prox=aux->prox;
							free(aux);
						}		
					}
				}
				else
					printf("O valor não existe.");		
			}
		}
		aux=(struct ptr *)NULL;
		ant=aux;
	}
}
void inserir_fim(int cont){
	struct ptr* aux;
	aux=inicio;
	if(cont<0){
		printf("\nEntre com um valor a ser inserido no fim:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		if(aux==(struct ptr*)NULL){
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=cont;
			aux->prox=aux;
		}
		else{
			while(aux->prox!=inicio)
				aux=aux->prox;
			if(aux->prox==inicio){
				aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux=aux->prox;
				aux->valor=cont;
				aux->prox=inicio;
				aux=(struct ptr*)NULL;
			}
		}
	}
}
void apagar(){
	struct ptr *aux,*ant;
	aux=inicio;
	ant=inicio;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux->prox!=inicio){
			ant=aux;
			aux=aux->prox;
		}
		if(ant!=aux)
			ant->prox=inicio;
		else
			inicio=(struct ptr*)NULL;
		free(aux);
		aux=(struct ptr*)NULL;
		ant=aux;
	}
}
