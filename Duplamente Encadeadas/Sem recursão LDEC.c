#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int cont,valor;
	struct ptr*prox,*ant;
};
struct ptr*inicio;
//void criar_lista();
struct ptr* criar_lista(struct ptr* aux,struct ptr* fim);
void mostra();
void contador();
void media();
void maior_menor();
void inserir_fim();
void apagar();
void remover(int cont);
main(){
	inicio=(struct ptr*)NULL;
	inicio=criar_lista(inicio,inicio);
//	criar_lista(inicio,inicio,inicio);
	mostra();
//	contador();
//	media();
//	maior_menor();
//	inserir_fim();
//	mostra();
//	remover(-1);
//	mostra();
	apagar();
	mostra();
}
struct ptr* criar_lista(struct ptr* aux, struct ptr* inicio){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->ant=inicio;
			inicio->prox=inicio;
		}
		else{
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=valor;
			aux->ant=inicio->ant;
			aux->ant->prox=aux;
			aux->prox=inicio;
			inicio->ant=aux;
			inicio=aux;
		}
		aux=(struct ptr*)NULL;
		inicio=criar_lista(aux,inicio);
	}
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
	struct ptr* aux;
	aux=inicio;
	int cont;
	cont=0;
	if(aux==(struct ptr*)NULL){
		printf("\nLista Vazia");
	}
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
	aux=inicio;
	int cont;
	float m;
	cont=0;
	m=0;
	if(aux==(struct ptr*)NULL){
		printf("\nLista Vazia");
	}
	else{
		while(aux->prox!=inicio){
			cont++;
			m+=aux->valor;
			aux=aux->prox;
		}
		if(aux->prox==inicio)
			cont++;
			m+=aux->valor;
			m=m/cont;
			printf("\nA m%cdia dessa lista %c:\t%f",130,130,m);
		}
}
void maior_menor(){
	struct ptr* aux;
	aux=inicio;
	int maior,menor;
	if(aux==(struct ptr*)NULL){
		printf("\nLista Vazia");
	}
	else{
		if(maior==-1)
			maior=aux->valor;
		if(menor==-1)
			menor=aux->valor;
		while(aux->prox!=inicio){
			if(maior<aux->valor)
				maior=aux->valor;
			if(menor>aux->valor)
				menor=aux->valor;
			aux=aux->prox;
		}
		if(aux->prox==inicio){
			if(maior<aux->valor)
				maior=aux->valor;
			if(menor>aux->valor)
				menor=aux->valor;
			printf("\nO maior elemento dessa lista %c:\t%d",130,maior);
			printf("\nO menor elemento dessa lista %c:\t%d",130,menor);
		}
	}
}
void inserir_fim(){
	struct ptr* aux;
	int cont;
	aux=inicio;
	printf("\nEntre com o valor a ser inserido no fim:\t");
	scanf("%d",&cont);
	if(aux==(struct ptr*)NULL){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=cont;
		aux->prox=aux;
		aux->ant=aux;
	}
	else{
		while(aux->prox!=inicio){
			aux=aux->prox;
		}
		if(aux->prox==inicio){
			aux=inicio->ant;
			aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
			aux->prox->ant=aux;
			aux=aux->prox;
			aux->valor=cont;
			inicio->ant=aux;
			aux->prox=inicio;
			aux=(struct ptr*)NULL;
		}
	}
}
void remover(int cont){
	struct ptr*aux,*fim;
	aux=inicio;
	fim=inicio;
	if(cont<0){
		printf("\nEntre com um valor a ser removido:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
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
				if(inicio->valor==cont){
					printf("\nEI-1\n");
					fim=inicio->ant;
					inicio=inicio->prox;
					inicio->ant=fim;
					free(aux);
					fim->prox=inicio;
				}
				else{
					while((cont!=aux->valor)&&(aux->prox!=inicio)){
						aux->ant=aux;
					//	printf("\n\n\nEI\n\n\n");
						aux=aux->prox;
					}
	//				if(aux->valor!=cont)
	//					printf("O valor não existe.");
					if(aux->valor==cont){
						if(aux->prox==inicio){
							printf("\nEI-2\n");
							aux->ant->prox=inicio;
							free(aux);
						}
						else{
							printf("\nEI-3\n");
							aux->ant->prox=aux->prox;
							aux->prox->ant=aux->ant;
							free(aux);
						}
					}
				}
			}
			aux=(struct ptr *)NULL;
	//		aux->ant=aux;
		}
	}
}
void apagar(){
	struct ptr*aux,*ant;
	aux=inicio;
	ant=inicio;
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux->prox!=inicio){
			ant=aux;
			aux=aux->prox;
			printf("\nEI\n");
		}
			inicio=(struct ptr*)NULL;
			printf("\nEI-2\n");
			free(aux);
			aux=(struct ptr*)NULL;
			ant=aux;
	}
}
