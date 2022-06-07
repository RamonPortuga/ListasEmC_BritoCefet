#include <stdio.h>
#include<stdlib.h>
int valor;
struct ptr{
	int cont,valor;
	struct ptr*prox;
};
struct ptr* inicio;
struct ptr* inverso(struct ptr* aux, struct ptr* inicio);
void cria_lista(struct ptr*aux);
void mostra(struct ptr*aux), contador(struct ptr*aux,int cont), inserir_fim(struct ptr *aux,int cont);
void media(struct ptr* aux, int cont,float m), maior_menor(struct ptr*aux,int maior,int menor);
void inserir_ordenado(struct ptr *aux, struct ptr *ant, int cont), remover(struct ptr* aux, struct ptr* ant,int cont);
void apagar (struct ptr* aux);
main(){
	inicio = (struct ptr*)NULL;
//	inicio = inverso(inicio, inicio);
	cria_lista(inicio);
	mostra(inicio);
//	contador(inicio,0);
//	media(inicio,1,0);
//	maior_menor(inicio,-1,-1);
	inserir_fim(inicio,-1);
	mostra(inicio);
//	inserir_ordenado(inicio,inicio,-1);
//	mostra(inicio);
//	remover(inicio,inicio,-1);
//	mostra(inicio);
//	apagar(inicio);
//	mostra(inicio);
}
void cria_lista(struct ptr* aux){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox=inicio;
//		printf("%d\n",aux->prox);
		inicio=aux;
//		printf("%d\t",inicio);
//		printf("%d\n",aux);
		aux=(struct ptr*)NULL;
		cria_lista(aux);
	}
}
/*struct ptr * inverso(struct ptr* aux, struct ptr* inicio){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		aux=(struct ptr*)NULL;
		inicio = inverso(aux,inicio);
	}
	return inicio;		
}*/
void mostra(struct ptr*aux){
	if(aux!=(struct ptr*)NULL){
		printf("%d\t",aux->valor);
		mostra(aux->prox);
	}
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
}
void contador(struct ptr*aux,int cont){
	if(aux!=(struct ptr*)NULL){
		cont++;
		contador(aux->prox,cont);
	}
	if(aux==(struct ptr*)NULL)
			printf("\nA lista possui %d elementos",cont);
}
void media(struct ptr* aux, int cont,float m){
	if(aux!=(struct ptr*)NULL){
		m+=aux->valor;
		cont++;
		media(aux->prox,cont,m);
	}
	if(aux==(struct ptr*)NULL){
		if((cont-1)==0)
			printf("\nMedia\t=\t0");
		if((cont-1)!=0){
			printf("\nMedia\t=%2f",m/(cont-1));
		}
	}
}
void maior_menor(struct ptr*aux,int maior,int menor){
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
void inserir_fim(struct ptr *aux,int cont){
	if(cont<0){
		printf("\nEntre com o valor a ser adicionado ao fim da lista: ");
		scanf("%d", &cont);
	}
	if(inicio==(struct ptr*)NULL){
		inicio=(struct ptr *)malloc(sizeof(struct ptr));
		inicio->prox=(struct ptr *)NULL;
		inicio->cont=cont;
	}
	else{
		if(aux->prox!=(struct ptr *)NULL){
			inserir_fim(aux->prox,cont);
		}
		else{
			aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
			aux=aux->prox;
			aux->prox=(struct ptr *)NULL;
			aux->cont=cont;
			aux=(struct ptr *)NULL;
		}
	}
}
void inserir_ordenado(struct ptr *aux, struct ptr *ant, int cont){
	if(cont<0){
		printf("\n\nEntre com um valor para ser inserido:\t");
		scanf("%d", &cont);
	}
	if(cont>0){
		if(inicio==(struct ptr *)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->cont=cont;
			inicio->prox=(struct ptr*)NULL;
		}
		else{
			if(inicio->valor>valor){
				printf("\n\nEI\n\n");
				inicio=(struct ptr *)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=valor;
				printf("\n%d",inicio->valor);	
			}
			else{
				if((valor>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					inserir_ordenado(aux->prox,ant,cont);
				}
				else{
					if(valor<aux->valor){
						ant->prox=(struct ptr *)malloc(sizeof(struct ptr));
						ant=ant->prox;
						ant->cont=cont;
						ant->prox=aux;
						printf("\n\nFIM\n\n");
					}
					else{
						aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
					//	aux=aux->prox;
						aux->cont=cont;
						aux->prox=(struct ptr*)NULL;	
						printf("\n\nMEIO\n\n");		
					}
				}
			}
		}
	aux=(struct ptr *)NULL;
	ant=(struct ptr *)NULL;
	}
}
void remover(struct ptr* aux,struct ptr* ant,int cont){
	if(cont<0){
		printf("Entre com o valor a ser removido:\t");
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
					ant=aux;
					remover(aux->prox,ant,cont);
				}
//				if(aux->valor!=cont)
//					printf("O valor não existe.");
				else{
					printf("Meio");
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
void apagar(struct ptr* aux){
	if(inicio!=(struct ptr*)NULL){
		inicio=inicio->prox;
		aux->prox=(struct ptr*)NULL;
		free(aux);
		apagar(inicio);
	}
}
/*void inverso(){
	struct ptr*aux;
	int valor;
	inicio=(struct ptr*)NULL;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	while(valor>=0){
		aux=(struct ptr*)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		printf("Entre com o valor:\t");
		scanf("%d",&valor);
	}
	aux=(struct ptr*)NULL;
}
void mostra(){
	struct ptr*aux;
	aux=inicio;
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		while(aux!=(struct ptr*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}
	}
}
void contador(){
	struct ptr*aux;
	int cont;
	cont=0;
	aux=inicio;
	while(aux!=(struct ptr*)NULL){
		cont++;
		aux=aux->prox;
	}
	printf("\nA lista possui %d elementos",cont);
}
void media(){
	struct ptr* aux;
	float m;
	int cont;
	cont=0;
	aux=inicio;
	while(aux!=(struct ptr*)NULL){
		m+=aux->valor;
		cont++;
		aux=aux->prox;
	}
	if(cont==0)
		printf("\nMedia\t=\t0");
	else{
		printf("\nMedia\t=%2f",m/cont);
	}
}
void maior_menor(){
	struct ptr*aux;
	int maior, menor;
	aux=inicio;
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		maior=aux->valor;
		menor=maior;
		while(aux!=(struct ptr*)NULL){
			if(aux->valor>maior)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			aux=aux->prox;
		}
	printf("\nMaior\t=\t%d\tmenor\t=\t%d",maior,menor);
	}
}
void inserir_fim(){
	struct ptr *aux;
	int valor;
	printf("Entre com o valor a ser adicionado ao fim da lista: ");
	scanf("%d", &valor);
	aux=inicio;
	if(inicio==(struct ptr*)NULL){
		inicio=(struct ptr *)malloc(sizeof(struct ptr));
		inicio->prox=(struct ptr *)NULL;
		inicio->valor=valor;
	}
	else{
		while(aux->prox!=(struct ptr *)NULL)
			aux=aux->prox;
		aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
		aux=aux->prox;
		aux->prox=(struct ptr *)NULL;
		aux->valor=valor;
		aux=(struct ptr *)NULL;
	}
}
void inserir_ordenado(){
	struct ptr *aux, *ant;
	int valor;
	printf("Entre com um valor: ");
	scanf("%d", &valor);
	if(inicio==(struct ptr *)NULL){
		inicio=(struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->prox=(struct ptr*)NULL;
	}
	else{
		aux=inicio;
		if(inicio->valor>valor){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->prox=aux;
			inicio->valor=valor;
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
void remover(){
	struct ptr *aux, *ant;
	int valor;
	printf("Entre com o valor a ser removido: ");
	scanf("%d", &valor);
	if(inicio==(struct ptr *)NULL)
		printf("Lista vazia.");
	else{
		if(inicio->prox==(struct ptr *)NULL){
			if(inicio->valr!=valor)
				printf("Valor não consta.");
			else{
				free(inicio);
				inicio=(struct ptr *)NULL;
			}
		}
		else{
			if(inicio->valor==valor){
				aux=inicio;
				inicio=inicio->prox;
				aux->prox=(struct ptr *)NULL;
				free(aux);
				aux=(struct ptr *)NULL;
			}
			else{
				aux=inicio;
				while((valor!=aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					aux=aux->prox;
				}
				if(aux->valor!=valor)
					printf("O valor não existe.");
				else{
					if(aux->prox==(struct ptr *)NULL){
						ant->prox=(struct ptr *)NULL;
						free(aux);
						aux=(struct ptr *)NULL;
						ant=aux;
					}
					else{
						ant->prox=aux->prox;
						aux->prox=(struct ptr *)NULL;
						free(aux);
						aux=(struct ptr *)NULL;
						ant=aux;
					}
				}
			}
		}
	}
}
*/
