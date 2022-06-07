#include <stdio.h>
struct ptr{
	int valor;
	struct ptr*prox;
};
struct ptr*inicio;
void cria_lista_inv(),mostra(),inserir_fim();
main(){
	cria_lista_inv();
	mostra();
	inserir_fim();
	mostra();
}
void cria_lista_inv( ){
	int  valor;
	struct ptr *aux;
	inicio = (struct ptr *)NULL;
	printf("Entre com um valor: ");
	scanf("%d", &valor);
	while(valor >= 0){
		aux = (struct ptr *)malloc(sizeof(struct ptr));
		aux -> valor = valor;
		aux -> prox = inicio;
		inicio = aux;
		printf("Entre com um valor: ");
		scanf("%d", &valor);
	}
	aux = (struct ptr *)NULL;
}
void inserir_fim( ){
	int valor;
	struct ptr *aux;
	if(inicio == (struct ptr *)NULL){
		inicio = (struct ptr*)malloc(sizeof(struct ptr));
		printf("\nEntre com um número: ");
		scanf("%d", &valor);
		inicio -> valor = valor;
		inicio -> prox = (struct ptr *)NULL;
	}
	else{
		aux = inicio;
		while(aux -> prox != (struct ptr *)NULL)
			aux = aux -> prox;
		aux -> prox = (struct ptr *)malloc(sizeof(struct ptr));
		aux = aux -> prox;
		aux -> prox = (struct ptr *)NULL;
		printf("Entre com um número: ");
		scanf("%d", &valor);
		aux -> valor = valor;
		aux = (struct ptr *)NULL;
	}
}
void mostra( ){
	struct ptr *aux;
	if(inicio == (struct ptr *)NULL)
		printf("Lista Vazia!");
	else{
		aux = inicio;
		while(aux != (struct ptr *)NULL){
			printf("%d\t", aux -> valor);
			aux = aux -> prox;
		}
	}
}
