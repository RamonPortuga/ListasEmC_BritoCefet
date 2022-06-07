#include <stdio.h>
#include <stdlib.h>
struct desc{
	int cont,valor;
	struct ptr *ini,*fim;
};
struct desc *inicio;
struct ptr{
	int cont,valor;
	struct ptr *prox,*ant;
};
void criar_lista(struct ptr* aux);
void mostra(struct ptr* aux);
void contador(struct ptr* aux, int cont);
void media(struct ptr* aux,int cont,float m);
void maior_menor(struct ptr* aux, int maior,int menor);
void inserir_fim(struct ptr* aux,int cont);
void apaga_lista(struct ptr* aux);
void remover(struct ptr* aux,int cont);
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
	criar_lista(inicio->ini);
	mostra(inicio->ini);
	inicio->cont=0;
//	contador(inicio->ini,0);
//	media(inicio->ini,0,0);
//	maior_menor(inicio->ini,-1,-1);
	inserir_fim(inicio->ini,-1);
	mostra(inicio->ini);
//	inicio->cont=0;
//	remover(inicio->ini,-1);
//	mostra(inicio->ini);
//	apaga_lista(inicio->ini);
//	mostra(inicio->ini);
//	inicio->cont=0;
}
void criar_lista(struct ptr* aux){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr*));
		aux->valor=valor;
		aux->ant=(struct ptr*)NULL;
		aux->prox=inicio->ini;
		if(inicio->ini!=(struct ptr*)NULL)
			inicio->ini->ant=aux;
		inicio->ini=aux;
		aux=(struct ptr*) NULL;
		criar_lista(aux);
	}
}
void mostra(struct ptr* aux){
	if(aux==(struct ptr*)NULL)
		printf("\nEssa lista possui %d nos",inicio->cont);
	if(inicio->ini==(struct ptr*)NULL){
		printf("\nLista Vazia");
	}
	if(aux!=(struct ptr*)NULL){
		inicio->cont++;
		printf("%d\t",aux->valor);
		mostra(aux->prox);
	}
}
void contador(struct ptr* aux, int cont){
	if(aux!=(struct ptr*)NULL){
		cont++;
		contador(aux->prox,cont);
	}
	else{
		if(cont==0)
			printf("\nLista vazia");
		else{
			printf("\nA lista possui %d elementos",cont);
		}
	}
}
void media(struct ptr* aux,int cont,float m){
	if(aux!=(struct ptr*)NULL){
		cont++;
		m+=aux->valor;
		media(aux->prox,cont,m);
	}
	else{
		m=m/cont;
		printf("\nMedia\t=\t%f",m);
	}
}
void maior_menor(struct ptr* aux, int maior,int menor){
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(maior==-1)
			maior=aux->valor;
		if(menor==-1)
			menor=maior;
		if(aux!=(struct ptr*)NULL){
			if(aux->valor>maior)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			maior_menor(aux->prox,maior,menor);
		}
	}
	if(aux==(struct ptr*)NULL)
		printf("\nMaior:\t%d\nMenor:\t%d",maior,menor);
}
void inserir_fim(struct ptr* aux,int cont){
	if(cont<0){
		printf("\nEntre com o valor a ser inserido no final:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini=cont;
			inicio->ini->prox=(struct ptr*)NULL;
		}
		else{
			if(aux->prox!=(struct ptr*)NULL)
				inserir_fim(aux->prox,cont);
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
	if(inicio->ini==(struct ptr *)NULL)
		printf("Lista vazia.");
	else{
		if(inicio->ini->prox==(struct ptr *)NULL){
			if(inicio->ini->valor!=cont)
				printf("Valor não consta.");
			else{
				free(inicio);
				inicio->ini=(struct ptr *)NULL;
			}
		}
		else{
			if(inicio->ini->valor==cont){
				inicio->ini=inicio->ini->prox;
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
void apaga_lista(struct ptr* aux){
	if(aux!=(struct ptr*)NULL){
		inicio->ini=inicio->ini->prox;
		printf("\nEI");
	//	inicio->ini->ant=(struct ptr*)NULL;
		printf("\nEI2");
		free(aux);
		apaga_lista(inicio->ini);
		inicio->fim=(struct ptr*)NULL;
	}
}
