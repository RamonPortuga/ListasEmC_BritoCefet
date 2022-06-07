#include <stdio.h>
struct ptr{
	int valor;
	struct ptr*prox;
};
struct ptr*inicio;
void criar_lista(struct ptr*aux);
void mostra(struct ptr*aux);
void inserir_ordenado(struct ptr* aux);
main(){
	inicio=(struct ptr*)NULL;
	criar_lista(inicio);
	mostra(inicio);
	inserir_ordenado(inicio);
}
void criar_lista(struct ptr*aux){
	int valor;
	printf("Entre com o valor:\t");
	scanf("%d",&valor);
	if(inicio==(struct ptr*)NULL){
		inicio=(struct ptr*)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->prox=aux;
		inicio->ant=
	}
}
