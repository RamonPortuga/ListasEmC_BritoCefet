#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int valor,cont;
	struct ptr *prox;
};
struct desc{
	int cont;
	struct ptr *ini, *fim;
};
struct desc *inicio;

void criar_lista(struct ptr* aux);
void mostra(struct ptr* aux);
void media(struct ptr* aux,int cont, float m);
void contador(struct ptr* aux,int cont);
void maior_menor(struct ptr* aux,int maior,int menor);
void inserir_fim(struct ptr*, int cont);
void apaga(struct ptr* aux);
void inserir_ordenado(struct ptr* aux,struct ptr* ant,int cont);
void remover(struct ptr* aux,struct ptr* ant,int cont);
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
//	inserir_fim(inicio->ini,-1);
//	mostra(inicio->ini);
//	inserir(inicio,inicio,-1);
//	mostra(inicio->ini);
	inserir_ordenado(inicio->ini,inicio->ini,-1);
//	apaga(inicio->ini);
//	remover(inicio->ini,inicio->ini,-1);
	mostra(inicio->ini);
}
void criar_lista(struct ptr*aux){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox = inicio->ini;
		inicio->ini=aux;
		inicio->cont++;
		if(inicio->fim == (struct ptr*)NULL)
			inicio->fim=aux;
		aux=(struct ptr*)NULL;
		criar_lista(aux);
	}
}
void mostra(struct ptr*aux){
	if(aux==(struct ptr*)NULL)
		printf("\nQuantidade de nos: %d.\n", inicio->cont);
	if(aux!=(struct ptr*)NULL){
		printf("%d\t",aux->valor);
		mostra(aux->prox);
	}
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
}
void contador(struct ptr* aux,int cont){
	//if(aux==(struct ptr*)NULL)
	if(aux==(struct ptr*)NULL)
		printf("A quantidade de elementos nessa lista e de:\t%d",cont);
	if(inicio->ini==(struct ptr*)NULL)
		printf("\nLista Vazia");
	if(aux!=(struct ptr*)NULL){
		cont++;
		contador(aux->prox,cont);
	}
}
void media(struct ptr* aux,int cont,float m){
	if(aux!=(struct ptr*)NULL){
		m+=aux->valor;
		cont++;
		media(aux->prox,cont,m);
	}
	if(aux==(struct ptr*)NULL){
		if(cont==0)
			printf("\nMedia\t=\t0");
		if(cont!=0){
			printf("\nMedia\t=%2f",m/cont);
		}
	}
}
void maior_menor(struct ptr* aux,int maior,int menor){
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
			if(menor>aux->valor)
				menor=aux->valor;
		maior_menor(aux->prox,maior,menor);
		}
	}
	if(aux==(struct ptr*)NULL){
		printf("\nO maior elemento e:\t%d",maior);
		printf("\nO menor elemento e:\t%d",menor);
	}
}
void inserir_fim(struct ptr* aux,int cont){
	if(cont<0){
		printf("\nEntre com o valor:\t");
		scanf("%d",&cont);
	}
	if(inicio->ini==(struct ptr*)NULL){
		inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
		inicio->ini->prox=(struct ptr*)NULL;
		inicio->ini->cont=cont;
	}
	else{
		if(aux->prox!=(struct ptr*)NULL){
			inserir_fim(aux->prox,cont);
		}
		else{
			aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
			aux=aux->prox;
			aux->prox=(struct ptr*)NULL;
			aux->valor=cont;
			aux=(struct ptr*)NULL;
		}
	}
}
void inserir_ordenado(struct ptr* aux,struct ptr* ant,int cont){
	if(cont<0){
		printf("\nEntre com um valor a ser inserido:\t");
		scanf("%d",&cont);
	}
	if(cont>0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=cont;
			inicio->ini->prox=(struct ptr*)NULL;
		}
		else{
			if(cont>inicio->ini->valor){
				printf("%d",inicio->ini->valor);
				inicio->ini=(struct ptr *)malloc(sizeof(struct ptr));
				inicio->ini->prox=aux;
				inicio->ini->valor=cont;	
				printf("\n\nInicio\n\n");
			}
			else{
				if((cont>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					inserir_ordenado(aux->prox,ant,cont);
				}
				else{
					if(aux->valor>cont){
						ant->prox=(struct ptr*)malloc(sizeof(struct ptr));
						ant=ant->prox;
						ant->valor=cont;
						ant->prox=aux;
						printf("\n\nMEIO\n\n");
					}
					else{
						printf("\n\nFIM\n\n");	
						aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->valor=cont;
						aux->prox=(struct ptr*)NULL;
					}
				}
			}
		}
	}
}
void remover(struct ptr* aux,struct ptr* ant,int cont){
	if(cont<0){
		printf("Entre com um valor:\t");
		scanf("%d",&cont);
	}
	if(cont>0){
		if(inicio->ini==(struct ptr *)NULL)
		printf("Lista vazia.");
	else{
		if(inicio->ini->prox==(struct ptr *)NULL){
//			if(inicio->ini->valor!=cont)
//				printf("Valor não consta.");  CONSERTAR
//			else{
			if(inicio->ini->valor==cont){
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
					ant=aux;
					remover(aux->prox,ant,cont);
				}
				if(aux->valor!=cont)
					printf("O valor não existe.");
				else{
					if(aux->prox==(struct ptr *)NULL){
						ant->prox=(struct ptr *)NULL;
						free(aux);
					}
					else{
						ant->prox=aux->prox;
						aux->prox=(struct ptr *)NULL;
						free(aux);
					}
				}
			}
		}
		aux=(struct ptr *)NULL;
		ant=aux;
	}
	}
}
void apaga(struct ptr* aux){
	if(inicio->ini!=(struct ptr*)NULL){
		inicio->ini=inicio->ini->prox;
		free(aux);
		inicio->fim=(struct ptr*)NULL;
		apaga(inicio->ini);
	}
}
