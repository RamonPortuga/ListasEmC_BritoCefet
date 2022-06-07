//23) Criar duas L.S.E. em qualquer ordem e em seguida juntar as duas em uma só L.S.E. em ordem crescente	
#include <stdio.h>
#include<stdlib.h>
void criar_lista_ordenada;
void criar_lista_ordenada2;
int valor;
struct ptr{
	int valor;
	struct ptr*prox;
};
struct ptr* inicio;
struct ptr* inverso(struct ptr* aux, struct ptr* inicio);
void criar_lista_ordenada(),criar_lista_ordenada2();
//void mostra(struct ptr*aux), contador(struct ptr*aux,int cont), inserir_fim(struct ptr *aux,int valor);
//void media(struct ptr* aux, int cont,float m), maior_menor(struct ptr*aux,int maior,int menor);
//void inserir_ordenado(struct ptr *aux, struct ptr *ant, int valor), remover(struct ptr* aux, struct ptr* ant,int valor,int cont);
main(){
	inicio = (struct ptr*)NULL;
	criar_lista_ordenada();
	mostra();
	criar_lista_ordenada2();
	mostra();
}
void criar_lista_ordenada(){
	void inserir_ordenado2(int valor);
	int valor;
	printf("Entre com o valor a ser inserido: ");
	scanf("%d", &valor);
	inicio=(struct ptr*)NULL;
	while(valor<=0){
		inserir_ordenado2(int valor);
		printf("Entre com o valor a ser inserido: ");
		scanf("%d", &valor);
	}
	void inserir_ordenado2(int valor){
		struct ptr *aux, *ant;
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
					ant=(struct ptr *)NULL;
					aux=ant;
				}
				else{
					aux=(struct ptr *)malloc(sizeof(struct ptr));
					aux->valor=valor;
					aux->prox=ant->prox;
					ant->prox=aux;
					ant=(struct ptr *)NULL;
					aux=ant;
				}
			}
		}
	}
}
void criar_lista_ordenada2(){
	void inserir_ordenado4(int valor);
	int valor;
	printf("Entre com o valor a ser inserido: ");
	scanf("%d", &valor);
	inicio=(struct ptr*)NULL;
	while(valor<=0){
		inserir_ordenado4(int valor);
		printf("Entre com o valor a ser inserido: ");
		scanf("%d", &valor);
	}
	void inserir_ordenado4(int valor){
		struct ptr *aux, *ant;
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
					ant=(struct ptr *)NULL;
					aux=ant;
				}
				else{
					aux=(struct ptr *)malloc(sizeof(struct ptr));
					aux->valor=valor;
					aux->prox=ant->prox;
					ant->prox=aux;
					ant=(struct ptr *)NULL;
					aux=ant;
				}
			}
		}
	}
}
