#include <stdio.h>
int valor;
void inserir_ordenado2(int valor);
struct ptr{
	int valor;
	struct ptr*prox;
};
struct ptr*inicio;
main(){
	criar_lista_ordenada();
}
void criar_lista_ordenada(){
	void inserir_ordenado2(int valor);
	int valor;
	printf("Entre com o valor a ser inserido: ");
	scanf("%d", &valor);
	inicio=(struct ptr*)NULL;
	while(valor<=0){
		inserir_ordenado2(valor);
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
