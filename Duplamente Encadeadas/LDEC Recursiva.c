#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int cont,valor;
	struct ptr*prox,*ant;
};
struct ptr*inicio;
//void criar_lista();
struct ptr* criar_lista(struct ptr* aux,struct ptr* fim);
void mostra(struct ptr* aux);
void contador(struct ptr* aux,int cont);
void media(struct ptr*aux,int cont,float m);
void maior_menor(struct ptr* aux,int maior,int menor);
void inserir_fim(struct ptr* aux,int cont);
void apagar(struct ptr* aux,struct ptr*ant);
void remover(struct ptr*aux,struct ptr*fim,int cont);
main(){
	inicio=(struct ptr*)NULL;
	inicio=criar_lista(inicio,inicio);
//	criar_lista(inicio,inicio,inicio);
	mostra(inicio);
//	contador(inicio,0);
//	media(inicio,0,0);
//	maior_menor(inicio,-1,-1);
//	inserir_fim(inicio,-1);
//	mostra(inicio);
//	apagar(inicio,inicio);
//	mostra(inicio);
	remover(inicio,inicio,-1);
	mostra(inicio);
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
void mostra(struct ptr* aux){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio){
			printf("%d\t",aux->valor);
			mostra(aux->prox);
		}
		else{
			printf("%d\t",aux->valor);
		}
	}
}
void contador(struct ptr* aux,int cont){
	if(aux==(struct ptr*)NULL){
		printf("\nLista Vazia");
	}
	else{
		if(aux->prox!=inicio){
			cont++;
			contador(aux->prox,cont);
		}
		else{
			cont++;
			printf("\nEssa lista possui %d elementos",cont);
		}
	}
}
void media(struct ptr*aux,int cont,float m){
	if(aux==(struct ptr*)NULL){
		printf("\nLista Vazia");
	}
	else{
		if(aux->prox!=inicio){
			cont++;
			m+=aux->valor;
			media(aux->prox,cont,m);
		}
		else{
			cont++;
			m+=aux->valor;
			m=m/cont;
			printf("A m%cdia dessa lista %c:\t%f",130,130,m);
		}
	}
}
void maior_menor(struct ptr* aux,int maior,int menor){
	if(aux==(struct ptr*)NULL){
		printf("\nLista Vazia");
	}
	else{
		if(maior==-1)
			maior=aux->valor;
		if(menor==-1)
			menor=aux->valor;
		if(aux->prox!=inicio){
			if(maior<aux->valor)
				maior=aux->valor;
			if(menor>aux->valor)
				menor=aux->valor;
			maior_menor(aux->prox,maior,menor);
		}
		else{
			if(maior<aux->valor)
				maior=aux->valor;
			if(menor>aux->valor)
				menor=aux->valor;
			printf("\nO maior elemento dessa lista %c:\t%d",130,maior);
			printf("\nO menor elemento dessa lista %c:\t%d",130,menor);
		}
	}
}
void inserir_fim(struct ptr* aux,int cont){
	if(cont<0){
		printf("\nEntre com o valor a ser inserido no fim:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		if(aux==(struct ptr*)NULL){
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=cont;
			aux->prox=aux;
			aux->ant=aux;
		}
		else{
			if(aux->prox!=inicio){
				inserir_fim(aux->prox,cont);
			}
			else{
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
}
void remover(struct ptr *aux,struct ptr* fim,int cont){
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
	//				printf("\nEI-1\n");
					fim=inicio->ant;
					inicio=inicio->prox;
					inicio->ant=fim;
					free(aux);
					fim->prox=inicio;
				}
				else{
					if((cont!=aux->valor)&&(aux->prox!=inicio)){
						aux->ant=aux;
					//	printf("\n\n\nEI\n\n\n");
						remover(aux->prox,fim,cont);
					}
	//				if(aux->valor!=cont)
	//					printf("O valor não existe.");
					if(aux->valor==cont){
						if(aux->prox==inicio){
	//						printf("\nEI-2\n");
							aux->ant->prox=inicio;
							free(aux);
						}
						else{
	//						printf("\nEI-3\n");
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
void apagar(struct ptr* aux,struct ptr* ant){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio)
			apagar(aux->prox,aux);
		if(ant!=aux)
			ant->prox=inicio;
		else
			inicio=(struct ptr*)NULL;
		free(aux);
		aux=(struct ptr*)NULL;
		ant=aux;
	}
}
//void apagar(struct ptr*aux){
//	if(aux==(struct ptr*)NULL)
//		printf("\nLista Vazia");
//	else{
//		if(aux->prox!=inicio){
//			printf("\n\nEI-1");
//			inicio=inicio->prox;
//			aux->prox=(struct ptr*)NULL;
//			free(aux);
//			apagar(aux->prox);
//		}
//		else{
//			printf("\n\nEI-2");
//			inicio=inicio->prox;
//			aux->prox=(struct ptr*)NULL;
//			free(aux);
//			apagar(aux->prox);
//		}
//	}
//}
