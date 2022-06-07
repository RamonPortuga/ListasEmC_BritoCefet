//145) Geração de uma L.S.E.C.D onde os elementos serão inseridos na ordem inversa em que forem obtidos
#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int valor;
	struct ptr* prox;
};
struct desc{
	int cont;
	struct ptr* ini,*fim;
};
struct desc *inicio;
//struct ptr* inicio;
//struct ptr* criar_lista(struct ptr*aux,struct desc*inicio,struct ptr*fim);
void criar_lista();
void mostra();
void contador();
void media();
void maior_menor();
void apagar();
void remover(int cont);
void inserir_fim(int cont);
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
	criar_lista();
	mostra();
//	contador();
//	media();
//	maior_menor();
//	remover(-1);
//	mostra();
	inserir_fim(-1);
	mostra();
//	apagar();
//	inicio->cont=0;
//	mostra();
}
void criar_lista(){
	struct ptr* aux;
	int valor;
	aux=inicio->ini;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	while(valor>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->prox=inicio->ini;
			inicio->fim=inicio->ini;
		}
		else{
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=valor;
			aux->prox=inicio->ini;
			inicio->ini=aux;
			inicio->fim->prox=inicio->ini;
		}
		printf("Entre com um valor:\t");
		scanf("%d",&valor);
	}
	aux=(struct ptr*)NULL;
}
void mostra(){
	struct ptr*aux;
	aux=inicio->ini;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux->prox!=inicio->ini){
			printf("%d\t",aux->valor);
			inicio->cont++;
			aux=aux->prox;
		}
		if(aux->prox==inicio->ini){
			inicio->cont++;
			printf("%d\t",aux->valor);
			printf("\nEssa lista possui %d nos",inicio->cont);
		}
	}
}
void contador(){
	struct ptr* aux;
	int cont;
	aux=inicio->ini;
	cont=0;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux->prox!=inicio->ini){
			cont++;
			aux=aux->prox;
		}
		if(aux->prox==inicio->ini){
			cont++;
			printf("\nEssa lista possui %d elementos",cont);
		}
	}
}
void media(){
	struct ptr* aux;
	int cont;
	float m;
	cont=0;
	m=0;
	aux=inicio->ini;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux->prox!=inicio->ini){
			cont++;
			m+=aux->valor;
			aux=aux->prox;
		}
		if(aux->prox==inicio->ini){
			cont++;
			m+=aux->valor;
			m=m/cont;
			printf("\nA m%cdia dessa lista %c\t:\t%f",130,130,m);
		}
	}
}
void maior_menor(){
	struct ptr* aux;
	int maior,menor;
	aux=inicio->ini;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(maior==-1)
			maior=aux->valor;
		if(menor==-1)
			menor=maior;
		while(aux->prox!=inicio->ini){
			if(maior<aux->valor)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			aux=aux->prox;
		}
		if(aux->prox==inicio->ini){
			if(maior<aux->valor)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			printf("\nO maior elemento dessa lista %c\t:\t%d",130,maior);
			printf("\nO menor elemento dessa lista %c\t:\t%d\n",130,menor);
		}
	}
}
void remover(int cont){
	struct ptr*aux,*ant;
	aux=inicio->ini;
	ant=inicio->ini;
	if(cont<0){
		printf("\nEntre com o valor a ser removido:\t");
		scanf("%d", &cont);
	}
	if(inicio->ini==(struct ptr *)NULL)
		printf("Lista vazia.");
	else{
		if(inicio->ini->prox==inicio->ini){
			if(inicio->ini->valor!=cont)
				printf("Valor não consta.");
			else{
				free(inicio);
				inicio=(struct ptr *)NULL;
			}
		}
		else{
			while(aux->prox!=inicio->ini){
				if((ant==inicio->ini) && (aux->prox->valor==cont)){
					ant=aux;
				}
				aux=aux->prox;
			}
			if(aux->prox==inicio->ini){
				if(inicio->ini->valor==cont || ant->prox->valor==cont){
					if(inicio->ini->valor==cont){
						inicio->ini=inicio->ini->prox;
						aux->prox=inicio->ini;
						free(ant);
					}
					else{
						if(ant->prox->prox==inicio->ini){
							ant->prox=inicio->ini;
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
	struct ptr*aux;
	aux=inicio->ini;
	if(cont<0){
		printf("\nEntre com o valor a ser inserido no fim:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		if(aux==(struct ptr*)NULL){
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=cont;
			aux=aux->prox;
		}
		else{
			while(aux->prox!=inicio->ini){
				aux=aux->prox;
			}
			if(aux->prox==inicio->ini){
				aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux=aux->prox;
				aux->valor=cont;
				aux->prox=inicio->ini;
				aux=(struct ptr*)NULL;
			}
		}
	}
}
void apagar(){
	struct ptr* aux;
	aux=inicio->ini;
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux->prox!=inicio->ini){
			aux=aux->prox;
		}
		if(aux->prox==inicio->ini){
			inicio->ini=(struct ptr*)NULL;
			free(aux);
			aux=(struct ptr*)NULL;
		}
	}
}
