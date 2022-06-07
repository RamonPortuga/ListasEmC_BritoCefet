//26) Geração de uma L.D.E. onde os elementos serão inseridos na ordem inversa em que forem obtidos em recursão
#include <stdio.h>
#include<stdlib.h>
struct ptr{
	int valor;
	struct ptr*prox;
	struct ptr* ant;
	int cont;
};
struct ptr* inicio;
void cria_lista_dupla_inv(struct ptr*aux);
void mostra(struct ptr*aux);
void contador(struct ptr* aux,int cont);
void media(struct ptr* aux,int cont,float m);
void maior_menor(struct ptr* aux,int maior,int menor);
void inserir_fim(struct ptr* aux,int cont);
void inserir_ordenada_dupla(struct ptr *aux,int cont);
void apaga_lista(struct ptr* aux);
void remover(struct ptr* aux,int cont);
main(){
	inicio=(struct ptr*)NULL;
	cria_lista_dupla_inv(inicio);
	mostra(inicio);
//	contador(inicio,0);
//	media(inicio,0,0);
//	maior_menor(inicio,-1,-1);
//	inserir_fim(inicio,-1);
//	mostra(inicio);
//	inserir_ordenada_dupla(inicio,-1);
//	mostra(inicio);
//	apaga_lista(inicio);
//	mostra(inicio);
	remover(inicio,-1);
	mostra(inicio);
}
void cria_lista_dupla_inv(struct ptr*aux){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->ant=(struct ptr *)NULL;
		aux->prox=inicio;
		if(inicio!=(struct ptr*)NULL)
			inicio->ant=aux;
		inicio=aux;
		aux=(struct ptr*) NULL;
		cria_lista_dupla_inv(aux);
	}
		aux=(struct ptr*)NULL;
}
void mostra(struct ptr*aux){
	if(aux!=(struct ptr*)NULL){
		printf("%d\t",aux->valor);
		mostra(aux->prox);
	}
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
}
void contador(struct ptr* aux,int cont){
	if(aux!=(struct ptr*)NULL){
		cont++;
		contador(aux->prox,cont);
	}
	if(aux==(struct ptr*)NULL)
		printf("\nEssa lista possui %d elementos",cont);
}
void media(struct ptr* aux,int cont,float m){
	if(aux!=(struct ptr*)NULL){
		cont++;
		m+=aux->valor;
		media(aux->prox,cont,m);
	}
	if(aux==(struct ptr*)NULL){
		m=m/cont;
		printf("\nA media dessa lista e:\t%f",m);
	}
}
void maior_menor(struct ptr* aux,int maior,int menor){
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(maior==-1)
			maior=aux->valor;
		if(menor==-1)
			menor=maior;
		if(aux!=(struct ptr*)NULL){
			if(aux->valor>maior){
				maior=aux->valor;
			}
			if(aux->valor<menor){
				menor=aux->valor;
			}
			maior_menor(aux->prox,maior,menor);
		}
	if(aux==(struct ptr*)NULL)
		printf("\nMaior\t=\t%d\tmenor\t=\t%d",maior,menor);
	}
}
void inserir_fim(struct ptr* aux,int cont){
	if(cont<0){
		printf("\nEntre com o valor a ser inserido no final da lista:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		if(inicio==(struct ptr*)NULL){
			inicio=(struct ptr*)malloc(sizeof (struct ptr));
			inicio->prox=(struct ptr*)NULL;
			inicio->valor=cont;
		}
		else{
			if(aux->prox!=(struct ptr*)NULL){	
				inserir_fim(aux->prox,cont);
			}
			else{
				aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux=aux->prox;
				aux->valor=cont;
				aux->prox=(struct ptr*)NULL;
			}
				aux=(struct ptr*)NULL;
		}
	}
}
void remover(struct ptr* aux,int cont){
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
				if((cont!=aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					aux->ant=aux;
					remover(aux->prox,cont);
				}
//				if(aux->valor!=cont)
//					printf("O valor não existe.");
				else{
					if(aux->prox==(struct ptr *)NULL){
						aux->ant->prox=(struct ptr *)NULL;
						free(aux);
					}
					else{
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
void apaga_lista(struct ptr *aux){
	if(aux!=(struct ptr*)NULL){
		inicio=inicio->prox;
		aux->prox=(struct ptr*)NULL;
		free(aux);
		apaga_lista(aux->prox);
	}
}
