#include <stdio.h>
#include <stdlib.h>
struct ptr{
	int valor,cont;
	struct ptr*prox;
	struct ptr*ant;
};
struct ptr* inicio;
void criar_lista_ordenada();
void mostra(struct ptr* aux);
main(){
	inicio=(struct ptr *)NULL;
	criar_lista_ordenada();
	mostra(inicio);
}
void criar_lista_ordenada(){
//	aux=inicio;
	int valor;
	void inserir_ordenado2(struct ptr *aux, struct ptr *ant, int valor){
		if(inicio==(struct ptr *)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=aux;
			inicio->ant=(struct ptr*)NULL;
		}
		else{
			if(inicio->valor>valor){
				inicio=(struct ptr *)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=valor;
				inicio->ant=(struct ptr*)NULL;
				aux->ant=inicio;
				inicio->prox->ant=inicio;	
			}
			else{
				if((valor>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					inserir_ordenado2(aux->prox,ant,valor);
				}
				else{
					if(valor<aux->valor){
						ant->prox=(struct ptr *)malloc(sizeof(struct ptr));
						ant=ant->prox;
						ant->valor=valor;
						ant->prox=aux;
					}
					else{
						aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
						aux=aux->prox;
						aux->valor=valor;
						aux->prox=(struct ptr*)NULL;
					}
				}
			}
		}
		aux=(struct ptr *)NULL;
		ant=(struct ptr *)NULL;
		}
		printf("Entre com o valor a ser inserido: ");
		scanf("%d", &valor);
		if(valor>=0){
			inserir_ordenado2(inicio, inicio, valor);
			printf("\n");
			mostra(inicio);
			printf("\n\n");
			criar_lista_ordenada();//ISSO foi adicionado
		}
}
void mostra(struct ptr*aux){
	if(aux!=(struct ptr*)NULL){
		printf("%d\t",aux->valor);
		mostra(aux->prox);
	}
	if(inicio==(struct ptr*)NULL)
		printf("\nLista Vazia");
}
