//146) Geração de uma L.D.E.C.D onde os elementos serão inseridos na ordem inversa em que forem obtidos em recursão
#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int valor;
	struct ptr* prox,*ant;
};
struct desc{
	int cont;
	struct ptr* ini,*fim;
};
struct desc *inicio;
//struct ptr* inicio;
//struct ptr* criar_lista(struct ptr*aux,struct desc*inicio,struct ptr*fim);
void criar_lista(struct ptr* aux);
void mostra(struct ptr*aux);
void contador(struct ptr* aux,int cont);
void media(struct ptr* aux,int cont,float m);
void maior_menor(struct ptr* aux,int maior,int menor);
void inserir_fim(struct ptr*aux,int cont);
void remover(struct ptr*aux,struct ptr* fim,int cont);
void apagar(struct ptr* aux);
main(){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct ptr*)NULL;
	inicio->fim=(struct ptr*)NULL;
	inicio->cont=0;
	criar_lista(inicio->ini);
	mostra(inicio->ini);
//	contador(inicio->ini,0);
//	media(inicio->ini,0,0);
//	maior_menor(inicio->ini,-1,-1);
//	remover(inicio->ini,inicio->ini,-1);
//	mostra(inicio->ini);
//	inserir_fim(inicio->ini,-1);
//	mostra(inicio->ini);
	apagar(inicio->ini);
//	inicio->cont=0;
	mostra(inicio->ini);
}
void criar_lista(struct ptr*aux){
	int valor;
	printf("Entre com um valor:\t");
	scanf("%d",&valor);
	if(valor>=0){
		if(inicio->ini==(struct ptr*)NULL){
			inicio->ini=(struct ptr*)malloc(sizeof(struct ptr));
			inicio->ini->valor=valor;
			inicio->ini->ant=inicio->ini;
			inicio->ini->prox=inicio->ini;
			inicio->fim=inicio->ini;
		}
		else{
			aux=(struct ptr*)malloc(sizeof(struct ptr));
			aux->valor=valor;
			aux->ant=inicio->ini->ant;
			aux->ant->prox=aux;
			aux->prox=inicio->ini;
			inicio->ini->ant=aux;
			inicio->ini=aux;
		}
		aux=(struct ptr*)NULL;
		criar_lista(aux);
	}
}
void mostra(struct ptr*aux){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio->ini){
			printf("%d\t",aux->valor);
			inicio->cont++;
			mostra(aux->prox);
		}
		else{
			inicio->cont++;
			printf("%d\t",aux->valor);
			printf("\nEssa lista possui %d nos",inicio->cont);
		}
	}
}
void contador(struct ptr* aux,int cont){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio->ini){
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
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio->ini){
			cont++;
			m+=aux->valor;
			media(aux->prox,cont,m);
		}
		else{
			cont++;
			m+=aux->valor;
			m=m/cont;
			printf("\nA m%cdia dessa lista %c\t:\t%f",130,130,m);
		}
	}
}
void maior_menor(struct ptr* aux, int maior,int menor){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(maior==-1)
			maior=aux->valor;
		if(menor==-1)
			menor=maior;
		if(aux->prox!=inicio->ini){
			if(maior<aux->valor)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			maior_menor(aux->prox,maior,menor);
		}
		else{
			if(maior<aux->valor)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->valor;
			printf("\nO maior elemento dessa lista %c\t:\t%d",130,maior);
			printf("\nO menor elemento dessa lista %c\t:\t%d\n",130,menor);
		}
	}
}
void remover(struct ptr*aux,struct ptr*fim,int cont){
	if(cont<0){
		printf("\nEntre com o numero a ser removido:\t");
		scanf("%d",&cont);
	}
	if(cont>=0){
		if(inicio->ini==(struct ptr *)NULL)
		printf("Lista vazia.");
		else{
			if(inicio->ini->prox==inicio->ini){
				if(inicio->ini->valor!=cont)
					printf("Valor não consta.");
				else{
					free(inicio);
					inicio->ini=(struct ptr *)NULL;
				}
			}
			else{
				if(inicio->ini->valor==cont){
					printf("\nEI-1\n");
					fim=inicio->ini->ant;
					inicio->ini=inicio->ini->prox;
					inicio->ini->ant=fim;
					free(aux);
					fim->prox=inicio->ini;
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
						if(aux->prox==inicio->ini){
							printf("\nEI-2\n");
							aux->ant->prox=inicio->ini;
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
			if(aux->prox!=inicio->ini){
				inserir_fim(aux->prox,cont);
			}
			else{
				aux=inicio->ini->ant;
				aux->prox=(struct ptr*)malloc(sizeof(struct ptr));
				aux->prox->ant=aux;
				aux=aux->prox;
				aux->valor=cont;
				inicio->ini->ant=aux;
				aux->prox=inicio->ini;
				aux=(struct ptr*)NULL;
			}
		}
	}
}
void apagar(struct ptr* aux){
	if(aux==(struct ptr*)NULL)
		printf("\nLista Vazia");
	else{
		if(aux->prox!=inicio->ini){
			apagar(aux->prox);
		}
		else{
			inicio->ini=(struct ptr*)NULL;
			free(aux);
			aux=(struct ptr*)NULL;
		}
	}
}
