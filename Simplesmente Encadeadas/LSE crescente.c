#include <stdio.h>
#include<stdlib.h>
int valor;
struct ptr{
	int valor;
	struct ptr*prox;
};
struct ptr* inicio;
void inserir_ordenado2(struct ptr*aux, struct ptr*ant, int valor);
main(){
	printf("Entre com o valor a ser inserido: ");
	scanf("%d", &valor);
	inserir_ordenado2(inicio, inicio, valor);
	criar_lista_ordenada();
}
void criar_lista_ordenada(){
	void inserir_ordenado2(struct ptr*aux, struct ptr*ant, int valor);
//	inicio=(struct ptr*)NULL;
	if(valor<=0){//AQUI originalmente tem um While (Um tanto óbvio mas fds);
		inserir_ordenado2(valor);
		printf("Entre com o valor a ser inserido: ");
		scanf("%d", &valor);
		criar_lista_ordenada(inicio,valor);//ISSO foi adicionado
	}
	void inserir_ordenado2(int valor){
		struct ptr *aux, *ant;
		if(inicio==(struct ptr *)NULL){
			inicio=(struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor=valor;
			inicio->prox=(struct ptr*)NULL;
		}
		else{
			if(inicio->valor>valor){
				inicio=(struct ptr *)malloc(sizeof(struct ptr));
				inicio->prox=aux;
				inicio->valor=valor;
			//	aux=(struct ptr*)NULL;		//PQ?
			}
		//	else{
				if((valor>aux->valor)&&(aux->prox!=(struct ptr *)NULL)){
					ant=aux;
					inserir_ordenado2(aux->prox,ant,valor);
				}
				if(valor>aux->valor){
					aux->prox=(struct ptr *)malloc(sizeof(struct ptr));
					aux=aux->prox;
					aux->valor=valor;
					aux->prox=(struct ptr*)NULL;
				//	ant=(struct ptr *)NULL;
				//	aux=ant;
				}
				else{
				//	aux=(struct ptr *)malloc(sizeof(struct ptr));
				//	aux->valor=valor;
				//	aux->prox=ant->prox;
				//	ant->prox=aux;
				//	ant=(struct ptr *)NULL;
					
					aux=ant;
					ant->prox=(struct ptr *)malloc(sizeof(struct ptr));
					ant=ant->prox;
					ant->valor=valor;
					ant->prox=aux;
				}
		//	}
		}
		ant=(struct ptr *)NULL;
		aux=ant;
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
